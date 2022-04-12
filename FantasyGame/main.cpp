#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Dragon.h"
#include "Weapon.h"
#include "Armor.h"
#include "Arena.h"
#include "Shop.h"

using namespace std;

int main()
{
	Player p1;
	Enemy e1;
	Dragon d1;
	Arena a;
	Shop s;
	string input = "";
	int area = -1;
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
		cout << "Enter '1' to enter the arena, '2' to enter the shop, or 0 to quit: ";
		cin >> area;
		cout << "" << endl;
		if (area == 1)
		{
			if (level % 10 != 0)
			{
				a.battle(p1, e1);
			}
			else
			{
				cout << "WARNING! BOSS BATTLE AHEAD!" << endl;
				a.bossBattle(p1, d1);
			}
		}
		else if (area == 2)
		{
			s.menu(p1);
		}
	} while (area != 0);



	return 0;
}