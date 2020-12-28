/*
auth: Jonathan Klinger
file: main.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include <iostream>
#include "account.h"

using namespace std; 

int main() {
    Account klinger;
    klinger.deposit(15);
    klinger.withdraw(6);
    //zu Viel abheben
    bool erfolg = klinger.withdraw(10);

    cout << "Status: " << erfolg << endl;
    cout << "Balance: " << klinger.get_balance() << endl;
}

