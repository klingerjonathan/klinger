/*
auth: Jonathan Klinger
file: account.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include <thread>
#include "account.h"

int Account::get_balance() {
    return balance; 
}

bool Account::deposit(int amount) {
    int currentBalance = balance;
    std::this_thread::yield();
    balance = currentBalance + amount;
    return 1;
}
        
        
bool Account::withdraw(int amount) {
    int currentBalance = balance;
    std::this_thread::yield();
    if (currentBalance - amount < 0) {
        return false;
    } else {
        balance = currentBalance - amount;
        return true;
    }
}