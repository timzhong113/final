#ifndef WATCARDOFFICE_H
#define WATCARDOFFICE_H

#include "watcard.h"
class Printer;


class WATCardOffice {

	protected:
		Printer &prt;

	public:
  	
    	WATCardOffice( Printer &prt );	// constructor
    	WATCard *create( unsigned int sid, unsigned int amount );	// create a new watcard
    	void transfer( unsigned int sid, unsigned int amount, WATCard &card );

};


#endif
