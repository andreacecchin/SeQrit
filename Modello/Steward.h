#ifndef STEWARD_H
#define STEWARD_H

#include "Operatore.h"

class Steward: public Operatore{
	
private:
	bool internazionale_;
    int stipendio_;
	
public:
	Steward(
        std::string id,
        std::string nome,
        std::string cognome,
		bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
		bool internazionale,
        int stipendio
	);
	
	bool getinternazionale() const;
    int getstipendio() const;
    virtual void accept(OperatoreVisitorInterface& operatore);
};

#endif
