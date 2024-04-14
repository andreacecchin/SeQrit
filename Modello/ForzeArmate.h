#ifndef FORZEARMATE_H
#define FORZEARMATE_H

#include "ProntoIntervento.h"

class ForzeArmate: public ProntoIntervento {
public:
	
	ForzeArmate(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool segnalazione,
        std::string corpo_op,
		bool arma
	);
	
    std::string getcorpo() const;
    bool getarma() const;
    virtual void accept(OperatoreVisitorInterface& operatore);

private:
    std::string corpo_;		// segnala a quale corpo di forze armate fa parte l'agente
    bool arma_;						// if true l'agente è dotato di arma da fuoco
		
};

#endif
