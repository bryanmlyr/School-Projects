//
// EPITECH PROJECT, 2018
// pscine cpp
// File description:
// ex01
//

#include <iostream>
#include <iomanip>
#include <string>
#include "temperature.hpp"

temperature::temperature() {
	std::string	str;

	std::getline(std::cin, str, '\n');
	this->input = str;
}

void	temperature::mul_spaces() {
	int		a = 0;
	std::string	wow;

	for (unsigned int x = 0; x < this->input.length(); x++) {
		while (this->input[x] == ' ') {
			x++;
			a = 1;
		}
		if (a == 1)
			wow += ' ';
		a = 0;
		wow += this->input[x];
	}
	this->input = wow;
};

void	temperature::find_type() {
	std::string::size_type	n;

	n = this->input.find(' ');
	if (n > this->input.length()) {
		return;
	}
	this->temperature_type = this->input.substr(n + 1);
}

void	temperature::print_converted_temp() {
	float val = 0;

	if (this->temperature_type == "Celsius") {
		val = (std::stof(this->input) * 9 / 5 + 32);
		std::cout << std::setw(16);
		std::cout << std::fixed;
		std::cout << std::setprecision(3) << val;
		std::cout << std::setw(16) << "Fahrenheit" << std::endl;
	} else if (this->temperature_type == "Fahrenheit") {
		val = (5.0f / 9.0f * (std::stof(this->input) - 32));
		std::cout << std::setw(16);
		std::cout << std::fixed;
		std::cout << std::setprecision(3) << val;
		std::cout << std::setw(16) << "Celsius" << std::endl;
	}
}

int	main()
{
	temperature temp;

	temp.mul_spaces();
	temp.find_type();
	temp.print_converted_temp();
	return 0;
}