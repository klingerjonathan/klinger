#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    auto pid{fork()};
    if(pid == 0) {
        while(true) {
            cout << "B" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        } 
    } else {
       while(true) {
            cout << "A" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
        }  
    }
    //Die genauer Ausgabe haengt davon ab welcher Prozess 
    //vom System zuerst gestartet wird.
}