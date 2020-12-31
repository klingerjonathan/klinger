/*
 * auth: Jonathan Klinger
 * file: main.cpp
 * date: 12/20
 * desc: Exercise 06 - future
 */

#include <iostream>
#include <vector>
#include <future>
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

    vector<future<vector<InfInt>>> futures;


    for (auto elem : facts) {
        futures.push_back(async(launch::async, get_factors, elem));
    }


    futures.at(facts.size() - 1).wait();

    for (unsigned int i{}; i < facts.size(); i++){
        cout << numbers[i] << ": ";
        futures[i].wait();
        for (auto primes : futures[i].get())
        {
            cout << primes.toString() << " ";
        }
        cout << endl;
    }


}