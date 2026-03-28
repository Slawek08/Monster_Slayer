#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include <string>
#include "Character.h"
#include "Monster.h"
#include <clocale>
#include <vector>
#include <algorithm>
#include <thread> 
#include <chrono> 
#include <ctime>

using namespace std;

void bubbleSortOnStrings(string array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}

void review(int rate, int argc) {
    if (rate < 0 || rate > 10) {
        cout << "Ocena jest od 0 - 10: ";
    }
    else {
        cout << "Dziękuję za opinię";

        vector <int> rateVector = { 8, 6, 4 };
        int size = sizeof(rateVector) / sizeof(rateVector[0]);

        rateVector.push_back(argc);
        rateVector.push_back(rate);

        sort(rateVector.begin(), rateVector.end());

        cout << "\n \n Oto jakie mamy oceny: ";

        for (int grade : rateVector) {
            cout << "\n -> " << grade;
        }
    }
}
void seeElementsFromArray(string array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "\n" << array[i] << " ";
    }
    cout << endl;
}

void terminalCleaningForPersonalizing(string title) {
    this_thread::sleep_for(chrono::seconds(1));
    system("cls");
    cout << title;
}

void terminalCleaningForInstruction(string title) {
    this_thread::sleep_for(chrono::seconds(5));
    system("cls");
    cout << title;
}

namespace instruction {
    string instructionText = "Instrukcja do gry: \n -> 1 : atak z bliska, \n -> 2: atak z daleka, \n -> 3: użyj apteczki, \n -> 4: użyj eliksiru, \n -> 5: użyj trucizny,\n -> 6: zobaczenie statystyk potwora, \n -> 7: wyświetlenie instrukcji, \n -> 8: wyświetlenie nazw potworów, \n -> 9: wyświetlenie statystyk bohatera";

    void seeInstruction() {
        cout << instructionText << endl;
    }
}

void arrayOfMonsters() {
    string monsters[4] = { "DuzoGlowy", "Psychomata", "Terminal", "CPlusPlus" };
    int size = sizeof(monsters) / sizeof(monsters[0]);
    bubbleSortOnStrings(monsters, size);

    seeElementsFromArray(monsters, size);
}

void terminalCleaningForFight() {
    string title =
        " ___  ________ _   _  _____ _____ ___________   _____ _       _____   _____________ \n"
        "|  \\/  |  _  | \\ | |/  ___|_   _|  ___| ___ \\ /  ___| |     / _ \\ \\ / /  ___| ___ \\ \n"
        "| .  . | | | |  \\| |\\ `--.  | | | |__ | |_/ / \\ `--.| |    / /_\\ \\ V /| |__ | |_/ / \n"
        "| |\\/| | | | | . ` | `--. \\ | | |  __||    /   `--. \\ |    |  _  |\\ / |  __||    /  \n"
        "| |  | \\ \\_/ / |\\  |/\\__/ / | | | |___| |\\ \\  /\\__/ / |____| | | || | | |___| |\\ \\  \n"
        "|_|  |_|\\___/\\_| \\_/\\____/  \\_/ \\____/\\_| \\_| \\____/\\_____/\\_| |_/\\_/ \\____/\\_| \\_| \n";

    this_thread::sleep_for(chrono::seconds(5));
    system("cls");
    cout << title;
}

void fight(Character& character, Monster& monster, int& answer) {
    while (character.getHealth() > 0 && monster.getMonHealth() > 0 && answer != 5) {
        if (answer == 1) {
            monster.monDamage(character.getCloseAttack());
            character.damage(monster.getMonAttack());
            terminalCleaningForFight();
        }
        else if (answer == 2) {
            monster.monDamage(character.getDistanceAttack());
            character.damage(monster.getMonSuperAttack());
            terminalCleaningForFight();
        }
        else if (answer == 3) {
            character.addHealth();
            monster.monAddHealth();
            terminalCleaningForFight();
        }
        else if (answer == 4) {
            character.addCloseAttack();
            character.addDistanceAttack();
            monster.monAddAttack();
            monster.monAddSuperAttack();
            terminalCleaningForFight();
        }
        else if (answer == 6) {
            monster.seeMonsterStatsByPlayer();
            terminalCleaningForFight();
        }
        else if (answer == 7) {
            instruction::seeInstruction();
            terminalCleaningForFight();
        }
        else if (answer == 8) {
            arrayOfMonsters();
            terminalCleaningForFight();
        }
        else if (answer == 9) {
            character.seeStats();
            terminalCleaningForFight();
        }
        else {
            cout << "Wpisz prawidłową akcję ";
            terminalCleaningForFight();
        }

        cin >> answer;
    }
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "");

    string title =
        " ___  ________ _   _  _____ _____ ___________   _____ _       _____   _____________ \n"
        "|  \\/  |  _  | \\ | |/  ___|_   _|  ___| ___ \\ /  ___| |     / _ \\ \\ / /  ___| ___ \\ \n"
        "| .  . | | | |  \\| |\\ `--.  | | | |__ | |_/ / \\ `--.| |    / /_\\ \\ V /| |__ | |_/ / \n"
        "| |\\/| | | | | . ` | `--. \\ | | |  __||    /   `--. \\ |    |  _  |\\ / |  __||    /  \n"
        "| |  | \\ \\_/ / |\\  |/\\__/ / | | | |___| |\\ \\  /\\__/ / |____| | | || | | |___| |\\ \\  \n"
        "|_|  |_|\\___/\\_| \\_/\\____/  \\_/ \\____/\\_| \\_| \\____/\\_____/\\_| |_/\\_/ \\____/\\_| \\_| \n";

    cout << title << "\n";
    cout << "                                      Play\n";
    cout << " \n";
    cout << "                                      Exit\n";

    string answer;
    cin >> answer;

    while (answer != "Exit") {
        if (answer == "Play") {
            numberHealth health;
            numberAttack closeAttack, distanceAttack;
            string name, classType;

            cout << "Imię: ";
            cin >> name;

            cout << "Zdrowie: ";
            cin >> health;

            cout << "Atak z bliska: ";
            cin >> closeAttack;

            cout << "Atak z daleka: ";
            cin >> distanceAttack;

            while (health > 99) {
                cout << "Zdrowie musi być mniejsze od 100 \n";
                cout << "Zdrowie: ";
                cin >> health;
                terminalCleaningForPersonalizing(title);
            }

            while (closeAttack > 99) {
                cout << "Atak musi być mniejszy od 100 \n";
                cout << "Atak: ";
                cin >> closeAttack;
                terminalCleaningForPersonalizing(title);
            }

            while (distanceAttack < 100 || distanceAttack > 149) {
                cout << "Atak dystansowy musi być pomiędzy 100 a 149 \n";
                cout << "Atak dystansowy: ";
                cin >> distanceAttack;
                terminalCleaningForPersonalizing(title);
            }

            do {
                cout << "Dostępne klasy postaci: \n";
                cout << "-> Mag \n";
                cout << "-> Rycerz \n";
                cout << "Wybierz klasę: ";
                cin >> classType;
                terminalCleaningForPersonalizing(title);
            } while (classType != "Rycerz" && classType != "Mag");

            Character protagonist(name, health, closeAttack, distanceAttack, classType);

            if (protagonist.getClassType() == "Mag") {
                protagonist.addDistanceAttack();
            }
            else if (protagonist.getClassType() == "Rycerz") {
                protagonist.addCloseAttack();
            }

            protagonist.seeStats();

            Monster duzoGlowy("DuzoGlowy", 200, 56, 78, "pachołek rangi 1");
            Monster psychoMata("Psychomata", 400, 42, 98, "pachołek rangi 2");
            Monster terminal("Terminal", 510, 52, 101, "Królewicz");
            Monster cPlusPlus("CPlusPlus", 600, 60, 120, "Król");

            string monsters[4] = { "DuzoGlowy", "Psychomata", "Terminal", "CPlusPlus" };

            int answer1;
            instruction::seeInstruction();
            cin >> answer1;

            srand(time(0));
            int random = rand() % 4;

            Monster selectedMonster = (monsters[random] == "DuzoGlowy") ? duzoGlowy :
                (monsters[random] == "Psychomata") ? psychoMata :
                (monsters[random] == "Terminal") ? terminal :
                cPlusPlus;

            fight(protagonist, selectedMonster, answer1);

            numberHealth protagonistHealth;
            numberMonHealth monsterHealth;

            protagonistHealth = protagonist.getHealth();
            monsterHealth = selectedMonster.getMonHealth();

            if (protagonistHealth <= 0) {
                terminalCleaningForPersonalizing(title);

                cout << "  ____                               _         __" << endl;
                cout << " |  _ \\ _ __ _______  __ _ _ __ __ _| | ___  _/_/" << endl;
                cout << " | |_) | '__|_  / _ \\/ _` | '__/ _` |/// _ \\/ __|" << endl;
                cout << " |  __/| |   / /  __/ (_| | | | (_| //|  __/\\__ \\" << endl;
                cout << " |_|   |_|  /___\\___|\\__, |_|  \\__,_|_|\\___||___/" << endl;
                cout << "                     |___/" << endl;
                cout << "\n \n                " << protagonist.getName();
            }

            if (monsterHealth <= 0) {
                terminalCleaningForPersonalizing(title);

                cout << "__        __                     _         __" << endl;
                cout << " \\ \\      / /   _  __ _ _ __ __ _| | ___  _/_/" << endl;
                cout << "  \\ \\ /\\ / / | | |/ _` | '__/ _` |/// _ \\/ __|" << endl;
                cout << "   \\ V  V /| |_| | (_| | | | (_| //|  __/\\__ \\" << endl;
                cout << "    \\_/\\_/  \\__, |\\__, |_|  \\__,_|_|\\___||___/" << endl;
                cout << "            |___/ |___/" << endl;
                cout << "\n \n                " << protagonist.getName();
            }

            int rate;

            cout << "\n \n Jak oceniasz grę w skali 0 - 10: ";
            cin >> rate;

            review(rate, argc);

            return 1;
        }
    }
    return 0;
}


