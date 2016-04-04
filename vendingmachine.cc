#include "vendingmachine.h"
#include "PRNG.h"
#include "printer.h"
#include "nameserver.h"
#include <iostream>

using namespace std;

extern PRNG prng;


VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id, 
	unsigned int sodaCost, unsigned int maxStockPerFlavour ): prt(prt), nameServer(nameServer),
	id(id), sodaCost(sodaCost), maxStockPerFlavour(maxStockPerFlavour) 
{
	for( unsigned int i=0; i<4; i++){//initialize stock
		stock[i]=0;
	}
	prt.print(Printer::Vending, id, 'S', sodaCost);
	nameServer.VMregister(this);	// register this vending machine to the name server

} // VendingMachine


VendingMachine::~VendingMachine(){

	prt.print(Printer::Vending, id, 'F');

} // ~VendingMachine 


VendingMachine::Status VendingMachine::buy( Flavours flavour, WATCard *&card ){

	if( stock[flavour] == 0 ) return STOCK;		// out of stock
	if( card->getBalance() < sodaCost ) return FUNDS;	// insufficient balance

	card->charge(sodaCost);
	stock[flavour]--;	// current stock decreased by 1
	prt.print(Printer::Vending, id, 'B', flavour, stock[flavour]);
	return BUY;

} // buy


unsigned int VendingMachine::cost(){ return sodaCost; } // cost

unsigned int VendingMachine::getId(){ return id; } // getId


unsigned int *VendingMachine::inventory(){ 
	
	prt.print(Printer::Vending, id, 'r');
	return stock;

} // inventory


void VendingMachine::restocked(){ 

	prt.print(Printer::Vending, id, 'R'); 

} // restocked


VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer,
		unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ):
		VendingMachine( prt, nameServer, id, sodaCost, maxStockPerFlavour ) {}


VendingMachine::Status VendingMachineCardEater::buy( Flavours flavour, WATCard *&card ){

	if( stock[flavour] == 0 ){	// out of stock

		if( prng(9)==0 ){	// eat card ?
			delete card;
			card = 0;
		}

		return STOCK;
	}

	if( card->getBalance() < sodaCost ){	// insufficient balace
		
		if( prng(9)==0 ){	// eat card ?
			delete card;
			card = 0;
		}

		return FUNDS;
	}

	card->charge( sodaCost );
	stock[flavour]--;	// update stock
	
	prt.print(Printer::Vending, id, 'B', flavour, stock[flavour]);

	if( prng(9)==0 ){	// eat card?
		delete card;
		card = 0;
	}

	return BUY;

} // VendingMachineCardEater::buy


VendingMachineOverCharger::VendingMachineOverCharger( Printer &prt, NameServer &nameServer,
		unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ): 
		VendingMachine( prt, nameServer, id, sodaCost*2, maxStockPerFlavour ) {}
