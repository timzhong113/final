#include "student.h"

extern PRNG::prng;

Student::Student( Printer &prt, NameServer &nameServer,
		 WATCardOffice &cardOffice, unsigned int id,
		 unsigned int maxPurchases ):prt(prt),nameServer(nameServer),
		cardOffice(cardOffice),id(id),maxPurchases(maxPurchases){
	unsigned int k = prng(3);
	if(k == 0) flavour = VendingMachine::Flavours::BBC;
	else if(k == 1) flavour = VendingMachine::Flavours::CCS;
	else if(k == 2) flavour = VendingMachine::Flavours::RRB;
	else flavour = VendingMachine::Flavours::JL;
}

void Student::action();
