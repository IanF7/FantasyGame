#include <iostream>
#include "Arena.h"

using namespace std;

Arena::Arena() {};

Arena::Arena(Player p1, Enemy e1)
{
	this->p1 = p1;
	this->e1 = e1;
}

void Arena::fight(Player &p1, Enemy &e1)
{
	cout << "BATTLE BEGIN" << endl;
	cout << "" << endl;
	string input = "";
	int damageTo = 0;
	int damageFrom = 0;
	int enemyAttack = 0;
	if (p1.getSpe() > e1.getSpe())
	{
		cout << "You get the first attack!" << endl;
		cout << "" << endl;
		do
		{
			//prints out details and takes in user inputted action
			cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
				<< p1.getStamina() << endl;
			cout << "Enemy Health: " << e1.getHealth() << endl;
			cout << "" << endl;
			cout << "Enter the number of the corresponding action: " << endl;
			cout <<	"Attack(1): 0 Stamina  Strong Attack(2): 10 Stamina  "
				"Block(3): 10 Stamina  Dodge(4): 15 Stamina" << endl;
			cin >> input;
			//checks if stamina allows for inputted action
			if (p1.getStamina() < 15 && input == "4")
			{
				while (input != "1" && input != "2" && input != "3")
				{
					cout << "You don't have enough stamina! Select another action: " << endl;
					cin >> input;
				}
			}
			else if (p1.getStamina() < 10 && (input == "4" || input == "3" || input == "2"))
			{
				while (input != "1")
				{
					cout << "You don't have enough stamina! Select another action: " << endl;
					cin >> input;
				}
			}
			//sets enemy's attack
			enemyAttack = rand() % 9 + 1;
			//checks if enemy's attack allows for action
			if (e1.getStamina() < 10)
			{
				enemyAttack = 1;
			}
			else if (e1.getStamina() < 15)
			{
				enemyAttack = rand() % 8 + 1;
			}
			//checks if user inputted 1 or 2 for an attack
			if (input == "1")
			{
				damageTo = attackP(p1, e1);
				cout << "You attack the enemy" << endl;
			}
			else if (input == "2")
			{
				p1.setStamina(p1.getStamina() - 10);
				damageTo = attackP(p1, e1) + 5;
				cout << "You attack strongly!" << endl;
			}
			//if the damage is less than 5, sets it equal to 5
			if (damageTo < 5)
			{
				damageTo = 5;
			}
			//if enemy's action is defensive, subtracts damage from user's attack
			if (enemyAttack == 8 || enemyAttack == 9)
			{
				cout << "" << endl;
				cout << "Enemy is defending!" << endl;
				e1.setStamina(e1.getStamina() - 10);
				damageTo -= 5;
				damageFrom = 0;
			}
			else if (enemyAttack == 10)
			{
				cout << "" << endl;
				cout << "Enemy dodged attack!" << endl;
				e1.setStamina(e1.getStamina() - 20);
				damageTo = 0;
				damageFrom = 0;
			}
			if (input == "3" || input == "4")
			{
				damageTo = 0;
			}
			//sets enemy health to current health minus damage
			e1.setHealth(e1.getHealth() - damageTo);
			//if the enemy health reaches 0, prints out the following and ends the battle
			if (e1.getHealth() <= 0)
			{
				e1.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
					<< p1.getStamina() << endl;
				cout << "Enemy Health: " << e1.getHealth() << endl;
				cout << "You Win!" << endl;
				p1.setGold(e1.getReward() + p1.getGold());
				cout << "Gold Earned: " << e1.getReward() << "   Total Gold: " <<
					p1.getGold() << endl;
				break;
			}
			cout << "" << endl;
			//if enemy attacks, sets damage
			if (enemyAttack <= 5)
			{
				cout << "Enemy attacks!" << endl;
				damageFrom = attackE(e1, p1);
			}
			else if (enemyAttack == 6 || enemyAttack == 7)
			{
				cout << "Enemy attacks strongly!" << endl;
				damageFrom = attackE(e1, p1) + 5;
				e1.setStamina(e1.getStamina() - 10);
			}
			//if damage is less than 5, sets it equal to 5
			if (damageFrom < 5)
			{
				damageFrom = 5;
			}
			if (enemyAttack >= 8)
			{
				damageFrom = 0;
			}
			//if user's action is defensive, subtracts damage from enemy's attack
			if (input == "3")
			{
				p1.setStamina(p1.getStamina() - 10);
				damageFrom -= 5;
				damageTo = 0;
				cout << "You are defending!" << endl;
			}
			if (input == "4")
			{
				p1.setStamina(p1.getStamina() - 15);
				damageFrom = 0;
				damageTo = 0;
				cout << "Dodged attack!" << endl;
			}
			//sets player health equal to current health minus damage
			p1.setHealth(p1.getHealth() - damageFrom);
			cout << "" << endl;
			//if player health reaches 0, prints out the following and ends the battle
			if (p1.getHealth() <= 0)
			{
				p1.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
					<< p1.getStamina() << endl;
				cout << "Enemy Health: " << e1.getHealth() << endl;
				cout << "You Lost!" << endl;
				break;
			}
			if (p1.getStamina() <= (p1.getMaxStamina() - 3))
			{
				cout << "Recovered 5 stamina" << endl;
				p1.setStamina(p1.getStamina() + 3);
			}
			if (e1.getStamina() <= (e1.getMaxStamina() - 3))
			{
				e1.setStamina(p1.getStamina() + 3);
			}
		} 
		while (p1.getHealth() >= 0 && e1.getHealth() >= 0);
	}
	else
	{
	cout << "Enemy gets the first attack!" << endl;
	cout << "" << endl;
		do
		{
			//prints out details and takes in user inputted action
			cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
				<< p1.getStamina() << endl;
			cout << "Enemy Health: " << e1.getHealth() << endl;
			cout << "" << endl;
			cout << "Enter the number of the corresponding action: " << endl;
			cout << "Attack(1): 0 Stamina  Strong Attack(2): 10 Stamina  "
				"Block(3): 10 Stamina  Dodge(4): 20 Stamina" << endl;
			cin >> input;
			//checks if stamina allows for inputted action
			if (p1.getStamina() < 15 && input == "4")
			{
				while (input != "1" && input != "2" && input != "3")
				{
					cout << "You don't have enough stamina! Select another action: " << endl;
					cin >> input;
				}
			}
			else if (p1.getStamina() < 10 && (input == "4" || input == "3" || input == "2"))
			{
				while (input != "1")
				{
					cout << "You don't have enough stamina! Select another action: " << endl;
					cin >> input;
				}
			}
			//sets enemy attck
			enemyAttack = rand() % 9 + 1;
			//checks if enemy's stamina allows for action
			if (e1.getStamina() < 10)
			{
				enemyAttack = 1;
			}
			else if (e1.getStamina() < 15)
			{
				enemyAttack = rand() % 8 + 1;
			}
			cout << "" << endl;
			//if enemy attcks, sets damage
			if (enemyAttack <= 5)
			{
				cout << "Enemy attacks!" << endl;
				damageFrom = attackE(e1, p1);
			}
			else if (enemyAttack == 6 || enemyAttack == 7)
			{
				cout << "Enemy attacks strongly!" << endl;
				damageFrom = attackE(e1, p1) + 5;
				e1.setStamina(e1.getStamina() - 10);
			}
			//if the damage is less than 5, sets it equal to 5
			if (damageFrom < 5)
			{
				damageFrom = 5;
			}
			if (enemyAttack >= 8)
			{
				damageFrom = 0;
			}
			//if user's action is defensive, subtracts damage from enemy's attack
			if (input == "3")
			{
				p1.setStamina(p1.getStamina() - 10);
				damageFrom -= 5;
				damageTo = 0;
				cout << "You are defending!" << endl;
			}
			if (input == "4")
			{
				p1.setStamina(p1.getStamina() - 15);
				damageFrom = 0;
				damageTo = 0;
				cout << "You dodged the attack" << endl;
			}
			//sets player health equal to current health minus damage
			p1.setHealth(p1.getHealth() - damageFrom);
			cout << "" << endl;
			//if player health reaches 0, prints out the following and ends the battle
			if (p1.getHealth() <= 0)
			{
				p1.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
					<< p1.getStamina() << endl;
				cout << "Enemy Health: " << e1.getHealth() << endl;
				cout << "You Lost!" << endl;
				break;
			}
			//if player attacks, sets damage
			if (input == "1")
			{
				damageTo = attackP(p1, e1);
				cout << "You attack the enemy!" << endl;
			}
			else if (input == "2")
			{
				p1.setStamina(p1.getStamina() - 10);
				damageTo = attackP(p1, e1) + 5;
				cout << "You attack the enemy strongly!" << endl;
			}
			//if damage is less than 5, sets damage equal to 5
			if (damageTo < 5)
			{
				damageTo = 5;
			}
			if (input == "3" || input == "4")
			{
				damageFrom = 0;
			}
			//if enemy's action is defensive, subtracts damage from user's attack
			if (enemyAttack == 8 || enemyAttack == 9)
			{
				cout << "Enemy is defending!" << endl;
				e1.setStamina(e1.getStamina() - 10);
				damageTo -= 5;
				damageFrom = 0;
			}
			else if (enemyAttack == 10)
			{
				cout << "Enemy dodged attack!" << endl;
				e1.setStamina(e1.getStamina() - 15);
				damageTo = 0;
				damageFrom = 0;
			}
			//sets enemy health equal to current health minus damage
			e1.setHealth(e1.getHealth() - damageTo);
			//if the enemy health reaches 0, prints out the following and ends the battle
			if (e1.getHealth() <= 0)
			{
				e1.setHealth(0);
				cout << "" << endl;
				cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
					<< p1.getStamina() << endl;
				cout << "Enemy Health: " << e1.getHealth() << endl;
				cout << "You Win!" << endl;
				p1.setGold(e1.getReward() + p1.getGold());
				cout << "Gold Earned: " << e1.getReward() << "   Total Gold: " <<
					p1.getGold() << endl;
				break;
			}
			if (p1.getStamina() <= (p1.getMaxStamina() - 3))
			{
				cout << "Recovered 5 stamina" << endl;
				p1.setStamina(p1.getStamina() + 3);
			}
			if (e1.getStamina() <= (e1.getMaxStamina() - 3))
			{
				e1.setStamina(p1.getStamina() + 3);
			}
		}
		while (p1.getHealth() >= 0 && e1.getHealth() >= 0);
	}
}

void Arena::bossFight(Player& p1, Dragon& d1)
{
	string input = "";
	int dragonAttack = rand() % 6 + 1;
	int damageTo = 0;
	int damageFrom = 0;
	cout << "Dragon Battle, START!" << endl;
	do {
		//prints out details and takes in user inputted action
		cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
			<< p1.getStamina() << endl;
		cout << "Dragon Health: " << d1.getHealth() << endl;
		cout << "" << endl;
		cout << "Enter the number of the corresponding action: " << endl;
		cout << "Attack(1): 0 Stamina  Strong Attack(2): 10 Stamina  "
			"Block(3): 10 Stamina  Dodge(4): 15 Stamina" << endl;
		cin >> input;
		//checks if stamina allows for inputted action
		if (p1.getStamina() <= 10 && input == "4")
		{
			while (input != "1" && input != "2" && input != "3")
			{
				cout << "You don't have enough stamina! Select another action: " << endl;
				cin >> input;
			}
		}
		else if (p1.getStamina() < 10 && (input == "4" || input == "3" || input == "2"))
		{
			while (input != "1")
			{
				cout << "You don't have enough stamina! Select another action: " << endl;
				cin >> input;
			}
		}
		//checks if user inputted 1 or 2 for an attack
		if (input == "1")
		{
			damageTo = pAttackD(p1, d1);
			cout << "You attack the dragon!" << endl;
		}
		else if (input == "2")
		{
			p1.setStamina(p1.getStamina() - 10);
			damageTo = pAttackD(p1, d1) + 5;
			cout << "You attack the dragon strongly!" << endl;
		}
		//if the damage is less than 5, sets it equal to 5
		if (damageTo < 5)
		{
			damageTo = 5;
		}
		if (input == "3" || input == "4")
		{
			damageTo = 0;
		}
		d1.setHealth(d1.getHealth() - damageTo);
		if (d1.getHealth() <= 0)
		{
			d1.setHealth(0);
			cout << "" << endl;
			cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
				<< p1.getStamina() << endl;
			cout << "Boss Health: " << d1.getHealth() << endl;
			cout << "You Win!" << endl;
			p1.setGold(d1.getReward() + p1.getGold());
			cout << "Gold Earned: " << d1.getReward() << "   Total Gold: " <<
				p1.getGold() << endl;
			break;
		}
		if (dragonAttack <= 4)
		{
			cout << "The dragon is waiting to see what you will do..." << endl;
		}
		else if (dragonAttack == 5 || dragonAttack == 6)
		{
			cout << "The dragon attacks you with it's claws!" << endl;
			damageFrom = 7;
		}
		else if (dragonAttack == 7)
		{
			cout << "The dragon attacks you with it's fire breath!" << endl;
			damageFrom = 15;
		}
		//if user's action is defensive, subtracts damage from enemy's attack
		if (input == "3")
		{
			p1.setStamina(p1.getStamina() - 10);
			damageFrom -= 5;
			damageTo = 0;
			cout << "You are defending!" << endl;
		}
		if (input == "4")
		{
			p1.setStamina(p1.getStamina() - 15);
			damageFrom = 0;
			damageTo = 0;
			cout << "You dodged the attack!" << endl;
		}
		if (p1.getStamina() <= 45)
		{
			cout << "Recovered 5 stamina" << endl;
			p1.setStamina(p1.getStamina() + 5);
		}
		if (e1.getStamina() <= 45)
		{
			e1.setStamina(p1.getStamina() + 5);
		}
		p1.setHealth(p1.getHealth() - damageFrom);
		if (p1.getHealth() <= 0)
		{
			p1.setHealth(0);
			cout << "" << endl;
			cout << "Your Health: " << p1.getHealth() << " Your Stamina: "
				<< p1.getStamina() << endl;
			cout << "Boss Health: " << d1.getHealth() << endl;
			cout << "You Lose" << endl;
			break;
		}
	} while (d1.getHealth() >= 0 && p1.getHealth() >= 0);
}

int Arena::attackP(Player &p1, Enemy &e1)
{
	int crit = rand() % (p1.getCrit() - 1) + 1;
	int damage = p1.getStr() - e1.getDef();
	if (damage < 5)
	{
		damage = 5;
	}
	if (crit == 1)
	{
		damage += 10;
		cout << "CRITICAL HIT!" << endl;
	}
	return damage;
}

int Arena::attackE(Enemy &e1, Player &p1)
{
	int crit = rand() % (e1.getCrit() - 1)+ 1;
	int damage = e1.getStr() - p1.getDef();
	if (damage < 5)
	{
		damage = 5;
	}
	if (crit == 1)
	{
		damage += 10;
		cout << "CRITICAL HIT!" << endl;
	}
	return damage;
}

int Arena::pAttackD(Player& p1, Dragon& d1)
{
	int crit = rand() % (p1.getCrit() - 1) + 1;
	int damage = (p1.getStr() - 20);
	cout << damage << endl;
	if (crit == p1.getCrit())
	{
		damage += 10;
	}
	return damage;
}




