#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Arena.h"

using namespace std;

int main()
{
	Player p1;
	Arena a;
	string input = "";
	p1.setStats(p1.getWeapons(), p1.getArmorSets(), 1, 1);
	cout << p1.getStr() << endl;
	cout << p1.getSpe() << endl;
	cout << p1.getDef() << endl;
	cout << p1.getHealth() << endl;
	cout << p1.getStamina() << endl;
	return 0;
}