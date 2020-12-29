/*
auth: Jonathan Klinger
file: account.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include <thread>
#include <mutex>
#include <chrono>
#include "account.h"

using namespace std;


int Account::get_balance() {
    return balance; 
}

bool Account::deposit(int amount) {
    unique_lock<mutex> unique{m};
    int tmp{this->balance};
    this_thread::sleep_for(chrono::milliseconds{10});
    this->balance = tmp + amount;
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

Depositer::Depositer(Account* account) {
    this->account = account;
}

void Depositer::operator()() {
    for(int i=0; i<5; i++) {
        this->account->deposit(1);
    }
}