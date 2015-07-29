#include <fstream>
#include <map>
#include <iostream>
#include <regex>

int main()
{
	std::regex reg_syscalls("^#define\\s+__NR_(\\w+)\\s+(\\d+)");
	std::regex reg_args("^[\\w\\s_#]*asmlinkage long sys_(\\w+)[(]([\\w\\s_*,]+)[)]");
	std::ifstream sycalls_file("/usr/include/x86_64-linux-gnu/asm/unistd_64.h");
	std::map<int, std::string> syscalls;
	std::map<std::string, int> args;
	while (sycalls_file.good())
	{
		std::string line;
		std::getline(sycalls_file, line);
		std::smatch m;
		if (regex_search(line, m, reg_syscalls))
		{
			// std::cout << m[0] << " -> " << m[1] << " et " << m[2] << std::endl;
			int num = std::stoi(m[2]);
			syscalls[num] = m[1];
		}
		// std::cout << line << std::endl;
	}

	std::ifstream args_file("/usr/src/linux-headers-3.16.0-44/include/linux/syscalls.h");
	while (args_file.good())
	{
		std::string line;
		std::getline(args_file, line, ';');
		std::smatch m;
		// std::cout << "__" << line << "__" << std::endl;
		if (regex_search(line, m, reg_args))
		{
			// std::cout << m[0] << " -> " << m[1] << " et " << m[2] << std::endl;
			std::string tmp_m1 = m[1];
			std::string tmp_m2 = m[2];
			args[tmp_m1] = std::count(tmp_m2.begin(), tmp_m2.end(), ',') + 1;
		}
		// std::cout << line << std::endl;
	}
	std::ofstream file("syscallenv.h");
	file << "#ifndef SYSCALLENV_H\n#define SYSCALLENV_H\nstruct syscall_entry syscalls[] = {\n";
	for (auto elem:syscalls)
	{
		std::string syscall = elem.second;
		int num = elem.first;
		file << "\t[" << num << "] = {\n\t\t.name = \"" << syscall << "\",\n\t\t.nargs = " << args[syscall] << "}\n";
		std::cout << num << " -> " <<  syscall << " have " << args[syscall] << " parameter" << std::endl;
		
	}
}