#ifndef STUDENT_H
#define STUDENT_H

#include "soda.h"

class Student {

  protected:

  	Printer &prt;
  	NameServer &nameServer;
  	WATCardOffice &cardOffice;
  	unsigned int id;
    unsigned int maxBottles;
    unsigned int curBottles;
  	WATCard *card;
  	VendingMachine::Flavours flavour;
    VendingMachine *vendingMachine;

  public:

    struct Finished {};            // exception raised on completion
    Student( Printer &prt, NameServer &nameServer,
         WATCardOffice &cardOffice, unsigned int id,
         unsigned int maxPurchases );
    void action();
    ~Student() { delete card; } // destructor

};

#endif

