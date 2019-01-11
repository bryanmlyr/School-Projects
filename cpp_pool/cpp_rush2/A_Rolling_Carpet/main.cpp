/*
** EPITECH PROJECT, 2018
** Main
** File description:
** A rolling carpet
*/

#include <memory>
#include "PapaXmasConveyorBelt.hpp"
#include "PapaXmasTable.hpp"
#include "toy.hpp"

ITable	*createTable()
{
	return new PapaXmasTable;
}

IConveyorBelt	*createConveyorBelt()
{
	return new PapaXmasConveyorBelt;
}

void	print_vec(std::vector<Object *> wow)
{
	for (unsigned int x = 0 ; x < wow.size() ; x++) {
		std::cout << wow[x]->getTitle() << std::endl;
	}
	std::cout << "Nombres d'objets: " << wow.size() << std::endl;
}

void	test_table()
{
	ITable	*table = createTable();

	table->put(new Toy("'s R us1"));
	table->put(new Toy("'s R us2"));
	table->put(new Toy("'s R us3"));
	table->put(new Toy("'s R us4"));
	table->put(new Toy("'s R us5"));
	table->put(new Toy("'s R us6"));
	table->put(new Toy("'s R us7"));
	table->put(new Toy("'s R us8"));
	table->put(new Toy("'s R us9"));
	table->put(new Toy("'s R us10"));
	print_vec(table->lookTable());
	table->take(0);
	table->take(0);
	table->take(0);
	table->take(0);
	table->take(0);
	table->take(0);
	print_vec(table->lookTable());
}

void	test_conveyorbelt()
{
	IConveyorBelt	*conveyorbelt = createConveyorBelt();

	conveyorbelt->put(new Toy("'s Story1"));
	std::cout << conveyorbelt->pressButtonOUT()->getTitle() << std::endl;
	conveyorbelt->put(new Toy("'s Story2"));
	conveyorbelt->put(new Toy("'s Story3"));
	conveyorbelt->put(new Toy("'s Story4"));
	conveyorbelt->put(new Toy("'s Story5"));
	conveyorbelt->put(new Toy("'s Story6"));
	conveyorbelt->put(new Toy("'s Story7"));
	conveyorbelt->pressButtonIN();
	conveyorbelt->put(new Toy("'s Story8"));
}

int	main()
{
	std::cout << "Testing Table :" << std::endl;
	test_table();
	std::cout << std::endl << "Testing Conveyorbelt :" << std::endl;
	test_conveyorbelt();
	return 0;
}