#include <iostream>
#include <thread>

using namespace std;

class Car {
    string carName;

    Car(string name) {
        carName = name;
    }

    void race() {
        int round = 1;

        while(true){
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Runde: " << round << endl << flush; 
            round++;
        }
    }
};



int main() {

}


