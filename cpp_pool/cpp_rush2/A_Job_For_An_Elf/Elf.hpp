/*
** EPITECH PROJECT, 2018
** Elf
** File description:
** Elf class
*/

#ifndef ELF_HPP_
	#define ELF_HPP_

#include "IElf.hpp"
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"

class Elf : public IELF
{
	public:
		Elf();
		~Elf();
		Object	*wrap_gift(Object *);
		void 	close_box(Object *);
		void 	open_box(Object *);
		void 	open_wrap(Object *);
		void 	close_wrap(Object *);
		void 	putOnTable(Object *);
		Object 	*takeFromTable(int);
		void 	putOnConveyor(Object *);
		Object 	*takeFromConveyor();
		void 	SendWrap();
		void	LookTable();
};

#endif /* !ELF_HPP_ */
