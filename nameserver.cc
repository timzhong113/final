#include "nameserver.h"
#include "printer.h"
#include "vendingmachine.h"
#include <iostream>

using namespace std;


NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, unsigned int numStudents ): 
						prt(prt), numVendingMachines(numVendingMachines), numStudents(numStudents)
{

	/* initialize machineList */

	machineList = new VendingMachine*[numVendingMachines];

	for(  unsigned int i=0; i<numVendingMachines; i++ ){
		machineList[i] = 0;
	}

	dtn = new Distribution[numStudents];

	prt.print(Printer::NameServer, 'S');		

} // NameServer


NameServer::~NameServer(){

	delete [] machineList;

} // ~NameServer


void NameServer::VMregister( VendingMachine *vendingmachine ){


	/* store the vendingmachine to machineList */

	unsigned int posn = 0;	// store the location of the vendingmachine in machineList

	for( unsigned int i=0; i<numVendingMachines; i++ ){

		if( machineList[i] == 0 ){
			machineList[i] = vendingmachine;
			posn = i;
			break;
		}
	
	} // for


	/* assign the vendingmachine to students */

	for( unsigned int j = posn; j < numStudents; j += numVendingMachines ){

		cerr << j << endl;
		dtn[j].mIndex = posn;
		dtn[j].isDistributed = false;

	} // for

	prt.print(Printer::NameServer, 'R', vendingmachine->getId());

}  // VMregister


VendingMachine *NameServer::getMachine( unsigned int id ){

	if( !dtn[id].isDistributed ){	// if the student want to get his(her) first vending machine

		dtn[id].isDistributed = true;
		prt.print(Printer::NameServer, 'N', id, machineList[dtn[id].mIndex]->getId());

		return machineList[dtn[id].mIndex];

	}else{	// if the student want to change a new vending machine

		if( dtn[id].mIndex == numVendingMachines - 1 ){  // if current vending machine is the last one
			dtn[id].mIndex = 0;		// set the new vending machine to be the first one
		}else{	// if current vending machine is not the last one
			dtn[id].mIndex++;	// set the new vending machine to be the next one
		}

		prt.print(Printer::NameServer, 'N', id, machineList[dtn[id].mIndex]->getId());
		return machineList[dtn[id].mIndex];

	}

} // getMachine


VendingMachine **NameServer::getMachineList() { return machineList; }

