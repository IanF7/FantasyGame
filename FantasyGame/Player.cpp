#include "Player.h"

//default constructor
Player::Player()
{
	//sets default stats, weapons, and armor for player
	gold = 100;
	wCount = 0;
	aCount = 0;
	weapons[wCount++] = new Weapon(4, 4, 4, 0, "Sword");
	weapons[wCount++] = new Weapon(5, 1, 6, 0, "Fists");
	armorSets[aCount++] = new Armor(8, 7, 5, 0, "Warrior Armor");
}

//parameterized constructor
Player::Player(int str, int spe, int def, int health, int stamina, int crit, int maxStamina,
	int weaponIndex, int armorIndex, int gold, int wCount, int aCount)
{
	this->gold = gold;
	this->wCount = wCount;
	this->aCount = aCount;
}

//getter for gold
int Player::getGold() const
{
	return gold;
}

//setter for gold
void Player::setGold(int gold)
{
	this->gold = gold;
}

//getter for wCount
int Player::getWCount() const
{
	return wCount;
}

//setter for wCount
void Player::setWCount(int wCount)
{
	this->wCount = wCount;
}

//getter for aCount
int Player::getACount() const
{
	return aCount;
}

//setter for aCount
void Player::setACount(int aCount)
{
	this->aCount = aCount;
}

//setWeaponIndex function that selects weapon the user will use
void Player::setWeaponIndex()
{
	cout << "Choose your weapon: " << endl;
	//prints out all available weapons and their stats
	for (int i = 0; i < getWCount(); i++)
	{
		cout << weapons[i]->getWName() << "(" << i + 1 << "): " << endl;
		cout << "str: " << weapons[i]->getStr() << "  def: " << weapons[i]->getDef() <<
			"  spe: " << weapons[i]->getSpe() << endl;
	}
	//prompts user to choose weapon by entering a number 
	cout << "Select weapon by entering the number of the corresponding weapon: " << endl;
	cin >> weaponIndex;
	//subtracts 1 to correspond with position in array
	weaponIndex--;
	//runs if the user enters an invalid number and will run until the user enters a valid number
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

//setArmorIndex function that selects armor the user will use
void Player::setArmorIndex()
{
	cout << "Choose your armor set: " << endl;
	//prints out all available armor sets and their stats
	for (int i = 0; i < getACount(); i++)
	{
		cout << armorSets[i]->getAName() << "(" << i + 1 << "): " << endl;
		cout << "str: " << armorSets[i]->getStr() << "  def: " << armorSets[i]->getDef() <<
			"  spe: " << armorSets[i]->getSpe() << endl;
	}
	//prompts user to choose armor set by entering a number
	cout << "Select armor set by entering the number of the corresponding armor set: " << endl;
	cin >> armorIndex;
	//subtracts 1 to correspond with position in array
	armorIndex--;
	//runs if the user enters an invalid number and will run until the user enters a valid number
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

//setStats function that will set the player's stats
void Player::setStats()
{
	//runs setWeaponIndex and setArmorIndex functions
	setWeaponIndex();
	setArmorIndex();
	//sets strength, speed, and defense equal to 20 plus given stat from weapon and armor
	setStr(20 + weapons[getWeaponIndex()]->getStr() + armorSets[getArmorIndex()]->getStr());
	setSpe(20 + weapons[getWeaponIndex()]->getSpe() + armorSets[getArmorIndex()]->getSpe());
	setDef(20 + weapons[getWeaponIndex()]->getDef() + armorSets[getArmorIndex()]->getDef());
	//sets crit rate equal to 20 if speed is less than 20, other wise sets it equal to
	//the speed minus 20 divided by 2 and then that minus 20
	if (getSpe() < 20)
	{
		setCrit(20);
	}
	else
	{
		setCrit(20 - ((getSpe() - 20) / 2));
		//sets crit equal to 2 if the crit is below 2
		if (getCrit() <= 2)
		{
			setCrit(2);
		}
	}
	//sets health equal to 50
	setHealth(50);
	//sets stamina and maxStamina equal to strength plus defense divided by 2, plus 20
	int stam = ((getStr() + getDef()) / 2) + 20;
	setStamina(stam);
	setMaxStamina(stam);
}

//showStats function that displays all the player's stats, current weapon, and curren armor
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

//updateWeapons function that adds a weapon to the last element in the weapons array
void Player::updateWeapons(Weapon* weapon)
{
	weapons[wCount++] = weapon;
}

//updateArmor that adds an armor to the last element in the armorSets array
void Player::updateArmor(Armor* armor)
{
	armorSets[aCount++] = armor;
}



