/*
auth: Jonathan Klinger 
file: loadsim.cpp 
date: 12.2020
desc: Exercise 04
*/

#include <iostream>
#include <thread>
#include <chrono>
#include "work_queue.h"
#include "work_packet.h"

using namespace std;

int main() {
    int counter{0};

    WorkQueue wq;
    while (true){
        wq.push(WorkPacket{counter});
        cout << "B: Submitted work packet " << counter << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        counter++;
    }
}