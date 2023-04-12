#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include "../HeaderFiles/money.h"
#include "../HeaderFiles/Roulette.h"
#include "../HeaderFiles/Dice.h"

using namespace std;

int money = 500;



int main() {
    system("Color 0E"); 
    int game;
   

    cout << "************************************ Welcome To The Casino ************************************\n";
    cout << "\n\n";
    cout << "\033[32mMoney: "  << money << "\033[33m\n" ;
    cout << "Here are all available games:\n\n";
    cout << "\033[34mNr.1 = Roulette\n\033[33m";
    cout << "\033[35mNr.2 = Dice\n\033[33m";
    cout << "\033[31mNr.3 = Quit\n\033[33m";
    cout << "Please choose a game below, by writing the number in front of the game ";
    cin >> game;
    



    switch (game) {
        case 1:
        cout << "Loading Roulette please wait....\n";
        Sleep(1500);
            Roulette();
            cout << "Returning to casino please wait.....\n";
            Sleep(1500);
            main();

        case 2:
            cout << "Loading dice please wait...\n";
            Sleep(1500);
            dice();
            cout << "Returning to casino....\n";
            Sleep(1500);
            main();
            
        case 3:
        cout << "Quiting....";
         Sleep(1500);
         ExitProcess(1);

        default:
            cout << "That was not an option";
            Sleep(1500);
             cin.clear();
             cin.ignore(numeric_limits<streamsize>::max(), '\n');
            main();
    }

    return 0;
}
