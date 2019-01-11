/*
** EPITECH PROJECT, 2018
** Interface
** File description:
** Elves
*/

#ifndef IELF_HPP_
	#define IELF_HPP_

#include "object.hpp"
#include "Wrap.hpp"
#include "ITable.hpp"
#include "IConveyorBelt.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"

class IELF
{
	public:
		virtual ~IELF() {}
		virtual Object	*wrap_gift(Object *) = 0;
		virtual void 	close_box(Object *) = 0;
		virtual void 	open_box(Object *) = 0;
		virtual void 	close_wrap(Object *) = 0;
		virtual void 	open_wrap(Object *) = 0;
		virtual void 	putOnTable(Object *) = 0;
		virtual Object 	*takeFromTable(int) = 0;
		virtual void 	putOnConveyor(Object *) = 0;
		virtual Object 	*takeFromConveyor() = 0;
		virtual void 	SendWrap() = 0;
		virtual	void	LookTable() = 0;
	protected:
		ITable		*_table;
		IConveyorBelt	*_conveyor;
};

#endif /* !IELF_HPP_ */
