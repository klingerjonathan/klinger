/*
auth: Jonathan Klinger 
file: work_queue.cpp 
date: 12.2020
desc: Exercise 04
*/

#include <thread>
#include <mutex>
#include <queue>
#include "work_queue.h"
#include "work_packet.h"

using namespace std;

WorkQueue::WorkQueue(){ }

void WorkQueue::push(WorkPacket wp){
    lock_guard<mutex> guard{m};
    this->work_queue.push(wp);
}

bool WorkQueue::pop(){
    lock_guard<mutex> guard{m};
    if(!this->work_queue.empty()){
        this->work_queue.pop();
        return true;
    } else {
        return false;
    }
}