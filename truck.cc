#include "truck.h"
#include "nameserver.h"
#include "printer.h"
#include "vendingmachine.h"
#include "bottlingplant.h"
#include <iostream>
using namespace std;

Truck::Truck( Printer &prt, NameServer &nameServer, BottlingPlant &plant,
	unsigned int numVendingMachines, unsigned int maxStockPerFlavour ):
	prt(prt), nameServer(nameServer), plant(plant), numVendingMachines(numVendingMachines),
	maxStockPerFlavour(maxStockPerFlavour), totalSoda(0){

		cerr << "==== Truck::Truck" << endl;
		
		prt.print(Printer::Truck, 'S');

}

void Truck::action(){

	plant.getShipment(cargo);
	totalSoda = cargo[0] + cargo[1] + cargo[2] + cargo[3];
	prt.print(Printer::Truck, 'P', totalSoda);

	VendingMachine **machineList = nameServer.getMachineList();


	for( unsigned int i=0; i<numVendingMachines; i++ ){
		unsigned int *stock = machineList[i]->inventory();
		prt.print(Printer::Truck, 'd', machineList[i]->getId(), totalSoda);
		unsigned int maxStock = maxStockPerFlavour*4;
		unsigned int curStock = 0;
		unsigned int notReplenished;

		for( unsigned int j=0; j<4; j++ ){
			unsigned int demand = maxStockPerFlavour - *(stock+j);  ////////////////////////////
			
			cerr << totalSoda << endl;
			cerr << *(stock+j) << " " << demand << " " << cargo[j] << endl;			
			if( totalSoda == 0 ) break;

			if( cargo[j] >= demand ){
				*(stock+j) += demand;
				cargo[j] -= demand;
				totalSoda -= demand;
			}else{
				*(stock+j) += cargo[j];
				totalSoda -= cargo[j];
				cargo[j] = 0;
			}
			curStock += *(stock+j);
		}//for

		notReplenished = maxStock-curStock;
		if( notReplenished != 0 ){
			prt.print(Printer::Truck, 'U', machineList[i]->getId(), notReplenished);
		}
		prt.print(Printer::Truck, 'D', machineList[i]->getId(), totalSoda);
		machineList[i]->restocked();
	}//for

}


