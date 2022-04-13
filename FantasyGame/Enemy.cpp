#include "Enemy.h"
#include <ctime>

//default constructor
Enemy::Enemy()
{
	//seeds random number generator
	srand(time(NULL));
	//sets wCount, aCount and reward to 0
	wCount = aCount = 0;
	reward = 0;
	//creates available weapons and armor sets for enemy to choose from
	weapons[wCount++] = new Weapon(4, 4, 4, 0, "Sword");
	weapons[wCount++] = new Weapon(5, 1, 6, 0, "Fists");
	weapons[wCount++] = new Weapon(6, 2, 4, 0, "Axe");
	weapons[wCount++] = new Weapon(6, 3, 3, 0, "Spear");
	weapons[wCount++] = new Weapon(4, 1, 7, 0, "Bow");
	weapons[wCount++] = new Weapon(5, 2, 5, 0, "Katana");
	weapons[wCount++] = new Weapon(2, 3, 7, 0, "Staff");
	weapons[wCount++] = new Weapon(7, 4, 1, 0, "Great Sword");
	weapons[wCount++] = new Weapon(8, 2, 2, 0, "Hammer");
	weapons[wCount++] = new Weapon(4, 2, 6, 0, "Dagger");
	armorSets[aCount++] = new Armor(8, 7, 5, 0, "Warrior Armor");
	armorSets[aCount++] = new Armor(5, 3, 12, 0, "Scout Armor");
	armorSets[aCount++] = new Armor(15, 8, -3, 0, "Knight Armor");
	armorSets[aCount++] = new Armor(10, 12, -2, 0, "Executioner's Armor");
	armorSets[aCount++] = new Armor(9, 9, 2, 0, "Samurai Armor");
	armorSets[aCount++] = new Armor(11, 8, 1, 0, "Chainmail Armor");
	armorSets[aCount++] = new Armor(8, 4, 8, 0, "Martial Artist's Armor");
}

//parameterized constructor
Enemy::Enemy(int str, int spe, int def, int health, int stamina, int maxStamina, int crit, 
	int weaponIndex, int armorIndex, int wCount, int aCount, int reward)
{
	this->wCount = wCount;
	this->aCount = aCount;
	this->reward = reward;
}

//getter for wCount
int Enemy::getWCount() const
{
	return wCount;
}

//setter for wCount
void Enemy::setWCount(int wCount)
{
	this->wCount = wCount;
}

//getter for aCount
int Enemy::getACount() const
{
	return aCount;
}

//setter for aCount
void Enemy::setACount(int aCount)
{
	this->aCount = aCount;
}

//setter for weaponIndex
void Enemy::setWeaponIndex()
{
	//sets weaponIndex to a random number between 0 and wCount
	weaponIndex = rand() % getWCount();
}

//setter for armorIndex
void Enemy::setArmorIndex()
{
	//sets armorIndex to a random number between 0 and aCount
	armorIndex = rand() % getACount();
}

//setStats function
void Enemy::setStats()
{
	//runs setWeaponIndex and setArmorIndex
	setWeaponIndex();
	setArmorIndex();
	//creates variables to control loops
	string difficulty = "";
	int strRand = 0;
	int speRand = 0;
	int defRand = 0;
	//prompts user to select difficulty from available options, if the user enters an
	//invalid option, will keep prompting for a new input until it is valid
	cout << "Select difficulty: " << endl;
	cout << "EASY    MEDIUM    HARD    EXTREME" << endl;
	do 
	{
		cin >> difficulty;
		for (int i = 0; i < difficulty.length(); i++)
		{
			difficulty[i] = tolower(difficulty[i]);
		}
	} while (difficulty != "easy" && difficulty != "medium" && difficulty != "hard" && 
		difficulty != "extreme");
	//sets stats to random number between 14 and 17 and reward to a random number between 1 and 15
	if (difficulty == "easy")
	{
		strRand = rand() % 4 + 14;
		speRand = rand() % 4 + 14;
		defRand = rand() % 4 + 14;
		setReward(rand() % 15 + 1);
	}
	//sets stats to random number between 17 and 20 and reward to a random number between 10 and 25
	else if (difficulty == "medium")
	{
		strRand = rand() % 4 + 17;
		speRand = rand() % 4 + 17;
		defRand = rand() % 4 + 17;
		setReward(rand() % 16 + 10);
	}
	//sets stats to random number between 20 and 23 and reward to a random number between 20 and 35
	else if (difficulty == "hard")
	{
		strRand = rand() % 4 + 20;
		speRand = rand() % 4 + 20;
		defRand = rand() % 4 + 20;
		setReward(rand() % 16 + 20);
	}
	//sets stats to 25 and reward to a random number between 30 and 45
	else if (difficulty == "extreme")
	{
		strRand = 25;
		speRand = 25;
		defRand = 25;
		setReward(rand() % 16 + 30);
	}
	//sets stats equal to numbers generated plus stats from weapon and armor
	setStr(strRand + weapons[getWeaponIndex()]->getStr() + armorSets[getArmorIndex()]->getStr());
	setSpe(speRand + weapons[getWeaponIndex()]->getSpe() + armorSets[getArmorIndex()]->getSpe());
	setDef(defRand + weapons[getWeaponIndex()]->getDef() + armorSets[getArmorIndex()]->getDef());
	//sets crit rate equal to 20 if speed is less than 20, other wise sets it equal to
	//the speed minus 20 divided by 2 and then that minus 20 
	if (getSpe() < 20)
	{
		setCrit(20);
	}
	else
	{
		setCrit(20 - ((getSpe() - 20) / 2));
	}
	//sets health equal to 50
	setHealth(50);
	//sets stamina and maxStamina equal to strength plus defense divided by 2, plus 20
	int stam = ((getStr() + getDef()) / 2) + 20;
	setStamina(stam);
	setMaxStamina(stam);
	cout << "" << endl;
}

//showStats function that displays all the enemy's stats, current weapon, and curren armor
void Enemy::showStats()
{
	cout << "Enemy Stats: " << endl;
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

//getter for reward
int Enemy::getReward() const
{
	return reward;
}

//setter for reward
void Enemy::setReward(int reward)
{
	this->reward = reward;
}

