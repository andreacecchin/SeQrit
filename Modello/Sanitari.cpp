#include "Sanitari.h"

Sanitari::Sanitari(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool segnalazione,
        std::string gruppo_op,
		bool blsd):
            ProntoIntervento(id, nome, cognome, status_attuale, sesso_op, eta, segnalazione), gruppo_op_(gruppo_op), blsd_(blsd) {}
			
std::string Sanitari::getgruppo() const {
	return gruppo_op_;
}

bool Sanitari::getblsd() const {
	return blsd_;
}

void Sanitari::accept(OperatoreVisitorInterface& visitor) {
    visitor.visitSanitari(*this);
}
