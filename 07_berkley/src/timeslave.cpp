/*
 * auth: Jonathan Klinger
 * file: timeslave.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include <iostream>
#include <string>
#include <tuple>
#include "clock.h"
#include "pipe.h"
#include "channel.h"
#include "TimeSlave.h"

using namespace std;


void TimeSlave::operator()() {
    //clock();
    long value1; 
    long value2;
    
    while (channel.get_pipe1() >> value1) {
        cout << name << ": " << value1 << endl; 
    }

    while (channel.get_pipe2() >> value2) {
        cout << name << ": " << value2 << endl; 
    }
}
