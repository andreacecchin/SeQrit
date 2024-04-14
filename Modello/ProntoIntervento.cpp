#include "ProntoIntervento.h"

ProntoIntervento::ProntoIntervento(
        std::string id,
        std::string nome,
        std::string cognome,
        bool status_attuale,
        std::string sesso_op,
        unsigned int eta,
        bool segnalazione):
			Operatore(
                id,
                nome,
				cognome,
				status_attuale,
				sesso_op,
				eta),
				segnalazione_(segnalazione) {}

ProntoIntervento::~ProntoIntervento() = default;

bool ProntoIntervento::getsegnalazione() const {
	return segnalazione_;
}
