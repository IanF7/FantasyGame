#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Weapon.h"
#include "Armor.h"
#include "Arena.h"

using namespace std;

int main()
{
	Player p1;
	Enemy e1;
	Dragon d1;
	Arena a;
	string input = "";
	int level = 1;
	cout << "Welcome to the game! Type 'start' to begin" << endl;
	while (input != "start")
	{
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			input[i] = tolower(input[i]);
		}
	}
	do 
	{
		if (level % 10 != 0)
		{
			cout << "" << endl;
			p1.setStats();
			cout << "Health: " << p1.getHealth() << endl;
			cout << "str: " << p1.getStr() << endl;
			cout << "def: " << p1.getDef() << endl;
			cout << "spe:" << p1.getSpe() << endl;
			cout << "Stamina: " << p1.getMaxStamina() << endl;
			cout << "" << endl;
			e1.setStats();
			cout << "Health: " << p1.getHealth() << endl;
			cout << "str: " << e1.getStr() << endl;
			cout << "def: " << e1.getDef() << endl;
			cout << "spe:" << e1.getSpe() << endl;
			cout << "Stamina: " << e1.getMaxStamina() << endl;
			cout << "" << endl;
			cout << "" << endl;
			a.fight(p1, e1);
			level++;
		}
		else
		{
			cout << "" << endl;
			cout << "WARNING! BOSS FIGHT AHEAD!" << endl;
			p1.setStats();
			cout << "Health: " << p1.getHealth() << endl;
			cout << "str: " << p1.getStr() << endl;
			cout << "def: " << p1.getDef() << endl;
			cout << "spe:" << p1.getSpe() << endl;
			cout << "Stamina: " << p1.getMaxStamina() << endl;
			cout << "" << endl;
			d1.setStats();
			a.bossFight(p1, d1);
			level++;
		}
		input = "";
		cout << "Do you wish to fight again? If so, enter 1, to end the game, enter 2: "
			<< endl;
		cin >> input;
	} while (input == "1");
	return 0;
}