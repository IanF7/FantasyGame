#include "Enemy.h"
#include <ctime>

Enemy::Enemy()
{
	srand(time(NULL));
	wCount = aCount = 0;
	reward = 0;
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

Enemy::Enemy(int str, int spe, int def, int health, int stamina, int maxStamina, int crit, 
	int weaponIndex, int armorIndex, int wCount, int aCount, int reward)
{
	this->wCount = wCount;
	this->aCount = aCount;
	this->reward = reward;
}

int Enemy::getWCount() const
{
	return wCount;
}

void Enemy::setWCount(int wCount)
{
	this->wCount = wCount;
}

int Enemy::getACount() const
{
	return aCount;
}

void Enemy::setACount(int aCount)
{
	this->aCount = aCount;
}

void Enemy::setWeaponIndex()
{
	weaponIndex = rand() % getWCount();
}

void Enemy::setArmorIndex()
{
	armorIndex = rand() % getACount();
}

void Enemy::setStats()
{
	setWeaponIndex();
	setArmorIndex();
	string difficulty = "";
	int strRand = 0;
	int speRand = 0;
	int defRand = 0;
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
	if (difficulty == "easy")
	{
		strRand = rand() % 2 + 14;
		speRand = rand() % 2 + 14;
		defRand = rand() % 2 + 14;
		setReward(rand() % 14 + 1);
	}
	else if (difficulty == "medium")
	{
		strRand = rand() % 2 + 17;
		speRand = rand() % 2 + 17;
		defRand = rand() % 2 + 17;
		setReward(rand() % 15 + 15);
	}
	else if (difficulty == "hard")
	{
		strRand = rand() % 2 + 20;
		speRand = rand() % 2 + 20;
		defRand = rand() % 2 + 20;
		setReward(rand() % 15 + 30);
	}
	else if (difficulty == "extreme")
	{
		strRand = 25;
		speRand = 25;
		defRand = 25;
		setReward(rand() % 15 + 45);
	}
	setStr(strRand + weapons[getWeaponIndex()]->getStr() + armorSets[getArmorIndex()]->getStr());
	setSpe(speRand + weapons[getWeaponIndex()]->getSpe() + armorSets[getArmorIndex()]->getSpe());
	setDef(defRand + weapons[getWeaponIndex()]->getDef() + armorSets[getArmorIndex()]->getDef());
	if (getSpe() < 20)
	{
		setCrit(20);
	}
	else
	{
		setCrit(20 - ((20 - getSpe()) / 2));
	}
	setHealth(50);
	int stam = ((getStr() + getDef()) / 2) + 20;
	setStamina(stam);
	setMaxStamina(stam);
	cout << "" << endl;
}

void Enemy::showStats()
{
	cout << "Enemy Stats: " << endl;
	cout << "     Weapon: " << weapons[getWeaponIndex()]->getWName() << endl;
	cout << "     Armor: " << armorSets[getArmorIndex()]->getAName() << endl;
	cout << "     Health: " << getHealth() << endl;
	cout << "     Str: " << getStr() << endl;
	cout << "     Def: " << getDef() << endl;
	cout << "     Spe: " << getSpe() << endl;
	cout << "     Stamina: " << getMaxStamina() << endl;
	cout << "" << endl;
}

int Enemy::getReward() const
{
	return reward;
}

void Enemy::setReward(int reward)
{
	this->reward = reward;
}

