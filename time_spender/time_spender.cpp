#include <chrono>
#include "Process.h"
#include "User.h"

int main() {
	User user;
	Process current_process;

	user.show_interface();

	bool is_active_process = current_process.is_process_exist(L"Code.exe");

	if (is_active_process)
	{
		auto start_timer = std::chrono::high_resolution_clock::now();

		while (is_active_process)
		{
			is_active_process = current_process.is_process_exist(L"Code.exe");
			Sleep(5);
		}

		auto end_timer = std::chrono::high_resolution_clock::now();

		std::chrono::duration<float> spended_time = end_timer - start_timer;

		user.save_data(spended_time.count() + user.rewrite_data());
	}
	else
	{
		std::cout << "\nYou need to launch VScode!\n";
	}

	return 0;
}