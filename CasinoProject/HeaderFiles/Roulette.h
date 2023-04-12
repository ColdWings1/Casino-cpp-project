#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <cmath>
#include "../HeaderFiles/money.h"
#include <limits>


using namespace std;


void Roulette() {
    srand((unsigned)time(NULL));

    double winchance = 18.0 / 37;

    int randomroll = rand() % 37;

    string bet;
    int betsize;

     
    cout << "\n\n\n\n\n\n\n\n\n";
    cout << "*********************** Welcome to roulette ***********************\n";
    cout << "\033[32mMoney: "  << money << "$\033[33m\n" ;
    cout << "These are what options you have to bet on: \n";
    cout << "\033[31mRed\n\033[33m";
    cout << "\033[90mBlack\n\033[33m";
    cout << "\033[32mGreen\n\033[33m";
    cout << "\033[31mQuit\n\033[33m";
    cout << "Please type what you would like to bet on: \n";   
    cin >> bet;
    if (bet == "Quit" || bet == "quit"){
        money = money;
        return;
        
}
    cout << "How much would you like to bet: ";
    cin >> betsize;
    if (cin.fail()) {
        cout << "Invalid input! Please enter an number." << endl;
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Sleep(5000);
        Roulette();
        }

        


 
    if (betsize > money){
        cout << "You dont have that much money!";
        Sleep(5000);
        Roulette();
    }



    if (randomroll < 18){
        if (bet == "Red" || bet == "red"){
            money = money + betsize;
            cout << "Rolling please wait.....\n";
            Sleep(3000);
            cout << "\033[31mRolled Red!\n\033[33m";
            cout << "Congrats you won: " << betsize <<  "$\n";
            cout << "Returning to roulette in 5 seconds....";
            Sleep(5000);
            Roulette();

        }
        else {
            money = money - betsize;
            cout << "Rolling please wait.....\n";
            Sleep(3000);
            cout << "\033[31mRolled Red!\n\033[33m";
            cout << "You lost: " << betsize <<  "$\n";
            cout << "Returning to roulette in 5 seconds....";
            Sleep(5000);
            Roulette();
        }
        
    }
    else if (randomroll  == 0 ) {
        if (bet == "Green" || bet == "green"){
            money = money + betsize * 35;
            cout << "Rolling please wait.....\n";
            Sleep(3000);
            cout << "\033[32mRolled Green!\n\033[33m";
            cout << "Congrats you won: " << betsize * 35 <<  "$\n";
            cout << "Returning to roulette in 5 seconds....";
            Sleep(5000);
            Roulette();

        }
        else {
            money = money - betsize;
           cout << "Rolling please wait.....\n";
            Sleep(3000);
            cout << "\033[32mRolled Green!\n\033[33m";
            cout << "You lost: " << betsize <<  "$\n";
            cout << "Returning to roulette in 5 seconds....";
            Sleep(5000);
            Roulette();
        }




    }

    else if (randomroll > 18){
        if (bet == "Black" || bet == "black"){
            money = money + betsize;
            cout << "Rolling please wait.....\n";
            Sleep(3000);
            cout << "\033[90mRolled Black!\n\033[33m";
            cout << "Congrats you won: " << betsize <<  "$\n";
            cout << "Returning to roulette in 5 seconds....";
            Sleep(5000);
            Roulette();

        }
        else {
            money = money - betsize;
           cout << "Rolling please wait.....\n";
            Sleep(3000);
            cout << "\033[90mRolled Black!\n\033[33m";
            cout << "You lost: " << betsize <<  "$\n";
            cout << "Returning to roulette in 5 seconds....";
            Sleep(5000);
            Roulette();
        }

    }

}


