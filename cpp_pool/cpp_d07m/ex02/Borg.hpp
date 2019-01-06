/*
** EPITECH PROJECT, 2018
** psicine
** File description:
** ex01
*/

#ifndef BORG_HPP_
	#define BORG_HPP_

#include "Federation.hpp"

namespace Borg
{
	class Ship {
		public:
			Ship();
			void setupCore(WarpSystem::Core *);
			void checkCore();
			bool move(int warp, Destination d);
			bool move(int warp);
			bool move(Destination d);
			bool move();
		private:
			int			_side;
			short			_maxWarp;
			WarpSystem::Core	*_our_core;
			Destination		_location;
			Destination		_home;
	};
}

#endif /* !BORG_HPP_ */
