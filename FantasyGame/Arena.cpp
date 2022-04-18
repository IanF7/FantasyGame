#include <iostream>
#include "Arena.h"

using namespace std;

//default constructor
Arena::Arena() 
{
	//sets player and enemy damage to 0
	playerDamage = 0;
	enemyDamage = 0;
}

//parameterized constructor
Arena::Arena(int playerDamage, int enemyDamage)
{
	this->playerDamage = playerDamage;
	this->enemyDamage = enemyDamage;
}

//battle function given a player object and an enemy object
void Arena::battle(Player player, Enemy enemy)
{
	//creates variables to control loops and for damage
	int input = 0;
	int damageP = 0;
	int damageE = 0;
	bool pFasterE = false;
	//sets and displays the stats for the player and enemy
	player.setStats();
	cout << "" << endl;
	enemy.setStats();
	player.showStats();
	enemy.showStats();
	//prints out that the battle has started and the player and enemy's health
	cout << "BATTLE BEGIN!" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Your Health: " << player.getHealth() << " Your Stamina: "
		<< player.getStamina() << endl;
	cout << "Enemy Health: " << enemy.getHealth() << endl;
	//compares speeds to determine who goes first and displays proper message and
	//sets pFasterE to given value
	if (player.getSpe() >= enemy.getSpe())
	{
		cout << "You get the first attack!" << endl;
		pFasterE = true;
	}
	else
	{
		cout << "Enemy gets the first attack!" << endl;
		pFasterE = false;
	}
	cout << "" << endl;
	//runs while both the player and enemy have more than 0 health
	do
	{
		//runs setPlayerDamage and setEnemyDamage
		setPlayerDamage(player, enemy);
		setEnemyDamage(enemy, player);
		//prompts uer to make an action and if invalid number is enter, will prompt user
		//to enter number until it is valid
		cout << "Enter the number of the corresponding action: " << endl;
		cout << "Attack(1): 0 Stamina  Strong Attack(2): 10 Stamina  "
			"Block(3): 10 Stamina  Dodge(4): 15 Stamina" << endl;
		cin >> input;
		if (input < 1 || input > 4)
		{
			do 
			{
				cout << "Please enter a valid number: " << endl;
				cin >> input;
			} while (input < 1 || input > 4);
		}
		//checks if stamina allows for inputted action
		if (player.getStamina() < 15 && input == 4)
		{
			while (input != 1 && input != 2 && input != 4)
			{
				cout << "You don't have enough stamina! Select another action: " << endl;
				cin >> input;
			}
		}
		else if (player.getStamina() < 10 && (input == 4 || input == 3 || input == 2))
		{
			while (input != 1)
			{
				cout << "You don't have enough stamina! Select another action: " << endl;
				cin >> input;
			}
		}
		//sets enemy attack equal to a random number between 1 and 10
		int enemyAttack = rand() % 10 + 1;
		//checks to see if stamina allows for action
		if (enemy.getStamina() < 10)
		{
			enemyAttack = 1;
		}
		else if (enemy.getStamina() < 15)
		{
			enemyAttack = rand() % 8 + 1;
		}
		cout << "" << endl;
		//player's turn if offencive action is selected
		if (input == 1)
		{
			cout << "You attack the enemy!" << endl;
			damageP = getPlayerDamage();
			damageP += checkCrit(player.getCrit());
		}
		else if (input == 2)
		{
			cout << "You strongly attack the enemy!" << endl;
			damageP = getPlayerDamage() + 5;
			damageP += checkCrit(player.getCrit());
			player.setStamina(player.getStamina() - 10);
		}
		//enemy's turn if offencive action in generated
		if (enemyAttack < 6)
		{
			cout << "The enemy attacks!" << endl;
			damageE += checkCrit(enemy.getCrit());
			damageE = getEnemyDamage();
		}
		else if (enemyAttack == 6 || enemyAttack == 7)
		{
			cout << "The enemy attacks you strongly!" << endl;
			damageE = getEnemyDamage() + 5;
			damageE += checkCrit(enemy.getCrit());
			enemy.setStamina(enemy.getStamina() - 10);
		}
		//player's turn if defensive action is selected
		if (input == 3)
		{
			cout << "You enter a defensive stance!" << endl;
			damageE = getEnemyDamage() - 5;
			if (damageE < 0)
			{
				damageE = 0;
			}
			damageP = 0;
			player.setStamina(player.getStamina() - 10);
		}
		else if (input == 4)
		{
			cout << "You dodge the enemy!" << endl;
			damageE = 0;
			damageP = 0;
			player.setStamina(player.getStamina() - 15);
		}
		//enemy's turn if defensive action is generated
		if (enemyAttack == 8 || enemyAttack == 9)
		{
			cout << "The enemy enters a defensive stance!" << endl;
			damageP = getPlayerDamage() - 5;
			if (damageP < 0)
			{
				damageP = 0;
			}
			damageE = 0;
			enemy.setStamina(enemy.getStamina() - 10);
		}
		else if (enemyAttack == 10)
		{
			cout << "The enemy dodges!" << endl;
			damageP = 0;
			damageE = 0;
			enemy.setStamina(enemy.getStamina() - 15);
		}
		//checks status of pFasterE and will give enemy damage first if pFasterE is true
		//and player damage first if it is false
		if (pFasterE)
		{
			//sets enemy health and checks if it equals 0 and displays results if so
			enemy.setHealth(enemy.getHealth() - damageP);
			if (enemy.getHealth() <= 0)
			{
				enemy.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "" << endl;
				cout << "You Win!" << endl;
				player.setGold(enemy.getReward() + player.getGold());
				cout << "Gold Earned: " << enemy.getReward() << "   Total Gold: " <<
					player.getGold() << endl;
				break;
			}
			//sets player health and checks if it equals 0 and displays results if so
			player.setHealth(player.getHealth() - damageE);
			if (player.getHealth() <= 0)
			{
				player.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "" << endl;
				cout << "You Lost!" << endl;
				break;
			}
		}
		else
		{
			//sets player health and checks if it equals 0 and displays results if so
			player.setHealth(player.getHealth() - damageE);
			if (player.getHealth() <= 0)
			{
				player.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "" << endl;
				cout << "You Lost!" << endl;
				break;
			}
			//sets enemy health and checks if it equals 0 and displays results if so
			enemy.setHealth(enemy.getHealth() - damageP);
			if (enemy.getHealth() <= 0)
			{
				enemy.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "" << endl;
				cout << "You Win!" << endl;
				player.setGold(enemy.getReward() + player.getGold());
				cout << "Gold Earned: " << enemy.getReward() << "   Total Gold: " <<
					player.getGold() << endl;
				break;
			}
		}
		//recovers stamina by 3 if the current stamina is less than the maxStamina - 3
		if (player.getStamina() <= player.getMaxStamina() - 3)
		{
			player.setStamina(player.getStamina() + 3);
		}
		if (enemy.getStamina() <= enemy.getMaxStamina() - 3)
		{
			enemy.setStamina(enemy.getStamina() + 3);
		}
		//prints out current health for you and the enemy
		cout << "" << endl;
		cout << "Your Health: " << player.getHealth() << " Your Stamina: "
			<< player.getStamina() << endl;
		cout << "Enemy Health: " << enemy.getHealth() << endl;
		cout << "" << endl;
	} while (player.getHealth() >= 0 && enemy.getHealth() >= 0);
}

//boss battle function given a player object and a dragon object
void Arena::bossBattle(Player player, Dragon dragon)
{
	//creates variables to control loops and for damage
	int input = 0;
	int damageP = 0;
	int damageE = 0;
	//sets the stats for the player and dragon and shows the player's stats
	player.setStats();
	dragon.setStats();
	player.showStats();
	//prompts uer to make an action and if invalid number is enter, will prompt user
		//to enter number until it is valid
	cout << "BATTLE BEGIN!" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Your Health: " << player.getHealth() << " Your Stamina: "
		<< player.getStamina() << endl;
	cout << "Enemy Health: " << dragon.getHealth() << endl;
	cout << "" << endl;
	//runs while both player and dragon health are greater than 0
	do
	{
		//sets the player's damage
		setPlayerDamage(player, dragon);
		//prompts uer to make an action and if invalid number is enter, will prompt user
		//to enter number until it is valid
		cout << "Enter the number of the corresponding action: " << endl;
		cout << "Attack(1): 0 Stamina  Strong Attack(2): 10 Stamina  "
			"Block(3): 10 Stamina  Dodge(4): 15 Stamina" << endl;
		cin >> input;
		if (input < 1 || input > 4)
		{
			do
			{
				cout << "Please enter a valid number: " << endl;
				cin >> input;
			} while (input < 1 || input > 4);
		}
		//checks if stamina allows for inputted action
		if (player.getStamina() < 15 && input == 4)
		{
			while (input != 1 && input != 2 && input != 3)
			{
				cout << "You don't have enough stamina! Select another action: " << endl;
				cin >> input;
			}
		}
		else if (player.getStamina() < 10 && (input == 4 || input == 3 || input == 2))
		{
			while (input != 1)
			{
				cout << "You don't have enough stamina! Select another action: " << endl;
				cin >> input;
			}
		}
		cout << "" << endl;
		//sets enemyAttack equal to a random number between 1 and 7
		int enemyAttack = rand() % 7 + 1;
		//player's turn if offencive action is selected
		if (input == 1)
		{
			cout << "You attack the enemy!" << endl;
			damageP = getPlayerDamage();
			damageP += checkCrit(player.getCrit());
		}
		else if (input == 2)
		{
			cout << "You strongly attack the enemy!" << endl;
			damageP = getPlayerDamage() + 5;
			damageP += checkCrit(player.getCrit());
			player.setStamina(player.getStamina() - 10);
		}
		//dragon's turn
		if (enemyAttack < 5)
		{
			cout << "The dragon waits to see what you will do..." << endl;
			damageE = 0;
		}
		else if (enemyAttack == 5 || enemyAttack == 6)
		{
			cout << "The dragon attacks you with its claws!" << endl;
			damageE = 7;
		}
		else if (enemyAttack == 7)
		{
			cout << "The dragon attacks with its fire!" << endl;
			damageE = 15;
		}
		//player's turn if defensive action is selected
		if (input == 3)
		{
			cout << "You enter a defensive stance!" << endl;
			damageE -= 5;
			damageP = 0;
			player.setStamina(player.getStamina() - 10);
		}
		else if (input == 4)
		{
			cout << "You dodge the enemy!" << endl;
			damageE = 0;
			damageP = 0;
			player.setStamina(player.getStamina() - 15);
		}
		//sets enemy health and checks if it equals 0 and displays results if so
		dragon.setHealth(dragon.getHealth() - damageP);
		if (dragon.getHealth() <= 0)
		{
			dragon.setHealth(0);
			cout << "" << endl;
			cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
			cout << "Enemy Health: " << dragon.getHealth() << endl;
			cout << "" << endl;
			cout << "You Win!" << endl;
			player.setGold(dragon.getReward() + player.getGold());
			cout << "Gold Earned: " << dragon.getReward() << "   Total Gold: " <<
				player.getGold() << endl;
			break;
		}
		//sets player health and checks if it equals 0 and displays results if so
		player.setHealth(player.getHealth() - damageE);
		if (player.getHealth() <= 0)
		{
			player.setHealth(0);
			cout << "" << endl;
			cout << "Your Health: " << player.getHealth() << " Your Stamina: "
				<< player.getStamina() << endl;
			cout << "Enemy Health: " << dragon.getHealth() << endl;
			cout << "" << endl;
			cout << "You Lost!" << endl;
			break;
		}
		//recovers stamina
		if (player.getStamina() <= player.getMaxStamina() - 3)
		{
			player.setStamina(player.getStamina() + 3);
		}
		//prints out current health for you and the enemy
		cout << "" << endl;
		cout << "Your Health: " << player.getHealth() << " Your Stamina: "
			<< player.getStamina() << endl;
		cout << "Enemy Health: " << dragon.getHealth() << endl;
		cout << "" << endl;
	} while (player.getHealth() >= 0 && dragon.getHealth() >= 0);
}

//setPlayerDamage function
void Arena::setPlayerDamage(Player player, Enemy enemy)
{
	//sets the player's damage equal to their strength minus the enemy's defense and sets it
	//equal to 3 if its less than 3
	playerDamage = player.getStr() - enemy.getDef();
	if (playerDamage < 3)
	{
		playerDamage = 3;
	}
}

//getter for playerDamage
int Arena::getPlayerDamage() const
{
	return playerDamage;
}

//setEnemyDamage function
void Arena::setEnemyDamage(Enemy enemy, Player player)
{
	//sets the enemy's damage equal to their strength minus the player's defense and sets it
	//equal to 3 if its less than 3
	enemyDamage = enemy.getStr() - player.getDef();
	if (enemyDamage < 3)
	{
		enemyDamage = 3;
	}
}

//getter for enemyDamage
int Arena::getEnemyDamage() const
{
	return enemyDamage;
}

int Arena::checkCrit(int c)
{
	int critDamage = 0;
	critDamage = rand() % (c + 1) + 1;
	if (critDamage == 1)
	{
		cout << "CRITICAL HIT!" << endl;
		critDamage = 10;
	}
	return critDamage;
}






