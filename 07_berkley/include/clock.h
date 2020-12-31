/*
 * auth: Jonathan Klinger
 * file: clock.h
 * date: 12/20
 * desc: Exercise 10 - berkely
 */
#pragma once

#include <chrono>
#include <iostream>

using namespace std;

class Clock {
    public:
        string name;
        chrono::time_point<chrono::system_clock> curr_time;
    
        Clock(string name);

        void operator()();
};