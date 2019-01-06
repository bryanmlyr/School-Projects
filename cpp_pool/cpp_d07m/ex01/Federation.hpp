/*
** EPITECH PROJECT, 2018
** Piscine cpp
** File description:
** ex00
*/

#ifndef FEDERATION_HPP_
	#define FEDERATION_HPP_

#include <string>
#include "WarpSystem.hpp"

namespace Federation
{
	namespace Starfleet
	{
		class Captain {
			public:
				Captain(std::string);
				std::string getName();
				int getAge();
				void setAge(int);
			private:
				std::string	_name;
				int		age;
		};

		class Ensign {
			public:
				Ensign(std::string);
			private:
				std::string	_name;
		};

		class Ship {
			public:
				Ship(int, int, std::string, short);
				void setupCore(WarpSystem::Core *);
				void checkCore();
				void promote(Federation::Starfleet::Captain *);
			private:
				int			_lenght;
				int			_width;
				std::string		_name;
				short			_maxWarp;
				WarpSystem::Core	*_our_core;
				Federation::Starfleet::Captain		*_our_captain;
		};
	}

	class Ship {
		public:
			Ship(int, int, std::string);
			void setupCore(WarpSystem::Core *);
			void checkCore();
		private:
			int			_lenght;
			int			_width;
			std::string		_name;
			short			_maxWarp;
			WarpSystem::Core	*_our_core;
	};
}

#endif /* !FEDERATION_HPP_ */
