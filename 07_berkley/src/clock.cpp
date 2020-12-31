/*
 * auth: Jonathan Klinger
 * file: clock.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <string>
#include "clock.h"
#include "timeutils.h"

using namespace std;

Clock::Clock(string name) {
    this->name = name;
    this->curr_time = chrono::system_clock::now();
}

void Clock::operator()() {
    while(true) {
        stringstream ss;
        ss << this->name << ": " << this->curr_time << endl;
        cout << ss.str();

        this_thread::sleep_for(chrono::seconds(1));
        this->curr_time += chrono::seconds(1);
    }
}