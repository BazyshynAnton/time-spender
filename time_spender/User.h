#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

class User {
	private:
		std::wstring user_data_path = L"C:\\Users\\bazys\\OneDrive\\Desktop\\study++\\time_spender\\time_spender\\user.txt";
		float second{ 1 };
		float hour{ 0.000277778 };
		std::string main_line = "* Total Time in VScode: ";

	public:
		void show_interface() const;
		float total_time_spended() const;
		void save_data(float) const;
		float rewrite_data() const;
};

