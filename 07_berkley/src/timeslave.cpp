/*
 * auth: Jonathan Klinger
 * file: timeslave.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include <iostream>
#include "TimeSlave.h"
#include <tuple>
#include "clock.h"

using namespace std;


void TimeSlave::operator()() {
    clock();
}
