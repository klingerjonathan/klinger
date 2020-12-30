/*
 * auth: Jonathan Klinger
 * file: utils.h 
 * date: 12.2020
 * desc: Exercise 5
 */

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <mutex>

using namespace std;

recursive_mutex out_mtx;

void println() {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << endl;
}

template<typename T, typename... Rest>
void println(const T& word, const Rest&... rest) {
    lock_guard<recursive_mutex> lg{out_mtx};
    cout << word << ' ';
    println(rest...);
}

#endif // UTILS_H