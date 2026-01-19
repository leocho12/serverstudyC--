#include<iostream>
using namespace std;

//Text RPG

enum PlayerType {
	KNIGHT = 1,
	ARCHER = 2,
	MAGE = 3
};

enum MonsterType {
	SLIME = 1,
	ORC = 2,
	SKELETON = 3
};

int playerType, hp, attack, defense;

int monsterType, monsterHp, monsterAttack, monsterDefense;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();

int main() {
	srand(time(0));
	EnterLobby();

	return 0;
}

void EnterLobby() {
	while (true) {
		cout << "--------------------------------" << endl;
		cout << "      Welcome to the Lobby      " << endl;
		cout << "--------------------------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "--------------------------" << endl;
		cout << "      (1)Enter Field      " << endl;
		cout << "      (2)Quit Game      " << endl;
		cout << "--------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1) {
			EnterField();
		}
		else {
			return;
		}
	}
}

void SelectPlayer() {
	while (true) {
		cout << "--------------------------" << endl;
		cout << "      Select your job!      " << endl;
		cout << "      (1)Knight, (2)Archer, (3)Mage      " << endl;
		cout << "> ";
		cin >> playerType;
		if (playerType == KNIGHT) {
			cout << "You have selected Knight!" << endl;
			hp = 150;
			attack = 10;
			defense = 5;
			break;
		}
		else if (playerType == ARCHER) {
			cout << "You have selected Archer!" << endl;
			hp = 100;
			attack = 15;
			defense = 3;
			break;
		}
		else if (playerType == MAGE) {
			cout << "You have selected Mage!" << endl;
			hp = 80;
			attack = 25;
			defense = 0;
			break;
		}
		else {
			cout << "Invalid selection. Please try again." << endl;
			return;
		}
	}
	
}

void EnterField() {
	while (true) {
		cout << "--------------------------------" << endl;
		cout << "      Welcome to the Field      " << endl;
		cout << "--------------------------------" << endl;

		cout << "[PLAYER] HP : " << hp << " ATTACK: " << attack << " DEFENSE: " << defense << endl;

		CreateRandomMonster();
	}
	
}

void CreateRandomMonster() {
	monsterType=rand() % 3 + 1;

	switch (monsterType) {
		case SLIME:
			monsterHp = 15;
			monsterAttack = 5;
			monsterDefense = 0;
			cout << "A wild Slime has appeared! (HP:15 / ATT:5 / DEF:0)" << endl;
			break;
		case ORC:
			monsterHp = 40;
			monsterAttack = 10;
			monsterDefense = 3;
			cout << "A wild Orc has appeared! (HP:40 / ATT:10 / DEF:3)" << endl;
			break;
		case SKELETON:
			monsterHp = 80;
			monsterAttack = 15;
			monsterDefense = 5;
			cout << "A wild Skeleton has appeared! (HP:80 / ATT:15 / DEF:5)" << endl;
			break;

	}
}