#include <iostream>
#include <thread>
#include <random>
#include <iomanip>

using namespace std;

class Car
{
public:
    void operator()()
    {
        int round = 1;
        string output;
        ostringstream buf;

        while (true)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis{1, 10};
            this_thread::sleep_for(chrono::milliseconds(1000));
            buf << "Car: Runde " << round << " Rundenzeit: " << setprecision(3) << dis(gen) << endl;
            output = buf.str();
            buf.str("");
            cout << output << flush;
            round++;
        }
    }
};

void mini_one()
{
    int round = 1;
    string output;
    ostringstream buf;

    while (true)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis{1, 10};
        this_thread::sleep_for(chrono::milliseconds(1000));
        buf << "Mini One: Runde " << round << " Rundenzeit: " << setprecision(3) << dis(gen) << endl;
        output = buf.str();
        buf.str("");
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
