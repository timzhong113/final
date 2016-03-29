#ifndef WATCARDOFFICE_H
#define WATCARDOFFICE_H

#include "soda.h"

class WATCardOffice {

  protected:

  	Printer &prt;

  public:
  	
    WATCardOffice( Printer &prt );
    WATCard *create( unsigned int sid, unsigned int amount );
    void transfer( unsigned int sid, unsigned int amount, WATCard &card );
};

#endif

