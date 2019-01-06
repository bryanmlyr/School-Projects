#include "Squad.hpp"
#include "AssaultTerminator.hpp"
#include "TacticalMarine.hpp"
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <memory>

int  main()
{
std:: unique_ptr <ISquad > vlc(new  Squad);
vlc ->push(new  TacticalMarine);
vlc ->push(new  AssaultTerminator);
vlc ->push(new  AssaultTerminator);
vlc ->push(new  AssaultTerminator);
vlc ->push(new  AssaultTerminator);
vlc ->push(new  AssaultTerminator);
vlc ->push(new  AssaultTerminator);
vlc ->push(NULL);
for (int i = 0; i < vlc ->getCount(); ++i) {
const  auto  cur = vlc ->getUnit(i);
cur ->battleCry ();
cur ->rangedAttack ();
cur ->meleeAttack ();
}
return  0;
}
