#ifndef WATCARDOFFICE_H
#define WATCARDOFFICE_H

class Printer;
#include "watcard.h"

class WATCardOffice {

  protected:

  	Printer &prt;

  public:
  	
    WATCardOffice( Printer &prt );
    WATCard *create( unsigned int sid, unsigned int amount );
    void transfer( unsigned int sid, unsigned int amount, WATCard &card );
};

#endif

