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

Clock::Clock(string name_, int hours, int minutes, int seconds) {
    name = name_;
    this->set_time(hours, minutes, seconds);
}

void Clock::set_time(int hours, int minutes, int seconds) {
    curr_time = jonny::set_time(curr_time, hours, minutes, seconds);
}

tuple<int, int, int> Clock::get_time()
{
    return jonny::get_time(curr_time);
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