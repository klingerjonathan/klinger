#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
    auto pid1{fork()};
    auto pid2{fork()};

    if(pid1 == 0){
        sleep(3);
        int status;
        waitpid(pid2, &status, 0);
        kill(pid2, SIGTERM);
        waitpid(pid1, &status, 0);
        kill(pid1, SIGTERM);
    } else{
        if (pid2 == 0){
            int run1 = execl("./charout", "B", nullptr);
            if (run1 == -1){
                cout << "Aufruf charout B wurde mit dem Code " << errno << " beendet" << endl;
            } else{
                cout << run1 << flush;
                exit(1);
            }
        } else{
            int run2 = execl("./charout", "A", nullptr);
            if (run2 == -1){
                cout << "Aufruf charout A wurde mit dem Code " << errno << " beendet" << endl;
            } else{
                cout << run2 << flush;
                exit(1);
            }
        }
    }

    //Die genauer Ausgabe haengt davon ab welcher Prozess
    //vom System zuerst gestartet wird.
}