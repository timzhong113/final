#ifndef STUDENT_H
#define STUDENT_H

class Student {

  protected:

  	Printer &prt;
  	NameServer &nameServer;
  	WATCardOffice &cardOffice;
  	unsigned int id;
  	unsigned int maxPurchases;
  	WATCard *card;
  	VendingMachine::Flavours flavour;

  public:

    struct Finished {};            // exception raised on completion
    Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id, unsigned int maxPurchases );
    void action();
    ~Student() { delete card; } // destructor

};

#endif
