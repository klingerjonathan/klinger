/*
auth: Jonathan Klinger
file: account.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include "account.h"

int Account::get_balance() {
    return balance; 
}

bool Account::deposit(int amount) {
    balance += amount;
    return 1;
}
        
        
bool Account::withdraw(int amount) {
    if (balance - amount < 0) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}