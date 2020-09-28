#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>
#include <sys/wait.h>

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
                int status;
                waitpid(pid, &status, 0);
                exit(EXIT_SUCCESS);
            }
        } 
    } else {
       while(true) {
            if(system("./charout A") != 0){
                cout << "Error!!! charout nicht vorhanden!!!" << endl;
            }
        }  
    }
    //Die genauer Ausgabe haengt davon ab welcher Prozess 
    //vom System zuerst gestartet wird.
}