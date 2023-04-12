#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <ctime>
#include <cmath>
#include "../HeaderFiles/money.h"
#include <limits>
#include <iomanip>



using namespace std;



void dice(){

    double edge = 3;
    double payout; 
    double roll;
    string whattodo;
    double betsize;
    double moneyrecived;
    string wanttoquit;
    


    srand((unsigned)time(NULL));
    int randomroll = (rand() % 100) + 1;

    
    

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "************************** Welcome to dice **************************\n";
    cout << "\033[32mMoney: "  << money << "$\033[33m\n" ;
    cout << "Write " << "\033[31mQuit\033[33m" << " if you want to leave\n";
    cout << "The dice will roll over: ";
    cin >> wanttoquit;

    if (wanttoquit == "Quit" || wanttoquit == "quit"){

        return;
    }
    
    else if (wanttoquit != "Quit" && wanttoquit != "quit" ){
        if(wanttoquit.find_first_not_of("0123456789") != string::npos){
            cout << "Invalid input!\n";
            Sleep(3000);
            cout << "Returning to dice...";
            dice();
    
            }
    }
         

    if (wanttoquit.find_first_not_of("0123456789") == string::npos) {
    roll = stoi(wanttoquit);
}


    if (roll > 100 || roll < 1){
        cout << "Invalid input! Please enter an number between 1 and 100!.\n";
        Sleep(3000);
        dice();


    } 

    double payroll = 100 - roll;
    payout = (100 - edge) / payroll;
    cout << "How much would you like to bet: ";
    cin >> betsize;
    if (cin.fail()) {
        cout << "Invalid input! Please enter an number.\n";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(), '\n');
        Sleep(5000);
        dice();
        }
    if (betsize > money){
        cout << "You dont have that much money!";
        Sleep(5000);
        dice();
    }
    moneyrecived = betsize * payout - betsize;
    cout << "\n";
    cout << fixed << setprecision(2) << "Your payout if you win for this bet will be: " << "\033[32m" << payout << "x\n\033[33m";
    cout << "You will recive: \033[32m" << moneyrecived << "$ \033[33m" << "If you win\n";
    cout << "please write your next action \n";
    cout << "\033[32mRoll\n\033[33m";
    cout << "\033[31mQuit\n\033[33m";
    cin >> whattodo;
    if (whattodo == "Quit" || whattodo == "quit"){

        return;
    }

    else if (whattodo == "Roll" || whattodo == "roll"){
        cout << "Rolling please wait....";
        Sleep(2000);

        if (roll < randomroll){

            money = money + moneyrecived;
            cout << "Rolled: \033[35m" << randomroll << "\n\033[33m";
            cout  << "Congrats you won! your payout for this win is: \033[32m" << moneyrecived << "$ \033[33m\n";
            cout << "Making your new balance \033[32m" << money << "$ \033[33m\n";
            cout << "Returning to dice in 5 seconds....";
            Sleep(5000);
            dice();




        }
        else {
            money = money - betsize;
            cout << "Rolled: \033[35m" << randomroll << "\n\033[33m";
            cout << "You lost: \033[32m" << betsize <<  "$\033[33m\n";
            cout << "Making your new balance \033[32m" << money << "$ \033[33m\n";
            cout << "Returning to dice in 5 seconds....";
            Sleep(5000);
            dice();


        }

    }

}


