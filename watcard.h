#ifndef WATCARD_H
#define WATCARD_H

class WATCard {

  protected:

  	unsigned int balance;

  public:
  	
    WATCard() { balance = 0; }	// default constructor
    addBalance(unsigned int amount) { this->balance += amount; }

};

#endif
