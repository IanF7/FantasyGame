#include "Shop.h"

Shop::Shop()
{
	Weapon* axe = new Weapon(6, 2, 4, 20, "Axe");
	Weapon* katana = new Weapon(5, 2, 5, 20, "Katana");
	weaponShop.push_back(axe);
	weaponShop.push_back(katana);
}

Shop::Shop(vector<Weapon*> weaponShop, vector<Armor*> armorShop)
{
}

void Shop::menu(Player player)
{
	int select = -1;
	do
	{
		cout << "Welcome to the shop! To buy weapons, enter 1, to buy armor enter 2,"
			<< " to leave enter 0" << endl;
		cin >> select;
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

void Shop::buyWeapon(Player player)
{
	int num = -1;
	int cont = -1;
	cout << "Enter the number that corresponds to the weapon you want to buy: " << endl;
	do {
		cout << "Available Weapons: " << endl;
		for (int i = 0; i < weaponShop.size(); i++)
		{
			cout << weaponShop[i]->getWName() << "(" << i + 1 << ")"
				<< ": " << weaponShop[i]->getCost() << endl;;
		}
		cin >> num;
		num--;
		if (player.getGold() >= weaponShop[num]->getCost())
		{
			player.updateWeapons(weaponShop[num]);
			cout << weaponShop[num]->getWName() << " has been added to your inventory" << endl;
		}
		else
		{
			cout << "You don't have enough gold to purchase this item" << endl;
		}
		cout << "If you want to buy another item, enter 1, otherwise enter 0: " << endl;
		cin >> cont;
	} while (cont == 1);
}

void Shop::buyArmor(Player player)
{
}
