/*
auth: Jonathan Klinger
file: account.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include <thread>
#include <mutex>
#include "account.h"

using namespace std;


int Account::get_balance() {
    return balance; 
}

bool Account::deposit(int amount) {
    balance -= amount;
    return 1;
}
        
        
bool Account::withdraw(int amount) {
    lock_guard<mutex> guard{m};
    if (balance - amount < 0) {
        return false;
    } else {
        balance -= amount;
        return true;
    }
}