/*
auth: Jonathan Klinger
file: work_queue.h
date: 12.2020
desc: Exercise 04
*/

#ifndef WORK_QUEUE
#define WORK_QUEUE

#include "work_packet.h"
#include <condition_variable>
#include <mutex>
#include <queue>

using namespace std;

class WorkQueue {
private:
  queue<WorkPacket> work_queue;
  mutex m;
  std::condition_variable not_empty;
  std::condition_variable is_full;
  size_t max_packets;

public:
  WorkQueue(size_t max) { max_packets = max; };
  void push(WorkPacket wp);
  WorkPacket pop();
};

#endif // WORK_QUEUE