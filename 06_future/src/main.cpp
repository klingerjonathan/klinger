/*
 * auth: Jonathan Klinger
 * file: main.cpp
 * date: 12/20
 * desc: Exercise 06 - future
 */

#include <iostream>
#include <vector>
#include <future>
#include <chrono>
#include "CLI11.hpp"
#include "calc_factors.h"
#include "InfInt.h"

using namespace std;

string validate(const string& numbers) {
    size_t check{numbers.find_first_not_of("0123456789")};
    if(check == string::npos){
        return string();
    }
    else{
        return string(numbers) + " contains not numeric character";
    }  
}

void factoring(vector<InfInt>& numbers, vector<shared_future<vector<InfInt>>>& futures) {
    futures.at(numbers.size() - 1).wait();

    for (unsigned int i{}; i < numbers.size(); i++){
        cout << numbers[i] << ": ";
        futures[i].wait();
        for (auto primes : futures[i].get())
        {
            cout << primes.toString() << " ";
        }
        cout << endl;
    }
               }

void checkFacts(vector<InfInt>& numbers, vector<shared_future<vector<InfInt>>>& futures) {
    for (unsigned int i=0; i<futures.size(); i++) {
        futures[i].wait();
        InfInt res = 1;
        for (auto elem : futures[i].get()) {
            res *= elem;
        }
        if (res != numbers[i]) {
            cerr << "Factoring FAILED for: " << numbers.at(i) << endl;
        }
    }
}

int main(int argc, char *argv[]) {
    CLI::App app("Factor numbers");

    vector<string> numbers{};
    app.add_option("number", numbers, "Zahlen zum Faktorieren")
        ->required()
        ->check(validate);

    CLI11_PARSE(app, argc, argv);

    vector<InfInt> facts{};


    for (unsigned int i=0; i<numbers.size(); i++) {
        facts.push_back(numbers[i]);
    }

    vector<shared_future<vector<InfInt>>> futures;


    for (auto elem : facts) {
        futures.push_back(async(launch::async, get_factors, elem));
    }

    auto start = chrono::system_clock::now();

    thread t1{factoring, ref(facts), ref(futures)};
    thread t2{checkFacts, ref(facts), ref(futures)};
    t1.join();
    t2.join();

    auto duration = chrono::duration_cast<chrono::milliseconds>
    (std::chrono::system_clock::now() - start);
    cout << "Time elapsed used for factoring: " << duration.count() << "ms" << endl;
    

    return 0;


}