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
	maxStockPerFlavour(maxStockPerFlavour)
{
	totalSoda = 0;
	for( unsigned int i=0; i<4; i++){
		cargo[i]=0;
	}
	prt.print(Printer::Truck, 'S');

} // Truck


void Truck::action() {


	plant.getShipment(cargo);	// get products from the bottling plant
	totalSoda = cargo[0] + cargo[1] + cargo[2] + cargo[3];	// total number of soda before delivery
	prt.print(Printer::Truck, 'P', totalSoda);
	VendingMachine **machineList = nameServer.getMachineList();	// get the vending machine list


	/* deliver to each vending machine in machineList */

	for( unsigned int i = 0; i < numVendingMachines; i++ ){

		if(totalSoda == 0){
			for( unsigned int i=0; i<4; i++){
				cargo[i]=0;
			}
			return;	// no more soda on the truck
		}

		unsigned int *stock = machineList[i]->inventory();	// get the stock of the vending machine
		prt.print(Printer::Truck, 'd', machineList[i]->getId(), totalSoda);

		unsigned int maxStock = maxStockPerFlavour * 4;
		unsigned int curStock = *stock + *(stock+1) + *(stock+2) + *(stock+3);

		
		/* fill in current vending machine */

		for( unsigned int j = 0; j < 4; j++ ){

			unsigned int demand = maxStockPerFlavour - *(stock+j);  
			
			if( totalSoda == 0 ) break;  // no more soda on the truck

			if( cargo[j] >= demand ){

				curStock += demand;
				*(stock+j) += demand;
				
				totalSoda -= demand;
				cargo[j] -= demand;

			}else{

				curStock += cargo[j];
				*(stock+j) += cargo[j];

				totalSoda -= cargo[j];
				cargo[j] = 0; 

			}

		} // for

		

		unsigned int notReplenished = maxStock - curStock;	// total number of bottles not replenished

		if( notReplenished != 0 ){	// not replenished
			prt.print(Printer::Truck, 'U', machineList[i]->getId(), notReplenished);
		}
	
		prt.print(Printer::Truck, 'D', machineList[i]->getId(), totalSoda);

		machineList[i]->restocked();

		
		if( totalSoda == 0 ) break;		// no more soda on the truck
	} // for
	
} // action
