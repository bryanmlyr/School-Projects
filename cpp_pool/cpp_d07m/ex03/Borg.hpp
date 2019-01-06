/*
** EPITECH PROJECT, 2018
** psicine
** File description:
** ex01
*/

#ifndef BORG_HPP_
	#define BORG_HPP_

#include "Federation.hpp"

namespace Federation {
	namespace Starfleet {
		class Ship;
	}
	class Ship;
}

namespace Borg
{
	class Ship {
		public:
			Ship(int, short);
			Ship(int);
			void setupCore(WarpSystem::Core *);
			void checkCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
			int getShield();
			void setShield(int);
			int getWeaponFrequency();
			void setWeaponFrequency(int);
			short getRepair();
			void setRepair(short);
			void fire(Federation::Starfleet::Ship *);
			void fire(Federation::Ship *);
			void repair();
		private:
			int			_side;
			short			_maxWarp;
			WarpSystem::Core	*_our_core;
			Destination		_location;
			Destination		_home;
			int			_shield;
			int			_weaponFrequency;
			short			_repair;
	};
}

#endif /* !BORG_HPP_ */
