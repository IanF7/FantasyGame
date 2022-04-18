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
	armorSets[aCount++] = new Armor(8, 7, 5, 0, "Warrior_Armor");
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

//compareWName function
bool Player::compareWName(string compare)
{
	//compares the names of every weapon to the input and returns true if any of them match
	bool repeat = false;
	for (int i = 0; i < wCount; i++)
	{
		if (compare == weapons[i]->getWName())
		{
			repeat = true;
		}
	}
	return repeat;
}

//compareAName function
bool Player::compareAName(string compare)
{
	//compares the names of every armor to the input and returns true if any of them match
	bool repeat = false;
	for (int i = 0; i < aCount; i++)
	{
		if (compare == armorSets[i]->getAName())
		{
			repeat = true;
		}
	}
	return repeat;
}

//saveCharacter function
void Player::saveCharacter()
{
	//opens save.txt file
	ofstream saveTo("Save.txt");
	//creates string name for adding _ from names with a space so that load works properly
	string name = "";
	//chekcs if file was loaded properly
	if (!saveTo)
	{
		cout << "File not found" << endl;
		exit(10);
	}
	//outputs gold and wCount to the file
	saveTo << getGold() << endl;
	saveTo << wCount << endl;
	//outputs data of all weapons to file
	for (int i = 0; i < wCount; i++)
	{
		//adds an _ if there are any spaces in wName of given weapon
		name = weapons[i]->getWName();
		for (int j = 0; j < name.length(); j++)
		{
			if (name[j] == ' ')
			{
				name[j] = '_';
			}
		}
		saveTo << weapons[i]->getStr() << " " << weapons[i]->getDef() << " " <<
			weapons[i]->getSpe() << " " << weapons[i]->getCost() << " " << 
			name << endl;
	}
	//outputs aCount to file
	saveTo << aCount << endl;
	//outputs data of all armor to file
	for (int i = 0; i < aCount; i++)
	{
		//adds an _ if there are any spaces in aName of given armor
		name = armorSets[i]->getAName();
		for (int j = 0; j < name.length(); j++)
		{
			if (name[j] == ' ')
			{
				name[j] = '_';
			}
		}
		saveTo << armorSets[i]->getStr() << " " << armorSets[i]->getDef() << " " <<
			armorSets[i]->getSpe() << " " << armorSets[i]->getCost() << " " <<
			name << endl;
	}
	//closes file
	saveTo.close();
}

//loadCharacter function
void Player::loadCharacter()
{
	//opens Save.txt
	ifstream saveFrom("Save.txt");
	//creates integers and strings to store data
	int numInput = 0;
	int strIn, defIn, speIn, costIn = 0;
	string nameInput = "";
	//inputs gold and wCount from file
	saveFrom >> numInput;
	setGold(numInput);
	saveFrom >> numInput;
	setWCount(numInput);
	//inputs stats of all weapons from file
	for (int i = 0; i < wCount; i++)
	{
		saveFrom >> strIn;
		saveFrom >> defIn;
		saveFrom >> speIn;
		saveFrom >> costIn;
		saveFrom >> nameInput;
		//removes _ from weapon name for display
		for (int j = 0; j < nameInput.length(); j++)
		{
			if (nameInput[j] == '_')
			{
				nameInput[j] = ' ';
			}
		}
		//creates new weapon with given data
		weapons[i] = new Weapon(strIn, defIn, speIn, costIn, nameInput);
		
	}
	//inputs aCount from file
	saveFrom >> numInput;
	setACount(numInput);
	//inputs stats of all armor from file
	for (int i = 0; i < aCount; i++)
	{
		saveFrom >> strIn;
		saveFrom >> defIn;
		saveFrom >> speIn;
		saveFrom >> costIn;
		saveFrom >> nameInput;
		//removes _ from armor name for display
		for (int j = 0; j < nameInput.length(); j++)
		{
			if (nameInput[j] == '_')
			{
				nameInput[j] = ' ';
			}
		}
		//creates new armor with given data
		armorSets[i] = new Armor(strIn, defIn, speIn, costIn, nameInput);
	}
	//closes file
	saveFrom.close();
}


