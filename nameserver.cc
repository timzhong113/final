#include "nameserver.h"
#include "printer.h"
#include "vendingmachine.h"
#include <iostream>
using namespace std;

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, 
	unsigned int numStudents ): prt(prt), numVendingMachines(numVendingMachines),
	numStudents(numStudents){

	cerr << "==== NameServer::NameServer" << endl;

	machineList = new VendingMachine*[numVendingMachines];	
	for(  unsigned int i=0; i<numVendingMachines; i++ ){
		machineList[i] = 0;
	}

	dtn = new Distribution[numStudents];

	prt.print(Printer::NameServer, 'S');		
}

NameServer::~NameServer(){

	delete [] machineList;

}

void NameServer::VMregister( VendingMachine *vendingmachine ){

	cerr << "==== NameServer::VMregister" << endl;
	unsigned int posn = 0;
	for( unsigned int i=0; i<numVendingMachines; i++ ){

		if( machineList[i] == 0 ){
			machineList[i] = vendingmachine;
			posn = i;
			break;
		}
	}//for

	for( unsigned int j=posn; j<numStudents; j+=numVendingMachines ){
		cerr << j << endl;
		dtn[j].mIndex = posn;
		dtn[j].isDistributed = false;
	}//for

	prt.print(Printer::NameServer, 'R', vendingmachine->getId());
}

VendingMachine *NameServer::getMachine( unsigned int id ){

	if( !dtn[id].isDistributed ){

		dtn[id].isDistributed = true;
		prt.print(Printer::NameServer, 'N', id, machineList[dtn[id].mIndex]->getId());
		return machineList[dtn[id].mIndex];

	}else{

		if( dtn[id].mIndex == numVendingMachines-1 ) dtn[id].mIndex=0;
		else dtn[id].mIndex++;
		prt.print(Printer::NameServer, 'N', id, machineList[dtn[id].mIndex]->getId());
		return machineList[dtn[id].mIndex];

	}

}

VendingMachine **NameServer::getMachineList(){
	return machineList;
}


