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
#include <vector>

using namespace std;

class Philosopher {
private:
    int number;
    mutex &left_fork;
    mutex &right_fork;
    mutex &stdout_mtx;

public:
    Philosopher(int _number, 
                mutex &_left_fork, 
                mutex &_right_fork,
                mutex &_stdout_mtx) : left_fork(_left_fork),
                                      right_fork(_right_fork),
                                      stdout_mtx(_stdout_mtx) {
        number = _number;
    }

    void operator()();
    void println(const vector<string>&);
};

#endif // PHILOSOPHER_H