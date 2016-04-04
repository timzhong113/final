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
	for( unsigned int i=0; i<numStudents; i++){
		dtn[i].sid = 0;
		dtn[i].mIndex = 0;
	}

	numStudentsRegister = 0;

	prt.print(Printer::NameServer, 'S');		

} // NameServer


NameServer::~NameServer(){

	delete [] machineList;
	delete [] dtn;
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

		dtn[j].mIndex = posn;
		//dtn[j].isDistributed = false;

	} // for

	prt.print(Printer::NameServer, 'R', vendingmachine->getId());

}  // VMregister


VendingMachine *NameServer::getMachine( unsigned int id ){

	if( numStudents != numStudentsRegister ){	// if the student want to get his(her) first vending machine
		
		dtn[numStudentsRegister].sid = id;
		//dtn[numStudentsRegister].isDistributed = true;
		prt.print(Printer::NameServer, 'N', id, machineList[dtn[numStudentsRegister].mIndex]->getId());
		numStudentsRegister++;
		return machineList[dtn[numStudentsRegister-1].mIndex];

	}else{	// if the student want to change a new vending machine

		/* get student's position in dtn */

		unsigned int posn=0;
		for( unsigned int i=0; i<numStudents; i++ ){
		
			if( dtn[i].sid == id ){
				posn = i;
				break;
			}

		}		
		
		if( dtn[posn].mIndex == numVendingMachines - 1 ){  // if current vending machine is the last one
			dtn[posn].mIndex = 0;		// set the new vending machine to be the first one
		}else{	// if current vending machine is not the last one
			dtn[posn].mIndex++;	// set the new vending machine to be the next one
		}

		prt.print(Printer::NameServer, 'N', id, machineList[dtn[posn].mIndex]->getId());
		return machineList[dtn[posn].mIndex];

	}

} // getMachine


VendingMachine **NameServer::getMachineList() { return machineList; }

