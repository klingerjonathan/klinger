#include <iostream>
#include <thread>

using namespace std;

class Car {
    public:
        void operator()() {
            int round = 1;
            string output;

            while(true){
                this_thread::sleep_for(chrono::seconds(1));
                output = "Car: Runde " + to_string(round) + "\n"; 
                cout << output << flush;
                round++;
            }
        }

};

void mini_one() {
    int round = 1;
    string output; 

    while(true){
        this_thread::sleep_for(chrono::seconds(1));
        output = "Mini One: Runde " + to_string(round) + "\n"; 
        cout << output << flush;
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


