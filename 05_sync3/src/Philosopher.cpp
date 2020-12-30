/*
 * auth: Jonathan Klinger
 * File: Philosopher.cpp
 * date: 12.2020
 * desc: Exercise 5
 */

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <initializer_list>
#include "philosopher.h"
#include "utils.h"
#include "semaphore.h"

using namespace std;


void Philosopher::operator()(Semaphore* fork_counter) {
    while (true){
        println("Philosopher ", to_string(number), " is thinking...");
        
        this_thread::sleep_for(1s);

        println("Philosopher ", to_string(number), " attempts to get left fork");

        if(fork_counter != nullptr) {
            fork_counter->acquire();
        }

        left_fork.lock();

        println("Philosopher ", to_string(number), " got left fork. Now he wants the right one...");

        this_thread::sleep_for(5s);

        println("Philosopher ", to_string(number), " attempts to get right fork");

        right_fork.lock();

        println("Philosopher ", to_string(number), " got right fork. Now he is eating...");


        this_thread::sleep_for(2s);

        println("Philosopher ", to_string(number), " finished eating");

        left_fork.unlock();
        if(fork_counter != nullptr) {
            fork_counter->acquire();
        }

        println("Philosopher ", to_string(number), " released left fork");
        println("currently", to_string(fork_counter->available_permits()), "left forks available");

        right_fork.unlock();

        println("Philosopher ", to_string(number), " released right fork");

    }
}