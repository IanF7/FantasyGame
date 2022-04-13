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
	Weapon* gun = new Weapon(30, 1, 30, 1000, "Gun");
	weaponShop.push_back(axe);
	weaponShop.push_back(spear);
	weaponShop.push_back(bow);
	weaponShop.push_back(katana);
	weaponShop.push_back(staff);
	weaponShop.push_back(greatSword);
	weaponShop.push_back(hammer);
	weaponShop.push_back(dagger);
	weaponShop.push_back(gun);
	//creates all available armorSets and adds each one to the most recent element in the vector
	Armor* scout = new Armor(5, 3, 12, 20, "Scout Armor");
	Armor* knight = new Armor(15, 8, -3, 20, "Knight Armor");
	Armor* executioner = new Armor(10, 12, -2, 20, "Executioner's Armor");
	Armor* samurai = new Armor(9, 9, 2, 20, "Samurai Armor");
	Armor* chainmail = new Armor(11, 8, 1, 20, "Chainmail Armor");
	Armor* martialArtist = new Armor(8, 4, 8, 20, "Martial Artist's Armor");
	armorShop.push_back(scout);
	armorShop.push_back(knight);
	armorShop.push_back(executioner);
	armorShop.push_back(samurai);
	armorShop.push_back(chainmail);
	armorShop.push_back(martialArtist);

}

//parameterized constructor
Shop::Shop(vector<Weapon*> weaponShop, vector<Armor*> armorShop)
{
}

//menu function that controls all other fuctions in shop
void Shop::menu(Player &player)
{
	//creates select to control loops
	int select = -1;
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
	bool easterEgg = false;
	//displays the user's current gold
	cout << "Gold: " << player.getGold() << endl;
	cout << "Enter the number that corresponds to the weapon you want to buy or 0 to leave: " << endl;
	//runs while cont equals 1
	do {
		//prints out all available weapons
		cout << "Available Weapons: " << endl;
		cout << weaponShop.size() << endl;
		for (int i = 0; i < weaponShop.size() - 1; i++)
		{
			cout << weaponShop[i]->getWName() << "(" << i + 1 << ")"
				<< ": " << weaponShop[i]->getCost() << endl;
		}
		for (int i = 0; i < weaponShop.size(); i++)
		{
			cout << weaponShop[i]->getWName() << "(" << i + 1 << ")"
				<< ": " << weaponShop[i]->getCost() << endl;
		}
		//takes in user input and subtracts 1 to correspond with the element in the vector
		cin >> num;
		num--;
		//if the number is not valid, tells the user no weapon was found
		if (num < 0 || num > weaponShop.size())
		{
			cout << "No weapon found" << endl;
		}
		//if num equals -1, ends buyWeapon
		else if (player.getGold() >= weaponShop[num]->getCost())
		{
			player.updateWeapons(weaponShop[num]);
			cout << weaponShop[num]->getWName() << " has been added to your inventory" << endl;
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
	//creates num and cont to control for loops
	int num = -1;
	int cont = -1;
	//prints out all available weapons
	cout << "Gold: " << player.getGold() << endl;
	cout << "Enter the number that corresponds to the armor set you want to buy or 0 to leave: " << endl;
	do {
		cout << "Available Armor Sets: " << endl;
		for (int i = 0; i < armorShop.size(); i++)
		{
			cout << armorShop[i]->getAName() << "(" << i + 1 << ")"
				<< ": " << armorShop[i]->getCost() << endl;
		}
		//takes in user input and subtracts 1 to correspond with the element in the vector
		cin >> num;
		num--;
		//if the number is not valid, tells the user no armor set was found
		if (num < 0 || num > armorShop.size())
		{
			cout << "No armor set found" << endl;
		}
		if (num == -1) {}
		else if (player.getGold() >= armorShop[num]->getCost())
		{
			player.updateArmor(armorShop[num]);
			cout << armorShop[num]->getAName() << " has been added to your inventory" << endl;
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
