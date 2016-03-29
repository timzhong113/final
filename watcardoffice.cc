#include "watcardoffice.h"


WATCardOffice::WATCardOffice( Printer &prt );

WATCard *WATCardOffice::create( unsigned int sid, unsigned int amount );

void WATCardOffice::transfer( unsigned int sid, unsigned int amount, WATCard &card );
