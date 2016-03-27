#ifndef WATCARDOFFICE_H
#define WATCARDOFFICE_H

class WATCardOffice {
  public:
    WATCardOffice( Printer &prt );
    WATCard *create( unsigned int sid, unsigned int amount );
    void transfer( unsigned int sid, unsigned int amount, WATCard &card );
};

#endif
