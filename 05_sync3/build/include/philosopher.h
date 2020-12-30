/*
 * auth: Jonathan Klinger
 * file: philosopher.h
 * date: 12.2020
 * desc: Exercise 5
 */

#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H

#include <thread>
#include <mutex>
#include <initializer_list>
#include "semaphore.h"

using namespace std;

class Philosopher {
    private:
        int number;
        mutex &left_fork;
        mutex &right_fork;

    public:
        Philosopher(int _number, 
                mutex &_left_fork, 
                mutex &_right_fork) : left_fork(_left_fork),
                                      right_fork(_right_fork) {
        number = _number;
    }

    void operator()(Semaphore* fork_counter);
};

#endif // PHILOSOPHER_H