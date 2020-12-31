/*
 * auth: Jonathan Klinger
 * file: main.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include <iostream>
#include <thread>
#include "clock.h"

using namespace std;

int main() {

    thread t1{Clock("testclock")};
    t1.join();
}