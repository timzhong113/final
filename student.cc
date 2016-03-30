#include "student.h"
#include "PRNG.h"
#include "printer.h"
#include <iostream>
using namespace std;
extern PRNG prng;


Student::Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, 
	unsigned int id, unsigned int maxPurchases ): prt(prt),nameServer(nameServer),
	cardOffice(cardOffice),id(id){

	cerr << "==== Student::Student" << endl;

	maxBottles = prng(1, maxPurchases);
	curBottles = 0;
	vendingMachine = nameServer.getMachine(id);


	/* create a WATCard */
	card = cardOffice.create(id, 5);


	/* initialize flavour */
	unsigned int flav = prng(3);  // choose a random flavour
	if(flav == 0) flavour = VendingMachine::BBC;
	else if(flav == 1) flavour = VendingMachine::CCS;
	else if(flav == 2) flavour = VendingMachine::RRB;
	else flavour = VendingMachine::JL;

	prt.print(Printer::Student, id, 'S', flavour, maxBottles);
	prt.print(Printer::Student, id, 'V', vendingMachine->getId());

}  // Student::constructor


void Student::action(){

	// cerr << "==== Student::action" << endl;

	if(curBottles == maxBottles){	// a student has purchased enough soda

		prt.print(Printer::Student, id, 'F');
		throw Finished();
		
	}else{

		VendingMachine::Status status = vendingMachine->buy(flavour, card);

		if(card == 0){

			card = cardOffice.create(id, 5);  // create a new card
			prt.print(Printer::Student, id, 'D');

		}

		if(status == VendingMachine::BUY){	// buy successfully

			curBottles++;
			prt.print(Printer::Student, id, 'B', card->getBalance());
			return;

		}else if(status == VendingMachine::FUNDS){	// insufficient funds, add money

			prt.print(Printer::Student, id, 't', vendingMachine->cost()+5);
			cardOffice.transfer(id, vendingMachine->cost()+5, *card);
			prt.print(Printer::Student, id, 'T', card->getBalance());
			return;

		}else{	// out of stock of favourate soda, change vending machine

			vendingMachine = nameServer.getMachine(id);	// get a new machine
			prt.print(Printer::Student, id, 'V', vendingMachine->getId());
			return;

		}

	}

}	// Student::action


