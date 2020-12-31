/*
 * auth: Jonathan Klinger
 * file: main.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include <iostream>
#include <thread>
#include "clock.h"
#include "TimeSlave.h"
#include "TimeMaster.h"

using namespace std;

int main() {

    thread t1{Clock("testclock", 0, 0, 0)};
    
    TimeMaster slave1{"Master1", 0, 0, 1};

    TimeSlave slave1{"Slave1", 0, 0, 1};
    TimeSlave slave2{"Slave2", 0, 0, 2};

    thread slave1_thread{ref(slave1)};
    thread slave2_thread{ref(slave2)};

    t1.join();
    slave1_thread.join();
    slave2_thread.join();
}