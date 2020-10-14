#include <iostream>
#include <thread>

using namespace std;

class Car {
    public:
        void operator()() {
            int round = 1;

            while(true){
                this_thread::sleep_for(chrono::seconds(1));
                cout << "Car: Runde " << round << flush << endl; 
                round++;
            }
        }

};

void mini_one() {
    int round = 1;

    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        cout << "Mini One: Runde " << round << flush << endl; 
        round++;
    }
}



int main() {
    Car audi_a1;
    
    thread t1{audi_a1};
    thread t2{mini_one};

    t1.join();
    t2.join();

}


