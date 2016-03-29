#include "nameserver.h"

NameServer::NameServer( Printer &prt, unsigned int numVendingMachines, 
	unsigned int numStudents ): prt(prt), numVendingMachines(numVendingMachines),
	numStudents(numStudents){
	
	for(  unsigned int i=0; i<numVendingMachines; i++ ){
		machineList[i] = 0;
	}
	prt.print(Printer::NameServer, 'S');		
}

void NameServer::VMregister( VendingMachine *vendingmachine ){

	unsigned int posn=0;
	for( unsigned int i=0; i<numVendingMachines; i++ ){
		if( !machineList[i] ){
			machineList[i] = vendingmachine;
			posn = i;
			break;
		}
	}//for

	for( unsigned int j=posn; j<numStudents; j+=numVendingMachines ){
		dtn[j].mIndex = posn;
		dtn[j].isDistributed = false;
	}//for

	prt.print(Printer::NameServer, 'R', vendingmachine->id);
}

VendingMachine *NameServer::getMachine( unsigned int id ){

	if( !dtn[id].isDistributed ){

		dtn[id].isDistributed = true;
		return machineList[dtn[id].mIndex];

	}else{

		if( dtn[id].mIndex == numVendingMachines-1 ) dtn[id].mIndex=0;
		else dtn[id].mIndex++;
		prt.print(Printer::NameServer, 'N', id, machineList[dtn[id].mIndex]->id);
		return machineList[dtn[id].mIndex];

	}

}

VendingMachine **NameServer::getMachineList(){
	return machineList;
}
