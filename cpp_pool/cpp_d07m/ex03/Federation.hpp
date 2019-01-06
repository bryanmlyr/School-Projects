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
#include "Destination.hpp"
#include "Borg.hpp"

namespace Borg {
	class Ship;
}

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
				Ship(int, int, std::string, short, int);
				void setupCore(WarpSystem::Core *);
				void checkCore();
				void promote(Federation::Starfleet::Captain *);
				bool move(int warp, Destination d);
				bool move(int warp);
				bool move(Destination d);
				bool move();
				int getShield();
				void setShield(int);
				int getTorpedo();
				void setTorpedo(int);
				void fire(Borg::Ship *);
				void fire(int, Borg::Ship *);
			private:
				int			_lenght;
				int			_width;
				std::string		_name;
				short			_maxWarp;
				WarpSystem::Core	*_our_core;
				Federation::Starfleet::Captain		*_our_captain;
				Destination		_location;
				Destination		_home;
				int			_shield;
				int			_photonTorpedo;
		};
	}

	class Ship {
		public:
			Ship(int, int, std::string);
			void setupCore(WarpSystem::Core *);
			void checkCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
			WarpSystem::Core *getCore();
		private:
			int			_lenght;
			int			_width;
			std::string		_name;
			short			_maxWarp;
			WarpSystem::Core	*_our_core;
			Destination		_location;
			Destination		_home;
	};
}

#endif /* !FEDERATION_HPP_ */
