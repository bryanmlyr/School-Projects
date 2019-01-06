/*
** EPITECH PROJECT, 2018
** piscine jour07m
** File description:
** ex00
*/

#ifndef WarpSystem_HPP_
	#define WarpSystem_HPP_

namespace WarpSystem
{
	class QuantumReactor {
		public:
			QuantumReactor();
			bool	isStable();
			void	setStability(bool);
		private:
			bool	_stability;
	};

	class Core {
		public:
			Core(WarpSystem::QuantumReactor *);
			WarpSystem::QuantumReactor *checkReactor();
		private:
			WarpSystem::QuantumReactor *_coreReactor;
	};
}

#endif /* !WarpSystem_HPP_ */
