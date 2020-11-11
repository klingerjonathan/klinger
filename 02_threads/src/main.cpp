#include <iostream>
#include <thread>
#include <random>

using namespace std;

class Car
{
public:
    void operator()()
    {
        int round = 1;
        string output;

        while (true)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis{1, 10};
            this_thread::sleep_for(chrono::milliseconds(1000));
            output = "Car: Runde " + to_string(round) + " Rundenzeit: " + to_string(dis(gen)) + "\n";
            cout << output << flush;
            round++;
        }
    }
};

void mini_one()
{
    int round = 1;
    string output;

    while (true)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis{1, 10};
        this_thread::sleep_for(chrono::milliseconds(1000));
        output = "Mini One: Runde " + to_string(round) + " Rundenzeit: " + to_string(dis(gen)) + "\n";
        cout << output << flush;
        round++;
    }
}

int main()
{
    Car audi_a1;

    thread t1{audi_a1};
    thread t2{mini_one};

    t1.join();
    t2.join();
}
