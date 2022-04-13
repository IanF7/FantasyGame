#include "Dragon.h"

//default constructor
Dragon::Dragon() {}

//parameterized constructor
Dragon::Dragon(int str, int spe, int def, int health, int stamina, int crit, 
	int weaponIndex, int armorIndex, int wCount, int aCount) {}

//setStats function
void Dragon::setStats()
{
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
	//sets health equal to 70 and reward eqaul to 100
	if (difficulty == "easy")
	{
		setHealth(70);
		setReward(100);
	}
	//sets health equal to 80 and reward eqaul to 120
	else if (difficulty == "medium")
	{
		setHealth(80);
		setReward(120);
	}
	//sets health equal to 90 and reward eqaul to 140
	else if (difficulty == "hard")
	{
		setHealth(90);
		setReward(140);
	}
	//sets health equal to 100 and reward eqaul to 160
	else if (difficulty == "extreme")
	{
		setHealth(100);
		setReward(160);
	}
	//sets crit equal to 20 and all other stats to 0
	setCrit(20);
	setStr(0);
	setDef(0);
	setSpe(0);
	setStamina(0);
	cout << "" << endl;
}


