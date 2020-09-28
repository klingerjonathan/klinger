#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char** argv) {
    while(true){
        chrono::milliseconds sleeptime(500);
        this_thread::sleep_for(sleeptime);
        cout << argv[0] << flush;
    }
}