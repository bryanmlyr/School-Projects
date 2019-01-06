/*
** EPITECH PROJECT, 2018
** pool
** File description:
** char
*/

#ifndef CHARACTER_HPP_
	#define CHARACTER_HPP_

#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character {
	public:
		Character(const std::string &);
		~Character();
		void recoverAP();
		void equip(AWeapon *);
		void attack(AEnemy *);
		AWeapon	*getWeapon() const;
		int	getAP() const;
		const std::string &getName() const;
	private:
		std::string		_name;
		int			_ap;
		AWeapon			*_Weapon;
};

std::ostream	&operator<<(std::ostream &, Character &);

#endif /* !CHARACTER_HPP_ */
