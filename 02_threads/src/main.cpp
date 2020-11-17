#include <iostream>
#include <thread>
#include <random>
#include <iomanip>

using namespace std;

class Car
{
public:
    float ges = 0;

    void operator()()
    {
        int round = 1;
        string output;
        ostringstream buf;

        for (int i = 0; i < 10; i++)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis{1, 10};
            this_thread::sleep_for(chrono::milliseconds(1000));
            float rundenzeit = dis(gen);
            ges += rundenzeit;
            buf << "Klasse Car: Runde " << round << " Rundenzeit: " << setprecision(3) << rundenzeit << "s" << endl;
            output = buf.str();
            buf.str("");
            cout << output << flush;
            round++;
        }
    }

    int get_total_time()
    {
        return ges;
    }
};

void mini_one(float &n)
{
    int round = 1;
    string output;
    ostringstream buf;

    for (int i = 0; i < 10; i++)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis{1, 10};
        this_thread::sleep_for(chrono::milliseconds(1000));
        float rundenzeit = dis(gen);
        n += rundenzeit;
        buf << "Mini One: Runde " << round << " Rundenzeit: " << setprecision(3) << rundenzeit << "s" << endl;
        output = buf.str();
        buf.str("");
        cout << output << flush;
        round++;
    }
}

int main()
{
    Car audi_a1;
    float n{};

    thread t1{audi_a1};
    thread t2{mini_one, ref(n)};

    t1.join();
    t2.join();

    if (n > audi_a1.get_total_time())
    {
        cout << "Der Sieger ist Mini mit   : " << n << endl;
        cout << "Der Verlierer ist Audi mit: " << audi_a1.get_total_time() << endl;
    } else if (n < audi_a1.get_total_time()) {
        cout << "Der Sieger ist Audi mit      : " << audi_a1.get_total_time() << endl;
        cout << "Der Verlierer ist Mini mit   : " << n << endl;
    } else {
        cout << "Unentschieden mit: " << n << endl; 
    }
}
