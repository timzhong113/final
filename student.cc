#include "student.h"

extern PRNG::prng;


Student::Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, 
	unsigned int id, unsigned int maxPurchases ): prt(prt),nameServer(nameServer),
	cardOffice(cardOffice),id(id){


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

	prt.print(Printer::student, 'S', flavour, maxBottles);
	prt.print(Printer::student, 'V', vendingMachine->id);

}  // Student::constructor


void Student::action(){

	if(curBottles == maxBottles){	// a student has purchased enough soda

		prt.print(Printer::Student, 'F');
		throw Finished();
		
	}else{

		VendingMachine::Status status = vendingMachine->buy(flavour, card);

		if(card == 0) card = cardOffice.create(id, 5);  // create a new card

		if(status == VendingMachine::BUY){	// buy successfully

			return;

		}else if(status == VendingMachine::FUNDS){	// insufficient funds, add money

			cardOffice.transfer(id, 5, card);
			return;

		}else{	// out of stock of favourate soda, change vending machine

			vendingMachine = nameServer.getMachine(id);	// get a new machine
			return;

		}

	}

}	// Student::action
