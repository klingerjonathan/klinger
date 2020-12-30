/*
auth: Jonathan Klinger 
file: work_queue.cpp 
date: 12.2020
desc: Exercise 04
*/

#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>
#include "work_queue.h"
#include "work_packet.h"

using namespace std;

WorkQueue::WorkQueue(){ }

void WorkQueue::push(WorkPacket wp){
    unique_lock lck{m};
    this->work_queue.push(wp);
    not_empty.notify_one();
}

WorkPacket WorkQueue::pop(){
    unique_lock<mutex> lck{m};
    not_empty.wait(lck, [this]{return this->work_queue.size();});
    WorkPacket return_elem = this->work_queue.front();
    this->work_queue.pop();
    return return_elem;
}