#include "Shop.h"

Shop::Shop()
{
	Weapon* axe = new Weapon(6, 2, 4, 20, "Axe");
	Weapon* spear = new Weapon(6, 3, 3, 20, "Spear");
	Weapon* bow = new Weapon(4, 1, 7, 20, "Bow");
	Weapon* katana = new Weapon(5, 2, 5, 20, "Katana");
	Weapon* staff = new Weapon(2, 3, 7, 20, "Staff");
	Weapon* greatSword = new Weapon(7, 4, 1, 20, "Great Sword");
	Weapon* hammer = new Weapon(8, 2, 2, 20, "Hammer");
	Weapon* dagger = new Weapon(4, 2, 6, 20, "Dagger");
	Weapon* gun = new Weapon(30, 1, 30, 1000, "Gun");
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

Shop::Shop(vector<Weapon*> weaponShop, vector<Armor*> armorShop)
{
}

void Shop::menu(Player &player)
{
	int select = -1;
	do
	{
		cout << "Welcome to the shop! To buy weapons, enter 1, to buy armor enter 2,"
			<< " to leave enter 0" << endl;
		cin >> select;
		if (select != 1 && select != 2 && select != 0)
		{
			do
			{
				cout << "Please enter a valid option" << endl;
				cin >> select;
			} while (select != 1 && select != 2 && select != 0);
		}
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

void Shop::buyWeapon(Player &player)
{
	int num = -2;
	int cont = -1;
	cout << "Enter the number that corresponds to the weapon you want to buy or 0 to leave: " << endl;
	do {
		cout << "Available Weapons: " << endl;
		for (int i = 0; i < weaponShop.size() - 1; i++)
		{
			cout << weaponShop[i]->getWName() << "(" << i + 1 << ")"
				<< ": " << weaponShop[i]->getCost() << endl;;
		}
		cin >> num;
		num--;
		if (num < 0 || num > weaponShop.size())
		{
			do {
				cout << "Please enter a valid option" << endl;
				cin >> num;
				num--;
			} while (num < 0 || num > weaponShop.size());
		}
		if(num == -1) {}
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

void Shop::buyArmor(Player &player)
{
	int num = -1;
	int cont = -1;
	cout << "Enter the number that corresponds to the armor set you want to buy or 0 to leave: " << endl;
	do {
		cout << "Available Armor Sets: " << endl;
		for (int i = 0; i < armorShop.size(); i++)
		{
			cout << armorShop[i]->getAName() << "(" << i + 1 << ")"
				<< ": " << armorShop[i]->getCost() << endl;;
		}
		cin >> num;
		num--;
		if (num < 0 || num > weaponShop.size())
		{
			do {
				cout << "Please enter a valid option" << endl;
				cin >> num;
				num--;
			} while (num < 0 || num > weaponShop.size());
		}
		if (num == 0)
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
