#include "Shop.h"

//default constructor
Shop::Shop()
{
	//creates all available weapons and adds each one to the most recent element in the vector
	Weapon* axe = new Weapon(6, 2, 4, 20, "Axe");
	Weapon* spear = new Weapon(6, 3, 3, 20, "Spear");
	Weapon* bow = new Weapon(4, 1, 7, 20, "Bow");
	Weapon* katana = new Weapon(5, 2, 5, 20, "Katana");
	Weapon* staff = new Weapon(2, 3, 7, 20, "Staff");
	Weapon* greatSword = new Weapon(7, 4, 1, 20, "Great Sword");
	Weapon* hammer = new Weapon(8, 2, 2, 20, "Hammer");
	Weapon* dagger = new Weapon(4, 2, 6, 20, "Dagger");
	Weapon* gun = new Weapon(20, 1, 20, 700, "Gun");
	Weapon* lightsaber = new Weapon(50, 50, 50, 0, "Lightsaber");
	weaponShop.push_back(axe);
	weaponShop.push_back(spear);
	weaponShop.push_back(bow);
	weaponShop.push_back(katana);
	weaponShop.push_back(staff);
	weaponShop.push_back(greatSword);
	weaponShop.push_back(hammer);
	weaponShop.push_back(dagger);
	weaponShop.push_back(gun);
	weaponShop.push_back(lightsaber);
	//creates all available armorSets and adds each one to the most recent element in the vector
	Armor* scout = new Armor(5, 3, 12, 30, "Scout Armor");
	Armor* knight = new Armor(15, 8, -3, 30, "Knight Armor");
	Armor* executioner = new Armor(10, 12, -2, 30, "Executioner's Armor");
	Armor* samurai = new Armor(9, 9, 2, 30, "Samurai Armor");
	Armor* chainmail = new Armor(11, 8, 1, 30, "Chainmail Armor");
	Armor* martialArtist = new Armor(8, 4, 8, 30, "Martial Artist's Armor");
	armorShop.push_back(scout);
	armorShop.push_back(knight);
	armorShop.push_back(executioner);
	armorShop.push_back(samurai);
	armorShop.push_back(chainmail);
	armorShop.push_back(martialArtist);
	easterEgg = false;
}

//parameterized constructor
Shop::Shop(vector<Weapon*> weaponShop, vector<Armor*> armorShop, bool easterEgg)
{
	this->easterEgg = easterEgg;
}

//menu function that controls all other fuctions in shop
void Shop::menu(Player &player)
{
	//creates select to control loops
	int select = -1;
	//checks if a weapon or armor already exists in the players inventory and if so deletes
	//it from the shop
	bool compare = false;
	for (int i = 0; i < weaponShop.size(); i++)
	{
		compare = player.compareWName(weaponShop[i]->getWName());
		if (compare)
		{
			weaponShop.erase(weaponShop.begin() + i);
		}
	}
	compare = false;
	for (int i = 0; i < armorShop.size(); i++)
	{
		compare = player.compareAName(armorShop[i]->getAName());
		if (compare)
		{
			armorShop.erase(armorShop.begin() + i);
		}
	}
	//runs while the user has not entered 0
	do
	{
		//prompts the user to enter a number
		cout << "Welcome to the shop! To buy weapons, enter 1, to buy armor enter 2,"
			<< " to leave enter 0" << endl;
		cin >> select;
		//prompts the user to enter a valid number if the number is invalid
		if (select != 1 && select != 2 && select != 0)
		{
			do
			{
				cout << "Please enter a valid option" << endl;
				cin >> select;
			} while (select != 1 && select != 2 && select != 0);
		}
		//if the user enters 1, runs buyWeapons, if 2, runs buyArmor
		if (select == 1)
		{
			buyWeapon(player);
		}
		else if (select == 2)
		{
			buyArmor(player);
		}
	} while (select != 0);
}

//buyWeapon function that allows the user to buy weapons
void Shop::buyWeapon(Player &player)
{
	//creates num and cont to control loops
	int num = -2;
	int cont = -1;
	cout << "Enter the number that corresponds to the weapon you want to buy or 0 to leave: " << endl;
	//runs while cont equals 1
	do {
		//displays the user's current gold
		cout << "Gold: " << player.getGold() << endl;
		cout << "" << endl;
		cout << "Available Weapons: " << endl;
		//prints out all available weapons except the last one if the easter egg has not
		//been found, otherwise prints out all available weapons
		if (easterEgg)
		{
			for (int i = 0; i < weaponShop.size(); i++)
			{
				cout << weaponShop[i]->getWName() << "(" << i + 1 << ")"
					<< ": " << weaponShop[i]->getCost() << endl;
			}
		}
		else
		{
			for (int i = 0; i < weaponShop.size() - 1; i++)
			{
				cout << weaponShop[i]->getWName() << "(" << i + 1 << ")"
					<< ": " << weaponShop[i]->getCost() << endl;
			}
		}
		//takes in user input and subtracts 1 to correspond with the element in the vector
		cin >> num;
		num--;
		//if the number is -1, stops code
		if (num == -1) 
		{
			break;
		}
		//if the number is 1976 (year of Star Wars release) is entered and has not been
		//purchased yet adds lightsaber to player's inventory
		else if (num == 1976 && !easterEgg)
		{
			cout << "TEST" << endl;
			player.updateWeapons(weaponShop[weaponShop.size()-1]);
			cout << weaponShop[weaponShop.size()-1]->getWName()
				<< " has been added to your inventory" << endl;
			easterEgg = true;
			weaponShop.erase(weaponShop.begin() + (weaponShop.size() - 1));
		}
		//if num is not in the range of indexes in the vector, tells user that no weapon was found
		else if (num < 0 || num > weaponShop.size() - 2)
		{
			cout << "No weapon found" << endl;
		}
		//if the player has enough gold for the selected weapon, adds the weapon to the player's
		//inventory and then deletes it from the shop and updates the user's gold
		else if (player.getGold() >= weaponShop[num]->getCost())
		{
			player.updateWeapons(weaponShop[num]);
			cout << weaponShop[num]->getWName() << " has been added to your inventory" << endl;
			player.setGold(player.getGold() - weaponShop[num]->getCost());
			weaponShop.erase(weaponShop.begin() + num);
		}
		else
		{
			cout << "You don't have enough gold to purchase this item" << endl;
		}
		cout << "If you want to buy another item, enter 1, otherwise enter 0: " << endl;
		cin >> cont;
	} while (cont == 1);
}

//buyArmor function that allows the user to buy armor
void Shop::buyArmor(Player &player)
{
	//creates num and cont to control loops
	int num = -2;
	int cont = -1;
	cout << "Enter the number that corresponds to the weapon you want to buy or 0 to leave: " << endl;
	//runs while cont equals 1
	do {
		//displays the user's current gold
		cout << "Gold: " << player.getGold() << endl;
		cout << "" << endl;
		cout << "Available Armor Sets: " << endl;
		//prints out all available armor sets
		for (int i = 0; i < armorShop.size(); i++)
		{
			cout << armorShop[i]->getAName() << "(" << i + 1 << ")"
				<< ": " << armorShop[i]->getCost() << endl;
		}
		//takes in user input and subtracts 1 to correspond with the element in the vector
		cin >> num;
		num--;
		//if the number is -1, stops code
		if (num == -1)
		{
			break;
		}
		//if num is not in the range of indexes in the vector, tells user that no weapon was found
		else if (num < 0 || num > armorShop.size() - 1)
		{
			cout << "No armor found" << endl;
		}
		//if the player has enough gold for the selected weapon, adds the armor to the player's
		//inventory and then deletes it from the shop and updates the user's gold
		else if (player.getGold() >= armorShop[num]->getCost())
		{
			player.updateArmor(armorShop[num]);
			cout << armorShop[num]->getAName() << " has been added to your inventory" << endl;
			player.setGold(player.getGold() - weaponShop[num]->getCost());
			armorShop.erase(armorShop.begin() + num);
		}
		else
		{
			cout << "You don't have enough gold to purchase this item" << endl;
		}
		cout << "If you want to buy another item, enter 1, otherwise enter 0: " << endl;
		cin >> cont;
	} while (cont == 1);
}
