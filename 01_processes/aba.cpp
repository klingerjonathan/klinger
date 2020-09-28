#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>

using namespace std;

int main() {
    int countB = 0;
    auto pid{fork()};
    if(pid == 0) {
        while(true) {
            cout << "B" << flush;
            chrono::milliseconds sleeptime(500);
            this_thread::sleep_for(sleeptime);
            countB++;

            if(countB == 6){
                kill(pid, SIGKILL);
                kill(getpid(), SIGTERM);
            }
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