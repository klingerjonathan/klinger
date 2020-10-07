#include <iostream>
#include <thread>

using namespace std;

class Car {
    string carBrand;

    void Car::operator()(string brand) {
        carBrand = brand;
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


