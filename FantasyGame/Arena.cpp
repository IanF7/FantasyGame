#include <iostream>
#include "Arena.h"

using namespace std;


Arena::Arena() 
{
	playerDamage = 0;
	enemyDamage = 0;
}

Arena::Arena(int playerDamage, int enemyDamage)
{
	this->playerDamage = playerDamage;
	this->enemyDamage = enemyDamage;
}

void Arena::battle(Player player, Enemy enemy)
{
	int input = 0;
	int damageP = 0;
	int damageE = 0;
	int enemyAttack = rand() % 9 + 1;
	bool pFasterE = false;
	player.setStats();
	enemy.setStats();
	player.showStats();
	enemy.showStats();
	cout << "BATTLE BEGIN!" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Your Health: " << player.getHealth() << " Your Stamina: "
		<< player.getStamina() << endl;
	cout << "Enemy Health: " << enemy.getHealth() << endl;
	//add check for speed here
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
	do
	{
		setPlayerDamage(player, enemy);
		setEnemyDamage(enemy, player);
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
		if (enemy.getStamina() < 10)
		{
			enemyAttack = 1;
		}
		else if (enemy.getStamina() < 15)
		{
			enemyAttack = rand() % 8 + 1;
		}
		cout << "" << endl;
		//player's turn if offence
		if (input == 1)
		{
			cout << "You attack the enemy!" << endl;
			damageP = getPlayerDamage();
		}
		else if (input == 2)
		{
			cout << "You strongly attack the enemy!" << endl;
			damageP = getPlayerDamage() + 5;
			player.setStamina(player.getStamina() - 10);
		}
		//enemy's turn if offence
		if (enemyAttack < 6)
		{
			cout << "The enemy attacks!" << endl;
			damageE = getEnemyDamage();
		}
		else if (enemyAttack == 6 || enemyAttack == 7)
		{
			cout << "The enemy attacks you strongly!" << endl;
			damageE = getEnemyDamage() + 5;
			enemy.setStamina(enemy.getStamina() - 10);
		}
		//player's turn if defensive
		if (input == 3)
		{
			cout << "You enter a defensive stance!" << endl;
			damageE = getEnemyDamage() - 5;
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
		//enemy's turn if defensive
		if (enemyAttack == 8 || enemyAttack == 9)
		{
			cout << "The enemy enters a defensive stance!" << endl;
			damageP = getPlayerDamage() - 5;
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
		if (pFasterE)
		{
			//sets enemy health and checks if it equals 0
			enemy.setHealth(enemy.getHealth() - damageP);
			if (enemy.getHealth() <= 0)
			{
				enemy.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "You Win!" << endl;
				player.setGold(enemy.getReward() + player.getGold());
				cout << "Gold Earned: " << enemy.getReward() << "   Total Gold: " <<
					player.getGold() << endl;
				break;
			}
			//sets player health and checks if it equals 0
			player.setHealth(player.getHealth() - damageE);
			if (player.getHealth() <= 0)
			{
				player.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "You Lost!" << endl;
				break;
			}
		}
		else
		{
			//sets player health and checks if it equals 0
			player.setHealth(player.getHealth() - damageE);
			if (player.getHealth() <= 0)
			{
				player.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "You Lost!" << endl;
				break;
			}
			//sets enemy health and checks if it equals 0
			enemy.setHealth(enemy.getHealth() - damageP);
			if (enemy.getHealth() <= 0)
			{
				enemy.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
				cout << "Enemy Health: " << enemy.getHealth() << endl;
				cout << "You Win!" << endl;
				player.setGold(enemy.getReward() + player.getGold());
				cout << "Gold Earned: " << enemy.getReward() << "   Total Gold: " <<
					player.getGold() << endl;
				break;
			}
		}
		//recovers stamina
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

void Arena::bossBattle(Player player, Dragon dragon)
{
	int input = 0;
	int damageP = 0;
	int damageE = 0;
	int enemyAttack = rand() % 6 + 1;
	player.setStats();
	dragon.setStats();
	cout << "BATTLE BEGIN!" << endl;
	cout << "" << endl;
	cout << "" << endl;
	cout << "Your Health: " << player.getHealth() << " Your Stamina: "
		<< player.getStamina() << endl;
	cout << "Enemy Health: " << dragon.getHealth() << endl;
	//add check for speed here
	cout << "" << endl;
	do
	{
		setPlayerDamage(player, dragon);
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
		//player's turn if offence
		if (input == 1)
		{
			cout << "You attack the enemy!" << endl;
			damageP = getPlayerDamage();
		}
		else if (input == 2)
		{
			cout << "You strongly attack the enemy!" << endl;
			damageP = getPlayerDamage() + 5;
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
		//player's turn if defensive
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
		//sets enemy health and checks if it equals 0
		dragon.setHealth(dragon.getHealth() - damageP);
		if (dragon.getHealth() <= 0)
		{
			dragon.setHealth(0);
			cout << "" << endl;
			cout << "Your Health: " << player.getHealth() << " Your Stamina: "
					<< player.getStamina() << endl;
			cout << "Enemy Health: " << dragon.getHealth() << endl;
			cout << "You Win!" << endl;
			player.setGold(dragon.getReward() + player.getGold());
			cout << "Gold Earned: " << dragon.getReward() << "   Total Gold: " <<
				player.getGold() << endl;
			break;
		}
		//sets player health and checks if it equals 0
		player.setHealth(player.getHealth() - damageE);
		if (player.getHealth() <= 0)
		{
			player.setHealth(0);
			cout << "" << endl;
			cout << "Your Health: " << player.getHealth() << " Your Stamina: "
				<< player.getStamina() << endl;
			cout << "Enemy Health: " << dragon.getHealth() << endl;
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

void Arena::setPlayerDamage(Player player, Enemy enemy)
{
	playerDamage = player.getStr() - enemy.getDef();
	if (playerDamage < 3)
	{
		playerDamage = 3;
	}
}

int Arena::getPlayerDamage() const
{
	return playerDamage;
}

void Arena::setEnemyDamage(Enemy enemy, Player player)
{
	enemyDamage = enemy.getStr() - player.getDef();
	if (enemyDamage < 3)
	{
		enemyDamage = 3;
	}
}

int Arena::getEnemyDamage() const
{
	return enemyDamage;
}






