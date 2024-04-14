#include "Steward.h"

Steward::Steward(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool internazionale,
        int stipendio):
            Operatore(id, nome, cognome, status_attuale, sesso_op, eta), internazionale_(internazionale), stipendio_(stipendio) {}
			
bool Steward::getinternazionale() const {
	return internazionale_;
}

int Steward::getstipendio() const {;
	return stipendio_;
}

void Steward::accept(OperatoreVisitorInterface& visitor) {
    visitor.visitSteward(*this);
}
