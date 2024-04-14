#ifndef OPERATORE_H
#define OPERATORE_H
#include <string>
#include "OperatoreVisitorInterface.h"

class Operatore {

public:
	
	Operatore();
	
	Operatore(
        std::string id,
        std::string nome,
        std::string cognome,
		bool status_attuale,
        std::string sesso_op,
        unsigned int eta
	);
	
    virtual ~Operatore() = 0;
    virtual void accept(OperatoreVisitorInterface& operatore) = 0;
    std::string getid() const;
    std::string getnome() const;
    std::string getcognome() const;
	bool getstatus_attuale() const;
    std::string getsesso_op() const;
    unsigned int geteta() const;
    void setstatus_attuale();
    bool operator==(const Operatore&) const;
    bool operator!=(const Operatore&) const;
	
private:
    std::string id_;
    std::string nome_;				// nome dell'operatore
    std::string cognome_;			// cognome dell'operatore
	bool status_attuale_;			// if true l'operatore è dispiegato, else in attesa
    std::string sesso_op_;		// sesso dell'operatore
    unsigned int eta_;			// età dell'operatore
		
};

#endif
