#include "Player.h"

Player::Player()
{
	gold = 0;
	wCount = 0;
	aCount = 0;
	weapons[wCount++] = new Weapon(4, 4, 4, 0, "Sword");
	weapons[wCount++] = new Weapon(1, 1, 1, 0, "Fists");
	armorSets[aCount++] = new Armor(8, 7, 5, 0, "Warrior Armor");
	cout << getWCount() << endl;
}

Player::Player(int str, int spe, int def, int health, int stamina, int crit, 
	int weaponIndex, int armorIndex, int gold, int wCount, int aCount)
{
	this->gold = gold;
	this->wCount = wCount;
	this->aCount = aCount;
}

int Player::getGold() const
{
	return gold;
}

void Player::setGold(int gold)
{
	this->gold = gold;
}

int Player::getWCount() const
{
	return wCount;
}

void Player::setWCount(int wCount)
{
	this->wCount = wCount;
}

int Player::getACount() const
{
	return aCount;
}

void Player::setACount(int aCount)
{
	this->aCount = aCount;
}

Weapon* Player::getWeapons() const
{
	return *weapons;
}

void Player::setWeapons(Weapon* weapons)
{
}

Armor* Player::getArmorSets() const
{
	return *armorSets;
}

void Player::setArmorSets(Armor* armorSets)
{
}

void Player::setWeaponIndex(int weaponIndex, Weapon* weapons)
{
	cout << "Select weapon by entering the number of the corresponding weapon: " << endl;
	while (weaponIndex > 0 && weaponIndex < sizeof(weapons))
	{
		for (int i = 0; i < getWCount(); i++)
		{
			cout << weapons[0].getWName() << "(" << i + 1 << "): " << endl;
			cout << "str: " << weapons[i].getStr() << "  spe: " << weapons[i].getSpe() <<
				"  def: " << weapons[i].getDef() << endl;
		}
		cin >> weaponIndex;
		weaponIndex--;
		cout << "" << endl;
	}
}

void Player::setArmorIndex(int armorIndex, Armor* armorSets)
{
	cout << "Select armor by entering the number of the corresponding weapon: " << endl;
	while (armorIndex > 0 && armorIndex <= sizeof(armorSets))
	{
		for (int i = 0; i < getACount(); i++)
		{
			cout << armorSets[i].getAName() << "(" << i + 1 << "): " << endl;
			cout << "str: " << armorSets[i].getStr() << "  spe: " << armorSets[i].getSpe() <<
				"  def: " << armorSets[i].getDef() << endl;
		}
		cin >> armorIndex;
		armorIndex--;
		cout << "" << endl;
	}
}

void Player::setStats(Weapon* weapons, Armor* armorSets, int weaponIndex, int armorIndex)
{
	setWeaponIndex(weaponIndex, weapons);
	setArmorIndex(armorIndex, armorSets);
	setStr(20 + weapons[getWeaponIndex()].getStr() + armorSets[getArmorIndex()].getStr());
	setSpe(20 + weapons[getWeaponIndex()].getSpe() + armorSets[getArmorIndex()].getSpe());
	setDef(20 + weapons[getWeaponIndex()].getDef() + armorSets[getArmorIndex()].getDef());
	if (getSpe() < 20)
	{
		setCrit(20);
	}
	else
	{
		setCrit(20 - ((20 - getSpe()) / 2));
	}
	setHealth(50);
	setStamina(50);
}
