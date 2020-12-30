/*
 * auth: Jonathan Klinger
 * File: Philosopher.cpp
 * date: 12.2020
 * desc: Exercise 5
 */

#include <iostream>
#include <thread>
#include <chrono>
#include "philosopher.h"

using namespace std;

void Philosopher::operator()(mutex &cout_mtx) {
    while (true){
        println({"Philosopher ", to_string(number), " is thinking..."});
        this_thread::sleep_for(1s);

        println({"Philosopher ", to_string(number), " attempts to get left fork"});

        left_fork.lock();

        println({"Philosopher ", to_string(number), " got left fork. Now he wants the right one..."});
        println({"Philosopher ", to_string(number), " attempts to get right fork"});

        right_fork.lock();

        println({"Philosopher ", to_string(number), " got right fork. Now he is eating..."});


        this_thread::sleep_for(2s);

        println({"Philosopher ", to_string(number), " finished eating"});

        left_fork.unlock();

        println({"Philosopher ", to_string(number), " released left fork"});

        right_fork.unlock();

        println({"Philosopher ", to_string(number), " released right fork"});

    }
}