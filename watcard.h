#ifndef WATCARD_H
#define WATCARD_H

#include <iostream>
using namespace std;

class WATCard {

  protected:

  	unsigned int balance;

  public:
  	
    WATCard() { 
	cerr << "==== WATcard()" << endl;
	balance = 0; 
    }	// default constructor
    void addBalance(  unsigned int amount ) { balance += amount; }
    unsigned int getBalance() { return balance; }
    void charge( unsigned int fee ) { balance -= fee; }

};

#endif


