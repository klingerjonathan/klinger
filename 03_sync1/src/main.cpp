/*
auth: Jonathan Klinger
file: main.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include <iostream>
#include "account.h"
#include <thread>

using namespace std; 

int main() {
    Account klinger;

    /* P U N K T 1
    klinger.deposit(15);
    klinger.withdraw(6);
    //zu Viel abheben
    bool erfolg = klinger.withdraw(10);

    cout << "Status: " << erfolg << endl;
    cout << "Balance: " << klinger.get_balance() << endl;
    */ 

    klinger.deposit(1);

    thread t1{[&]() {
        klinger.withdraw(1);
    }};

    thread t2{[&]() {
        klinger.withdraw(1);
    }};

    t1.join();
    t2.join();

    cout << "Balance: " << klinger.get_balance() << endl;

    return 0;
}

