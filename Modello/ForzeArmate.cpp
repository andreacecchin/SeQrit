#include "ForzeArmate.h"

ForzeArmate::ForzeArmate(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool segnalazione,
        std::string corpo_op,
		bool arma):
            ProntoIntervento(id, nome, cognome, status_attuale, sesso_op, eta, segnalazione), corpo_(corpo_op), arma_(arma) {}
			
std::string ForzeArmate::getcorpo() const {
	return corpo_;
}

bool ForzeArmate::getarma() const {
	return arma_;
}

void ForzeArmate::accept(OperatoreVisitorInterface& visitor) {
    visitor.visitForzeArmate(*this);
}
