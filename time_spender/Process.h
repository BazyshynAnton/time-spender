#include<iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>

class Process {
	public:
		bool is_process_exist(const std::wstring&);
	private:
		bool check_first_process(HANDLE , PROCESSENTRY32W);
};