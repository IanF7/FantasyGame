//Ian Fletcher
// CST-210 Final Project
//This is my own code with help from Professor Fritz

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
	//creates objects of classes
	Player p1;
	Enemy e1;
	Dragon d1;
	Arena a;
	Shop s;
	//creates objects to control loops
	string input = "";
	int area = -1;
	int level = 1;
	int save = 0;
	cout << "Welcome to the game! Type 'start' to begin" << endl;
	//takes in user input to start game and sets it to lower case
	while (input != "start")
	{
		cin >> input;
		for (int i = 0; i < input.length(); i++)
		{
			input[i] = tolower(input[i]);
		}
	}
	cout << "To load a character, enter 1, to create a new character enter 2: " << endl;
	cin >> save;
	//if the number isn't valid, runs loop to prompt user to enter in a number that does work
	if (save == 1)
	{
		p1.loadCharacter();
		cout << "Character loaded successfully" << endl;
	}
	if (save == 2)
	{
		cout << "New Character created!" << endl;
	}
	else if (save != 1 && save != 2)
	{
		do {
			cout << "Please enter a valid option" << endl;
			cin >> save;
		} while (save != 1 && save !=2);
	}
	//do/while loop that runs until user enters 0
	do
	{
		//prompts user to enter in number to control location
		cout << "Enter '1' to enter the arena, '2' to enter the shop, or 0 to quit: ";
		cin >> area;
		//if the number isn't valid, runs loop to prompt user to enter in a number that does work
		if (area < 0 || area > 2)
		{
			do {
				cout << "Please enter a valid option" << endl;
				cin >> area;
			} while (area < 0 || area > 2);
		}
		cout << "" << endl;
		//runs if the user enters 1 and every 10 fights the user will enter a boss battle
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
		//runs if the user enters 2 to access the shop
		else if (area == 2)
		{
			s.menu(p1);
		}
		cout << "Saving character..." << endl;
		p1.saveCharacter();
	} while (area != 0);

	return 0;
}