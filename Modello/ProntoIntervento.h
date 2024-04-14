#ifndef PRONTOINTERVENTO_H
#define PRONTOINTERVENTO_H

#include "Operatore.h"

class ProntoIntervento: public Operatore {
	
private:
	bool segnalazione_;
	
public:
	ProntoIntervento(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
		bool segnalazione
	);
	
    virtual ~ProntoIntervento() = 0;
    virtual void accept(OperatoreVisitorInterface& operatore) = 0;
	bool getsegnalazione() const ;
	
};

#endif
