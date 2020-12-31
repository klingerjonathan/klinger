/*
 * auth: Jonathan Klinger
 * file: TimeSlave.h
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#pragma once

#include <string>

using namespace std;

#include "clock.h"
#include "channel.h"

class TimeSlave {
private:
  Clock clock;
  string name;
  Channel channel;

public:
  TimeSlave(std::string name, int hours, int minutes, int seconds) : clock(name + "_name", hours, minutes, seconds) {
      this->name = name;
  };

  Channel* get_channel() {
      return &channel;
  }
  
  void operator()();
};