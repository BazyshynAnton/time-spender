#include "Process.h"


	bool Process::is_process_exist(const std::wstring& process_name)
	{
		HANDLE h_process_snap;
		PROCESSENTRY32 pe_32;

		h_process_snap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

		if (h_process_snap == INVALID_HANDLE_VALUE)
		{
			return false;
		}

		pe_32.dwSize = sizeof(PROCESSENTRY32);
		bool first_process = check_first_process(h_process_snap, pe_32);

		if (!first_process)
		{
			return false;
		}

		do {

			if (wcscmp(pe_32.szExeFile, process_name.c_str()) == 0)
			{
				CloseHandle(h_process_snap);
				return true;
			}

		} while (Process32Next(h_process_snap, &pe_32));

		CloseHandle(h_process_snap);
		return false;
	}

	bool Process::check_first_process(HANDLE h_process_snap,PROCESSENTRY32W pe_32)
	{

		return Process32First(h_process_snap, &pe_32);

	}
