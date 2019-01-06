//
// EPITECH PROJECT, 2018
// pscine cpp
// File description:
// temperature class
//

#ifndef TEMPERATURE_HPP_
	#define TEMPERATURE_HPP_

class	temperature {
	public:
		temperature();
		void	mul_spaces();
		void	find_type();
		void	print_converted_temp();
	private:
		std::string input;
		std::string temperature_type;
};

#endif /* !TEMPERATURE_HPP_ */
