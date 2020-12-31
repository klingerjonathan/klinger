/*
 * auth: Jonathan Klinger
 * file: TimeMaster.h
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#pragma once

#include <string>

using namespace std;

#include "clock.h"

class TimeMaster {
private:
  Clock clock;
  string name;

public:
  TimeMaster(string name, int hours, int minutes, int seconds) : clock(name + "_name", hours, minutes, seconds) {
      this->name = name;
  };
  
  void operator()();
};
