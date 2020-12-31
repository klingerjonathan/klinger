/*
auth: Jonathan Klinger
file: main.cpp
date: 12.20
desc: Exercise 03 NVS
*/

#include "CLI11.hpp"
#include "account.h"
#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char **argv) {
  Account klinger;

  /* P U N K T 1
  klinger.deposit(15);
  klinger.withdraw(6);
  //zu Viel abheben
  bool erfolg = klinger.withdraw(10);

  cout << "Status: " << erfolg << endl;
  cout << "Balance: " << klinger.get_balance() << endl;
  */

  /*
  klinger.deposit(1);

  thread t1{[&]() {
      klinger.withdraw(1);
  }};

  thread t2{[&]() {
      klinger.withdraw(1);
  }};

  t1.join();
  t2.join();

  cout << "Balance: " << klinger.get_balance() << endl;
  */

  /*
      Depositer dep1(&klinger);
      Depositer dep2(&klinger);

      thread t1{&Depositer::operator(), ref(dep1)};
      thread t2{&Depositer::operator(), ref(dep2)};

      t1.join();
      t2.join();
      cout << "Balance: " << klinger.get_balance() << endl;

  */

  CLI::App app("Account app");

  int balance{0};
  app.add_option("balance", balance, "Initial balance")->required();
  int deposits{5};
  app.add_option("-d,--deposits", deposits, "Count of deposits", true);
  CLI11_PARSE(app, argc, argv);

  klinger.deposit(balance);

  Depositer dep1(&klinger, deposits);
  Depositer dep2(&klinger, deposits);

  thread t1{&Depositer::operator(), ref(dep1)};
  thread t2{&Depositer::operator(), ref(dep2)};

  t1.join();
  t2.join();
  cout << klinger.get_balance() << endl;
  return 0;
}
