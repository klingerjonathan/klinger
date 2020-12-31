#ifndef PIPE_H
#define PIPE_H

#include <condition_variable>
#include <mutex>
#include <queue>

template <typename T> class Pipe {
  std::queue<T> backend;
  std::mutex mtx;
  std::condition_variable not_empty;
  bool closed{false};

public:
  Pipe &operator<<(T value) {
    std::lock_guard<std::mutex> lock(mtx);
    backend.push(value);
    not_empty.notify_one();
    return *this;
  }

  Pipe &operator>>(T &value) {
    if (closed) {
      return *this;
    } else {
      std::unique_lock<std::mutex> lock{mtx};
      not_empty.wait(lock, [this] { return backend.size() > 0; });
      value = backend.front();
      backend.pop();
    }

    return *this;
  }

  void close() { closed = true; }

  explicit operator bool() { return !closed; }
};
#endif