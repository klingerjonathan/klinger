#include <iostream>
#include <unistd.h>

using namespace std;

int main() {
    while(true) {
        cout << "B";
        sleep(1000);
    }
    fork();
    while(true) {
        cout << "A" << endl;
        sleep(1000)
    }
}