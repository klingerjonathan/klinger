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
    klinger.deposit(1);
    cout << "Kontostand: " << klinger.get_balance() << endl;
}

