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
    private: 
        string name;
        chrono::time_point<chrono::system_clock> curr_time;
    
    public:    
        Clock(string name);
        Clock(string name_, int hours, int minutes, int seconds);

        void set_time(int hours, int minutes, int seconds);
        tuple<int, int, int> get_time();

        void operator()();

        long to_time();
        void from_time(long new_time);
};