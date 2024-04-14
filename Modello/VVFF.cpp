#include "VVFF.h"

VVFF::VVFF(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool segnalazione,
        bool piattaforma):
            ProntoIntervento(id, nome, cognome, status_attuale, sesso_op, eta, segnalazione), piattaforma_(piattaforma) {}
			
bool VVFF::getpiattaforma() const {
	return piattaforma_;
}

void VVFF::accept(OperatoreVisitorInterface& visitor) {
    visitor.visitVVFF(*this);
}
