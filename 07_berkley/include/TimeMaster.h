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
#include "channel.h"
#include "pipe.h"

class TimeMaster {
private:
  Clock clock;
  string name;
  Channel* channel1;
  Channel* channel2;

public:
  TimeMaster(string name, int hours, int minutes, int seconds) : clock(name + "_name", hours, minutes, seconds) {
      this->name = name;
  };

  void set_channel1(Channel* chan) {
      channel1 = chan;
  }

  void set_channel2(Channel* chan) {
      channel2 = chan;
  }
  
  void operator()();
};
