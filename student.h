#ifndef STUDENT_H
#define STUDENT_H

#include "nameserver.h"
#include "watcardoffice.h"
#include "watcard.h"
#include "vendingmachine.h"

class Printer;

class Student {

  protected:

  	Printer &prt;
  	NameServer &nameServer;
  	WATCardOffice &cardOffice;

  	unsigned int id;            // student id
    	unsigned int targetBottles;    // the number of bottles that the student need to buy
    	unsigned int currentBottles;    // the number of bottles that the student bought
    	VendingMachine::Flavours flavour;   // the flavour of the student's favourite soda

	WATCard *card; 
    	VendingMachine *vendingMachine;

  public:

    struct Finished {};            // exception raised on completion
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, 
             unsigned int id, unsigned int maxPurchases );    // constructor
    ~Student() { delete card; } // destructor
    void action();

};

#endif


