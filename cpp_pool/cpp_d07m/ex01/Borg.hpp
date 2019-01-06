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
		private:
			int			_side;
			short			_maxWarp;
			WarpSystem::Core	*_our_core;
	};
}

#endif /* !BORG_HPP_ */
