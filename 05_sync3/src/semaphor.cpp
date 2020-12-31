/*
 * auth: Jonathan Klinger
 * file: semaphor.cpp
 * date: 12.2020
 * desc: Exercise 5
 */

#include "semaphore.h"
#include <mutex>

Semaphore::Semaphore() { counter.store(0); }

Semaphore::Semaphore(int start_value) { counter.store(start_value); }

void Semaphore::release() {
  unique_lock<mutex> ul{mtx};
  not_empty.wait(ul, [this]() { return (counter >= 0); });
  counter--;
  not_maximum.notify_one();
}

void Semaphore::acquire() {
  unique_lock<mutex> ul{mtx};
  not_maximum.wait(ul, [this]() { return (counter < MAXIMUM); });
  counter++;
  not_empty.notify_one();
}

int Semaphore::available_permits() { return MAXIMUM - counter; }