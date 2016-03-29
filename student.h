#ifndef STUDENT_H
#define STUDENT_H

class Printer;
class NameServer;
class WATCardOffice;
#include "watcard.h"
class VendingMachine;

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

