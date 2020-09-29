#include <iostream>
#include <thread>

using namespace std;

void mini_one() {
    int round = 1;

    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Runde: " << round << endl << flush; 
        round++;
    }
}

int main() {
    thread t{mini_one};
    t.join();
}


