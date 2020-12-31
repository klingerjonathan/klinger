/*
auth: Jonathan Klinger
file: work_queue.cpp
date: 12.2020
desc: Exercise 04
*/

#include "work_queue.h"
#include "work_packet.h"
#include <condition_variable>
#include <mutex>
#include <queue>
#include <thread>

using namespace std;


void WorkQueue::push(WorkPacket wp) {
  unique_lock<mutex> lck{m};
  is_full.wait(lck, [this]() { return work_queue.size() < max_packets; });
  work_queue.push(wp);
  not_empty.notify_one();
}

WorkPacket WorkQueue::pop() {
  unique_lock<mutex> lck{m};
  not_empty.wait(lck, [this] { return work_queue.size(); });
  WorkPacket return_elem = work_queue.front();
  work_queue.pop();
  is_full.notify_one();
  return return_elem;
}