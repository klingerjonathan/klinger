/*
 * auth: Jonathan Klinger
 * file: channel.h
 * date: 12/20
 * desc: Exercise 10 - berkely
 */

#pragma once

#include "pipe.h"

class Channel
{
private:
  Pipe<long> pipe1;
  Pipe<long> pipe2;

public:
  Channel() {}

  Pipe<long> &get_pipe1()
  {
    return pipe1;
  }

  Pipe<long> &get_pipe2()
  {
    return pipe2;
  }


};