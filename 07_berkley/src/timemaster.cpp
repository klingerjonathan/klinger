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
    for (int i=1; i<4; i++){
        channel1->get_pipe1() << i;
    }
    
    for (int i=5; i<8; i++){
        channel2->get_pipe1() << i;
    }

    this_thread::sleep_for(5s);

    channel1->get_pipe1().close();
    channel2->get_pipe2().close();


}
