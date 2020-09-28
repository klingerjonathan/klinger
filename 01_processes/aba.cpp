#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    auto pid{fork()};
    if(pid == 0) {
        while(true) {
            cout << "B" << flush;
            sleep(0.5);
        } 
    } else {
       while(true) {
            cout << "A" << flush;
            sleep(0.5);
        }  
    }
    //Die genauer Ausgabe haengt davon ab welcher Prozess 
    //vom System zuerst gestartet wird.
}