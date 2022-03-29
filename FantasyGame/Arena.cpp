#include <iostream>
#include "Arena.h"

using namespace std;

Arena::Arena() {};

Arena::Arena(Character player, Character enemy)
{
	this->player = player;
	this->enemy = enemy;
}

void Arena::fight(Character &player, Character &enemy)
{
	string input = "";
	if (player.getSpe() > enemy.getSpe())
	{
		do
		{
			cout << "Your Turn: " << endl;
			attackP(player, enemy);
			if (player.getHealth() <= 0)
			{
				break;
			}
			else if (enemy.getHealth() <= 0)
			{
				break;
			}
			cout << "Enemy turn: " << endl;
			attackE(enemy, player);
			if (player.getHealth() <= 0)
			{
				break;
			}
			else if (enemy.getHealth() <= 0)
			{
				break;
			}
			cout << "Go to next turn? ";
			cin >> input;
			for (int i = 0; i < input.length(); i++)
			{
				input[i] = tolower(input[i]);
			}
			if (input != "yes")
			{
				break;
			}
			if (player.getHealth() <= 0)
			{
				break;
			}
			else if (enemy.getHealth() <= 0)
			{
				break;
			}
		} 
		while (player.getHealth() >= 0 && enemy.getHealth() >= 0);
	}
	else
	{
		do
		{
			cout << "Enemy turn: " << endl;
			attackE(enemy, player);
			if (player.getHealth() <= 0)
			{
				break;
			}
			else if (enemy.getHealth() <= 0)
			{
				break;
			}
			cout << "Your Turn: " << endl;
			attackP(player, enemy);
			if (player.getHealth() <= 0)
			{
				break;
			}
			else if (enemy.getHealth() <= 0)
			{
				break;
			}
			cout << "Go to next turn? ";
			cin >> input;
			for (int i = 0; i < input.length(); i++)
			{
				input[i] = tolower(input[i]);
			}
			if (input != "yes")
			{
				break;
			}
		}
		while (player.getHealth() >= 0 && enemy.getHealth() >= 0);
	}
}

void Arena::attackP(Character &player, Character &enemy)
{
	int health = enemy.getHealth();
	int crit = rand() % 20 + 1;
	int damage = player.getStr() - enemy.getDef();
	if (damage < 5)
	{
		damage = 5;
	}
	if (crit == 20)
	{
		damage += 10;
		cout << "CRITICAL HIT!" << endl;
	}
	health = health - damage;
	if (health < 0)
	{
		health = 0;
		cout << "" << endl;
		cout << "Player Wins" << endl;
	}
	enemy.setHealth(health);
	cout << "Your Health: " << player.getHealth() << "     ";
	cout << "Enemy Health: " << enemy.getHealth() << endl;
}

void Arena::attackE(Character &enemy, Character &player)
{
	int health = player.getHealth();
	int crit = rand() % 20 + 1;
	int damage = enemy.getStr() - player.getDef();
	if (damage < 5)
	{
		damage = 5;
	}
	if (crit == 20)
	{
		damage += 10;
		cout << "CRITICAL HIT!" << endl;
	}
	health = health - damage;
	if (health < 0)
	{
		health = 0;
		cout << "" << endl;
		cout << "Enemy Wins" << endl;
	}
	player.setHealth(health);
	cout << "Your Health: " << player.getHealth() << "     ";
	cout << "Enemy Health: " << enemy.getHealth() << endl;
}

