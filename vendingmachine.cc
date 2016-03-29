#include "vendingmachine.h"
#include "PRNG.h"
#include "printer.h"

extern PRNG prng;

VendingMachine::VendingMachine( Printer &prt, NameServer &nameServer, unsigned int id,
	unsigned int sodaCost, unsigned int maxStockPerFlavour ): prt(prt), nameServer(nameServer),
	id(id), sodaCost(sodaCost), maxStockPerFlavour(maxStockPerFlavour) {

		prt.print(Printer::Vending, 'S', sodaCost);

	}

virtual VendingMachine::~VendingMachine(){

	prt.print(Printer::Vending, 'F');

}

virtual Status VendingMachine::buy( Flavours flavour, WATCard *&card ){

	if( stock[flavour] == 0 ) return STOCK;
	if( card->getBalance() < sodaCost ) return FUNDS;
	card->charge( sodaCost );
	stock[flavour]--;
	prt.print(Printer::Vending, 'B', flavour, stock[flavour]);
	return BUY;

}

virtual unsigned int VendingMachine::cost(){ return sodaCost; }

virtual unsigned int VendingMachine::getId(){ return id; }

virtual unsigned int *VendingMachine::inventory(){ 

	prt.print(Printer::Vending, 'r');
	return stock;

}

virtual void VendingMachine::restocked(){

	prt.print(Printer::Vending, 'R');
	return;

}

VendingMachineCardEater::VendingMachineCardEater( Printer &prt, NameServer &nameServer,
	unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ):
	VendingMachine( prt, nameServer, id, sodaCost, maxStockPerFlavour ) {}

Status VendingMachineCardEater::buy( Flavours flavour, WATCard *&card ){

	if( stock[flavour] == 0 ){

		if( prng(9)==0 ){
			delete card;
			card = 0;
		}
		return STOCK;
	}
	if( card->getBalance() < sodaCost ){
		
		if( prng(9)==0 ){
			delete card;
			card = 0;
		}
		return FUNDS;
	}
	card->charge( sodaCost );
	stock[flavour]--;
	prt.print(Printer::Vending, 'B', flavour, stock[flavour]);
	if( prng(9)==0 ){
		delete card;
		card = 0;
	}
	return BUY;

}

VendingMachineOverCharger::VendingMachineOverCharger( Printer &prt, NameServer &nameServer,
	unsigned int id, unsigned int sodaCost, unsigned int maxStockPerFlavour ): 
	VendingMachine( prt, nameServer, id, sodaCost*2, maxStockPerFlavour ) {}

