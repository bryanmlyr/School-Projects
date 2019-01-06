//
// EPITECH PROJECT, 2018
// piscine cpp
// File description:
// ex00
//

#include <string>
#include <fstream>
#include <iostream>

int	main(int ac, char **av)
{
	std::string str;

	if (ac <= 1)
		std::cout << "my_cat: Usage: "
		<< av[0] << " file [...]" << std::endl;
	for (int x = 1; x < ac; x++) {
		std::ifstream file(av[x]);
		if (!file.is_open()) {
			std::cerr << "my_cat: " << av[x]
			<< ": No such file or directory" << std::endl;
		} else {
			while (std::getline(file, str, '\0'))
				std::cout << str;
		}
	}
	return 0;
}