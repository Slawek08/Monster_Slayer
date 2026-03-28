#pragma once

#include <string>
#include <iostream>
#include <clocale>
#include "types.h"

using namespace std;

class Character {
private:
    string name, classType;
    numberHealth health;
    numberAttack distanceAttack, closeAttack;
    string backpack[3] = {"apteczka", "eliksir", "trutka"};

public:
    Character(const string& name, numberHealth health, numberAttack closeAttack, numberAttack distanceAttack ,const string& classType)
        : name(name), health(health), closeAttack(closeAttack), distanceAttack(distanceAttack), classType(classType) {
    }

    string getName() const { return name; }
    numberHealth getHealth() const { return health; }
    numberAttack getCloseAttack() const { return closeAttack; }
    numberAttack getDistanceAttack() const { return distanceAttack; }
    string getClassType() const {setlocale(LC_ALL, ""); return classType; }

    void getBackpack() {
        cout << "Zawartoœæ plecaka \n";
        for (int i = 0; i < 3; i++) {
            cout << "-> " << backpack[i] << "\n" << endl;
        }
    }


    void seeStats() {
        cout << "Imiê: " << getName()
            << "\n Zdrowie: " << getHealth()
            << "\n Si³a bliskiego ataku: " << getCloseAttack()
            << "\n Si³a dalekiego ataku: " << getDistanceAttack()
            << "\n Klasa postaci: " << getClassType()
            << "\n";

            getBackpack();
    }

    void addHealth() {
        health += 50;
        cout << "Zdrowie wynosi: " << getHealth() << "\n" << endl;
    }

    void addCloseAttack() {
        closeAttack += 40;
        cout << "Atak z bliska wynosi: " << getCloseAttack() << "\n" << endl;
    }

    void addDistanceAttack() {
        distanceAttack += 40;
        cout << "Atak z daleka wynosi: " << getDistanceAttack() << "\n" << endl;
    }

    void damage(numberMonAttack getAttack) {
        health -= getAttack;
        cout << "Oberwa³eœ. Twoje ¿ycie aktualnie wynosi: " << getHealth() << "\n" << endl;
    }

    void seeHealth() {
        cout << getHealth();
    }
};



