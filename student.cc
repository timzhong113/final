#include "student.h"
#include "PRNG.h"
#include "printer.h"
#include <iostream>
using namespace std;
extern PRNG prng;



Student::Student( Printer &prt, NameServer &nameServer, WATCardOffice &cardOffice, unsigned int id,
	unsigned int maxPurchases ): prt(prt), nameServer(nameServer), cardOffice(cardOffice),id(id)
{


	targetBottles = prng(1, maxPurchases);
	currentBottles = 0;

	/* get a VendingMachine */
	vendingMachine = nameServer.getMachine(id);


	/* create a WATCard */
	card = cardOffice.create(id, 5);


	/* setup favourite flavour */
	
	unsigned int flav = prng(3);  // choose a random flavour
	
	if(flav == 0) {
		flavour = VendingMachine::BBC;
	}else if(flav == 1) {
		flavour = VendingMachine::CCS;
	}else if(flav == 2) {
		flavour = VendingMachine::RRB;
	}else {
		flavour = VendingMachine::JL;
	}

	prt.print(Printer::Student, id, 'S', flavour, targetBottles);
	prt.print(Printer::Student, id, 'V', vendingMachine->getId());

}  // student



void Student::action(){


	if(currentBottles == targetBottles){	// a student has purchased enough soda


		prt.print(Printer::Student, id, 'F');
		throw Finished();

		
	}else{	// buy a soda from the vending machine


		VendingMachine::Status status = vendingMachine->buy(flavour, card);

		if(card == 0){	// card was destroyed

			prt.print(Printer::Student, id, 'D');
			card = cardOffice.create(id, 5);  // create a new card

		}

		if(status == VendingMachine::BUY){	// buy successfully

			currentBottles++;
			prt.print(Printer::Student, id, 'B', card->getBalance());
			return;

		}else if(status == VendingMachine::FUNDS){	// insufficient funds

			prt.print(Printer::Student, id, 't', vendingMachine->cost()+5);
			cardOffice.transfer( id, vendingMachine->cost() + 5, *card);	// add money to watcard
			prt.print(Printer::Student, id, 'T', card->getBalance());
			return;

		}else{	// vending machine was out of stock

			vendingMachine = nameServer.getMachine(id);	// get a new vending machine from nameserver
			prt.print(Printer::Student, id, 'V', vendingMachine->getId());
			return;

		}

	}

}  // action()

