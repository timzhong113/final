#include "watcardoffice.h"
#include "PRNG.h"
#include "printer.h"
#include <iostream>

using namespace std;

extern PRNG prng;


WATCardOffice::WATCardOffice( Printer &prt ): prt(prt){

	prt.print(Printer::WATCardOffice, 'S');

}  // constructor


WATCard *WATCardOffice::create( unsigned int sid, unsigned int amount ){

	WATCard *card = new WATCard();
	card->addBalance(amount);
	prt.print(Printer::WATCardOffice, 'C', sid, amount);
	return card;

}  // create


void WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard &card ){

	prt.print(Printer::WATCardOffice, 't', sid, amount);
	if( prng(3)==0 ) amount = amount/2;		// 1/4 chance only deposit 1/2 amount
	card.addBalance(amount);
	prt.print(Printer::WATCardOffice, 'T', sid, amount);
	return;

}  // transfer
