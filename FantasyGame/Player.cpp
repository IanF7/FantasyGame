#include "Player.h"

Player::Player()
{
	gold = 10;
	wCount = 0;
	aCount = 0;
	weapons[wCount++] = new Weapon(4, 4, 4, 0, "Sword");
	weapons[wCount++] = new Weapon(5, 1, 6, 0, "Fists");
	armorSets[aCount++] = new Armor(8, 7, 5, 0, "Warrior Armor");
}

Player::Player(int str, int spe, int def, int health, int stamina, int crit, int maxStamina,
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

void Player::setWeaponIndex()
{
	cout << "Choose your weapon: " << endl;
	for (int i = 0; i < getWCount(); i++)
	{
		cout << weapons[i]->getWName() << "(" << i + 1 << "): " << endl;
		cout << "str: " << weapons[i]->getStr() << "  def: " << weapons[i]->getDef() <<
			"  spe: " << weapons[i]->getSpe() << endl;
	}
	cout << "Select weapon by entering the number of the corresponding weapon: " << endl;
	cin >> weaponIndex;
	weaponIndex--;
	if (weaponIndex < 0 || weaponIndex > wCount)
	{
		do
		{
			cout << "Please enter a valid option: " << endl;
			cin >> weaponIndex;
			weaponIndex--;
		} while (weaponIndex < 0 || weaponIndex > wCount);
	}
}

void Player::setArmorIndex()
{
	cout << "Choose your armor set: " << endl;
	for (int i = 0; i < getACount(); i++)
	{
		cout << armorSets[i]->getAName() << "(" << i + 1 << "): " << endl;
		cout << "str: " << armorSets[i]->getStr() << "  def: " << armorSets[i]->getDef() <<
			"  spe: " << armorSets[i]->getSpe() << endl;
	}
	cout << "Select armor set by entering the number of the corresponding armor set: " << endl;
	cin >> armorIndex;
	armorIndex--;
	if (armorIndex < 0 || armorIndex > aCount)
	{
		do
		{
			cout << "Please enter a valid option: " << endl;
			cin >> armorIndex;
			armorIndex--;
		} while (armorIndex < 0 || armorIndex > aCount);
	}
}

void Player::setStats()
{
	setWeaponIndex();
	setArmorIndex();
	setStr(20 + weapons[getWeaponIndex()]->getStr() + armorSets[getArmorIndex()]->getStr());
	setSpe(20 + weapons[getWeaponIndex()]->getSpe() + armorSets[getArmorIndex()]->getSpe());
	setDef(20 + weapons[getWeaponIndex()]->getDef() + armorSets[getArmorIndex()]->getDef());
	if (getSpe() < 20)
	{
		setCrit(20);
	}
	else
	{
		setCrit(20 + ((20 - getSpe()) / 2));
	}
	setHealth(50);
	int stam = ((getStr() + getDef()) / 2) + 20;
	setStamina(stam);
	setMaxStamina(stam);
}

void Player::showStats()
{
	cout << "Your Stats: " << endl;
	cout << "     Weapon: " << weapons[getWeaponIndex()]->getWName() << endl;
	cout << "     Armor: " << armorSets[getArmorIndex()]->getAName() << endl;
	cout << "     Health: " << getHealth() << endl;
	cout << "     Str: " << getStr() << endl;
	cout << "     Def: " << getDef() << endl;
	cout << "     Spe: " << getSpe() << endl;
	cout << "     Crit Rate: " << getCrit() << endl;
	cout << "     Stamina: " << getMaxStamina() << endl;
	cout << "" << endl;
}

void Player::updateWeapons(Weapon* weapon)
{
	weapons[wCount++] = weapon;
}

void Player::updateArmor(Armor* armor)
{
	armorSets[aCount++] = armor;
}

ostream& operator<<(ostream& out, const Player& rhs)
{
	out << "Gold: " << rhs.getGold() << "\n";
}

istream& operator>>(istream& in, Player& rhs)
{
	// // O: insert return statement here
}
