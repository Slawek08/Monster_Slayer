#pragma once

#include <string>
#include <iostream>
#include <clocale>
#include "types.h"

using namespace std;

class Monster {
private:
	string name, classType;
	numberMonHealth health;
	numberMonAttack attack, superAttack;

public: 
	Monster(const string& name, numberMonHealth health, numberMonAttack attack, numberMonAttack superAttack, const string& classType)
		: name(name), health(health), attack(attack), superAttack(superAttack), classType(classType) { 
	}


	string getMonName() const { return name;}
	numberMonHealth getMonHealth() const { return health; }
	numberMonAttack getMonAttack() const { return attack; }
	numberMonAttack getMonSuperAttack() const { return superAttack; }
	string getMonClassType() const { return classType; }


	void seeMonsterStatsByPlayer() {
		cout << "\nNazwa: " << getMonName()
			<< "\n  Zdrowie: " << getMonHealth()
			<< "\n Klasa postaci: " << getMonClassType()
			<< "\n" << endl;
	}

	void seeMonsterStats() {
		cout << "\n Nazwa: " << getMonName()
			<< "\n Zdrowie: " << getMonHealth()
			<< "\n Zwyk³y atak: " << getMonAttack()
			<< "\n Super atak: " << getMonSuperAttack()
			<< "\n Typ potwora: " << getMonClassType()
			<< "\n" << endl;
	}

	void monDamage(numberAttack getAttack) {
		health -= getAttack;
		cout << getMonName() << " oberwa³. Jego ¿ycie aktualnie wynosi: " << getMonHealth() << "\n" << endl;
	}

	void monAddHealth() {
		health += 10;
		cout << "Potwór zwiêkszy³ swoje zdrowie " << "\n" << endl;
	}

	void monAddAttack() {
		attack += 8;
		cout << "Potwór zwiêkszy³ swój podstawowy atak " << "\n" << endl;
	}

	void monAddSuperAttack() {
		superAttack += 4;
		cout << "Potwór zwiêkszy³ swój super atak " << "\n" << endl;
	}

	void monSeeHealth() {
		cout << getMonHealth() << "\n" << endl;
	}

};
