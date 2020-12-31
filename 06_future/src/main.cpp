/*
 * auth: Jonathan Klinger
 * file: main.cpp
 * date: 12/20
 * desc: Exercise 06 - future
 */

//#include "InfInt.h"
#include <iostream>
#include <vector>
#include "CLI11.hpp"
#include "InfInt.h"
#include "calc_factors.h"

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


    for (int i=0; i<numbers.size(); i++) {
        facts.push_back(numbers[i]);
    }

    for (auto number : facts) {
        cout << number << ": ";
        for (auto elem : get_factors(number)) {
            cout << elem.toString() << " ";
        }
        cout << endl;
    }
}