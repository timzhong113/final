#include "watcardoffice.h"
#include "PRNG.h"
#include "printer.h"

extern PRNG prng;

WATCardOffice::WATCardOffice( Printer &prt ): prt(prt){

	prt.print(Printer::WATCardOffice, 'S');

}

WATCard *WATCardOffice::create( unsigned int sid, unsigned int amount ){

	WATCard *card = new WATCard();
	card->addBalance(amount);
	prt.print(Printer::WATCardOffice, 'C', sid, amount);
	return card;

}

void WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard &card ){

	prt.print(Printer::WATCardOffice, 't', sid, amount);
	if( prng(3)==0 ) amount = amount/2;
	card.addBalance(amount);
	prt.print(Printer::WATCardOffice, 'T', sid, amount);
	return;

}

