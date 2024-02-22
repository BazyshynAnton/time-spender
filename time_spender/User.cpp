#include "User.h"

void User::save_data(float duration) const 
{	
	std::string save_in_memory = std::to_string(duration);

	std::fstream user_data;
	user_data.open(user_data_path, std::ios::out | std::ios::trunc);
	user_data << save_in_memory;

	user_data.close();
}

float User::total_time_spended() const 
{
	std::string saved_user_data;

	std::fstream user_data;
	user_data.open(user_data_path, std::ios::in);
	user_data >> saved_user_data;
	user_data.close();

	float total_seconds = std::stof(saved_user_data);
	float total_hours = total_seconds * hour;


	return total_hours;

}

float User::rewrite_data() const
{
	std::string cache_time;

	std::fstream user_data;
	user_data.open(user_data_path);
	user_data >> cache_time;
	user_data.close();

	float cache_result = std::stof(cache_time);

	return cache_result;
}

void User::show_interface() const
{
    float user_time = total_time_spended();
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << user_time;

    std::string user_time_to_string = ss.str();
    std::string set_main_line = main_line + user_time_to_string + "(hrs) *";

    std::string interface_border(set_main_line.size(), '*');

    std::cout << interface_border << std::endl;
    std::cout << set_main_line << std::endl;
    std::cout << interface_border << std::endl;
}