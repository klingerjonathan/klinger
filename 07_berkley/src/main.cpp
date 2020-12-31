/*
 * auth: Jonathan Klinger
 * file: main.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include "TimeMaster.h"
#include "TimeSlave.h"
#include "channel.h"
#include "clock.h"
#include "pipe.h"
#include <iostream>
#include <thread>

using namespace std;

int main() {

  // thread t1{Clock("testclock", 0, 0, 0)};

  TimeMaster master{"Master1", 0, 0, 1};

  TimeSlave slave1{"Slave1", 0, 0, 1};
  TimeSlave slave2{"Slave2", 0, 0, 2};

  master.set_channel1(slave1.get_channel());
  master.set_channel2(slave2.get_channel());

  thread master_thread{master};

  thread slave1_thread{ref(slave1)};
  thread slave2_thread{ref(slave2)};

  // t1.join();
  master_thread.join();
  slave1_thread.join();
  slave2_thread.join();
}