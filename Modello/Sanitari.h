#ifndef SANITARI_H
#define SANITARI_H

#include "ProntoIntervento.h"

class Sanitari: public ProntoIntervento {
public:
	Sanitari(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool segnalazione,
        std::string gruppo_op,
		bool blsd
	);
	
	bool getblsd() const;
    std::string getgruppo() const;
    virtual void accept(OperatoreVisitorInterface& operatore);

private:
    std::string gruppo_op_;		// gruppo di cui fa parte l'operatore sanitario
	bool blsd_;							// if true l'operatore ha l'autorizzazione per usare il defibrillatore, else no
};

#endif
