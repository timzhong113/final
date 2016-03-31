#include "bottlingplant.h"
#include "PRNG.h"
#include "printer.h"
#include "truck.h"
#include <iostream>
using namespace std;

extern PRNG prng;

BottlingPlant::BottlingPlant( Printer &prt, NameServer &nameServer,unsigned int numVendingMachines,
		unsigned int maxShippedPerFlavour, unsigned int maxStockPerFlavour, 
		unsigned int timeBetweenShipments ): prt(prt), nameServer(nameServer),
		numVendingMachines(numVendingMachines), maxShippedPerFlavour(maxShippedPerFlavour),
		maxStockPerFlavour(maxStockPerFlavour), timeBetweenShipments(timeBetweenShipments)
{

		prt.print(Printer::BottlingPlant, 'S');

		truck = new Truck(prt, nameServer, *this, numVendingMachines, maxStockPerFlavour);

		/* production run */

		numBBC = prng(maxShippedPerFlavour);
		numCCS = prng(maxShippedPerFlavour);
		numRRB = prng(maxShippedPerFlavour);
		numJL = prng(maxShippedPerFlavour);
		totalSoda = numBBC + numCCS + numRRB + numJL;

		prt.print(Printer::BottlingPlant, 'G', totalSoda);

		truck->action();  // distribute these bottles to initalize the registered vending machines
		
}  // BottlingPlant


BottlingPlant::~BottlingPlant(){ delete truck; }


void BottlingPlant::getShipment( unsigned int cargo[] ){

	prt.print(Printer::BottlingPlant, 'P');

	/* store number of each kind of products to cargo */

	cargo[0] = numBBC;
	cargo[1] = numCCS;
	cargo[2] = numRRB;
	cargo[3] = numJL;

}  // getShipment


void BottlingPlant::action(){

	if( prng(4)==0 ){	// on strike

		prt.print(Printer::BottlingPlant, 'X');
		return;
	
	}else{

		if( prng(timeBetweenShipments-1) != 0 ) {  // truck hasn't returned
		
			return;
		
		}else{	// truck has returned

			/* production run*/

			numBBC = prng(maxShippedPerFlavour);
			numCCS = prng(maxShippedPerFlavour);
			numRRB = prng(maxShippedPerFlavour);
			numJL = prng(maxShippedPerFlavour);
			totalSoda = numBBC + numCCS + numRRB + numJL;

			prt.print(Printer::BottlingPlant, 'G', totalSoda);

			truck->action();	// delivery

		}

	}

}  // action
