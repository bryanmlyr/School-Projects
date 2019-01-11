#include "Elf.hpp"
#include "toy.hpp"
#include "teddy.hpp"
#include "littlepony.hpp"

void testTable(Elf elf, Object *gift2)
{
	elf.putOnTable(new Teddy("lama"));
	elf.putOnTable(gift2);
	elf.putOnTable(new LittlePony("lama"));
	elf.LookTable();
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.putOnTable(new Toy("lama"));
	elf.LookTable();
}

int main()
{
	Object *gift1 = new Toy("Sprite");
	Object *gift2 = new Toy("Banana");
	Object *gift3 = new Toy("Failed");
	Object *gift4 = new Toy("NotaToy");
	Elf elf;

	elf.putOnConveyor(gift1);
	elf.putOnConveyor(gift3);
	elf.SendWrap();
	elf.SendWrap();
	elf.putOnConveyor(gift2);
	elf.SendWrap();
	elf.putOnConveyor(gift4);
	elf.takeFromConveyor();
	elf.takeFromConveyor();
	testTable(elf, gift2);
	return 0;
}