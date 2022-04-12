#include <iostream>
#include <fstream>
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
	ifstream toSave("save.txt");
	ofstream fromSave("save.txt");
	cout << "Welcome to the game! Type 'start' to begin" << endl;
	while (input != "start")
	{
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			input[i] = tolower(input[i]);
		}
	}
	cout << "Enter '1' to load character or '2' to create new character: " << endl;
	do
	{
		cout << "Enter '1' to enter the arena, '2' to enter the shop, or 0 to quit: ";
		cin >> area;
		if (area < 0 || area > 2)
		{
			do {
				cout << "Please enter a valid option" << endl;
				cin >> area;
			} while (area < 0 || area > 2);
		}
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
		cout << "Do you want to save your status? Yes(1) No(2): " << endl;
	} while (area != 0);



	return 0;
}