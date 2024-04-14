#ifndef VVFF_H
#define VVFF_H

#include "ProntoIntervento.h"

class VVFF: public ProntoIntervento{
private:
	bool piattaforma_;
	
public:
	VVFF(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
		bool segnalazione,
		bool piattaforma
	);
    bool getpiattaforma() const;
    virtual void accept(OperatoreVisitorInterface& operatore);
};

#endif
