#include "bottlingplant.h"
#include "PRNG.h"
#include "printer.h"
#include "truck.h"

extern PRNG prng;

BottlingPlant::BottlingPlant( Printer &prt, NameServer &nameServer,unsigned int numVendingMachines,
		unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour,
		unsigned int timeBetweenShipments ): prt(prt), nameServer(nameServer),
		numVendingMachines(numVendingMachines), maxShippedPerFlavour(maxShippedPerFlavour),
		maxStockPerFlavour(maxStockPerFlavour), timeBetweenShipments(timeBetweenShipments){

		prt.print(Printer::BottlingPlant, 'S');
		truck = new Truck(prt, nameServer, *this, numVendingMachines, maxStockPerFlavour);

		numBBC = prng(maxShippedPerFlavour);
		numCCS = prng(maxShippedPerFlavour);
		numRRB = prng(maxShippedPerFlavour);
		numJL = prng(maxShippedPerFlavour);
		totalSoda = numBBC + numCCS + numRRB + numJL;
		prt.print(Printer::BottlingPlant, 'G', totalSoda);

		truck->action();
		
}

BottlingPlant::~BottlingPlant(){ delete truck; }

void BottlingPlant::getShipment( unsigned int cargo[] ){

	prt.print(Printer::BottlingPlant, 'P');
	cargo[0] = numBBC;
	cargo[1] = numCCS;
	cargo[2] = numRRB;
	cargo[3] = numJL;

}

void BottlingPlant::action(){

	if( prng(4)==0 ){
		prt.print(Printer::BottlingPlant, 'X');
		return;
	}
	else{
		if( prng(timeBetweenShipments-1)!=0 ) return;
		else{

			numBBC = prng(maxShippedPerFlavour);
			numCCS = prng(maxShippedPerFlavour);
			numRRB = prng(maxShippedPerFlavour);
			numJL = prng(maxShippedPerFlavour);
			totalSoda = numBBC + numCCS + numRRB + numJL;
			prt.print(Printer::BottlingPlant, 'G', totalSoda);

			truck->action();

		}
	}

}

