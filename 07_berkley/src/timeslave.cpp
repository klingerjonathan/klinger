/*
 * auth: Jonathan Klinger
 * file: timeslave.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include "TimeSlave.h"
#include "channel.h"
#include "clock.h"
#include "pipe.h"
#include <iostream>
#include <string>
#include <tuple>

using namespace std;

void TimeSlave::operator()() {
  // clock();
  long new_time;

  while (true) {
    while (channel.get_pipe1() >> new_time) {
      if (new_time > 0) {
        clock.from_time(new_time);
      } else {
        std::cout << name + " time request: " + to_string(clock.to_time()) +
                         "\n"
                  << std::flush;
        channel.get_pipe2() << clock.to_time();
      }
    }
  }
}
