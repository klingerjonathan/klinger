/*
auth: Jonathan Klinger
file: account.h
date: 12.20
desc: Exercise 03 NVS
*/

#include <mutex>
#include "CLI11.hpp"

class Account {
    private: 
        int balance = 0; 
        std::mutex m;

    public: 
        int get_balance();
        bool deposit(int amount) ;
        bool withdraw(int amount);
};

class Depositer {
    private: 
        Account* account;
        int start_deposits{0};
    
    public: 
        Depositer(Account* account, int init_deposits);
        void operator()();
};