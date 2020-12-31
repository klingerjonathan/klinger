/*
 * auth: Jonathan Klinger
 * file: timemaster.cpp
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#include <thread>
#include "TimeMaster.h"
#include "pipe.h"
#include "channel.h"

void TimeMaster::operator()() {

    while (true) {
        cout << "Berkeley sync started: " + std::to_string(clock.to_time()) + "\n" << std::flush;

        long slave1_time;
        long slave2_time;
        long self_time;

        channel1->get_pipe1() << -1;
        channel2->get_pipe1() << -1;

        self_time = clock.to_time();
        channel1->get_pipe2() >> slave1_time;
        channel2->get_pipe2() >> slave2_time;

        long new_time{(self_time + slave1_time + slave2_time) / 3};
    
        clock.from_time(new_time);
        channel1->get_pipe1() << new_time;
        channel2->get_pipe1() << new_time;

        this_thread::sleep_for(3s);

    }


}
