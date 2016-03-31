#ifndef WATCARD_H
#define WATCARD_H

#include <iostream>
using namespace std;


class WATCard {

  protected:

  	unsigned int balance;

  public:
  	
    WATCard() { balance = 0; }	// default constructor
    unsigned int getBalance() { return balance; }
    void addBalance(  unsigned int amount ) { balance += amount; }
    void charge( unsigned int fee ) { balance -= fee; }

};


#endif
