/*
 * auth: Jonathan Klinger
 * file: semaphore.h
 * date: 12.2020
 * desc: Exercise 5
 */

#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <atomic>
#include <condition_variable>
#include <mutex>


using namespace std;

class Semaphore{
private:
    const int MAXIMUM = 4;
    atomic<int> counter;
    mutex mtx;
    condition_variable not_empty;
    condition_variable not_maximum;

public:
    Semaphore();
    Semaphore(int start_value);
    void acquire();
    void release();
    int available_permits();
};

#endif // SEMAPHORE_H