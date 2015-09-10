#include <fstream>
#include <map>
#include <iostream>
#include <regex>

int main()
{
	std::regex reg_syscalls("^#define\\s+__NR_(\\w+)\\s+(\\d+)");
	std::regex reg_proto("^\\s*extern\\s+([\\w\\s_]+[ \\*])([\\w]+)\\s[(]([\\w\\s\\(\\)\\[\\]_*,.]+)[)]");
	// std::regex reg_args("^[\\w\\s_#]*asmlinkage long sys_(\\w+)[(]([\\w\\s_*,]+)[)]");
	std::ifstream sycalls_file("/usr/include/x86_64-linux-gnu/asm/unistd_64.h");
	std::map<int, std::string> syscalls;
	int i = 0;
	while (sycalls_file.good())
	{
		std::string line;
		std::getline(sycalls_file, line);
		std::smatch m;
		if (regex_search(line, m, reg_syscalls))
		{
			// std::cout << m[0] << " -> " << m[1]man << " et " << m[2] << std::endl;
			int num = std::stoi(m[2]);
			syscalls[num] = m[1];
			i++;
		}
		// std::cout << line << std::endl;
	}
	std::vector<int> retValue(i, 0);
	std::vector<int> args(i, -1);
	sycalls_file.close();
	std::ifstream headers("header_list");
	while (headers.good())
	{

		std::string line;
		std::getline(headers, line);
		std::ifstream header(line);
		std::string currentLine;
		bool ignore = false;
		while (header.good())
		{
			std::getline(header, line);
			if(line[0] == '#')
				continue;
			if (ignore == false && line.find("/*") != std::string::npos)
				ignore = true;
			if (ignore == true)
			{
				if (line.find("*/") != std::string::npos)
					ignore = false;
				continue;
			}
			if (line.find("extern") == 0)
				currentLine = line;
			else
				currentLine = currentLine + line;
			// std::cout << currentLine.find(';') << std::endl;
			if (currentLine.find(';') == std::string::npos)
				continue;
				std::cout << currentLine << std::endl;
			// std::cout << currentLine << std::endl;
			std::smatch m;
			if (regex_search(currentLine, m, reg_proto))
			{
				// std::cout << currentLine << std::endl;
				std::string tmp_m2 = m[2];
				// std::cout << tmp_m2 << std::endl;
				for (auto elem:syscalls)
				{
					int num = elem.first;
					std::string syscall = elem.second;
					if (tmp_m2 == syscall)
					{
						std::string tmp_m3 = m[3];
						std::string tmp_m1 = m[1];
						if (tmp_m3 == "void")
							args[num] = 0;
						else
							args[num] = std::count(tmp_m3.begin(), tmp_m3.end(), ',') + 1;
						if (tmp_m1 == "char *")
							retValue[num] = 2;
						else if (tmp_m1.find('*') != std::string::npos)
							retValue[num] = 1;
						else
							retValue[num] = 3;
						// std::cout << "syscall : " << syscall << " -> " << m[0] << std::endl;
						break;
					}
				}
			}
			currentLine.clear();
		}
		header.close();
	}


	// std::ifstream args_file("/usr/src/linux-headers-3.16.0-44/include/linux/syscalls.h");
	// while (args_file.good())
	// {
	// 	std::string line;
	// 	std::getline(args_file, line, ';');
	// 	std::smatch m;
	// 	// std::cout << "__" << line << "__" << std::endl;
	// 	if (regex_search(line, m, reg_args))
	// 	{
	// 		// std::cout << m[0] << " -> " << m[1] << " et " << m[2] << std::endl;
	// 		std::string tmp_m1 = m[1];
	// 		std::string tmp_m2 = m[2];
	// 		args[tmp_m1] = std::count(tmp_m2.begin(), tmp_m2.end(), ',') + 1;
	// 	}
	// 	// std::cout << line << std::endl;
	// }
	std::ofstream file("syscallenv.h");
	file << "#ifndef SYSCALLENV_H\n#define SYSCALLENV_H\n\nstruct syscall_entry syscalls[] = {\n";
	for (auto elem:syscalls)
	{
		std::string syscall = elem.second;
		int num = elem.first;
		file << "\t[" << num << "] = {\n\t\t.name = \"" << syscall << "\",\n\t\t.nargs = " << args[num] << ",\n\t\t.rtype = " << retValue[num] << "},\n";
		// std::cout << num << " -> " <<  syscall << " have " << args[syscall] << " parameter" << std::endl;
		
	}
	file << "};\n\n#endif\n";
}