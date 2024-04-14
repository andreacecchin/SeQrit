#include "Operatore.h"

Operatore::Operatore() {}

Operatore::Operatore(std::string id,std::string nome,std::string cognome,bool status_attuale,std::string sesso_op,unsigned int eta):
        id_(id),
		nome_(nome),
		cognome_(cognome),
		status_attuale_(status_attuale),
		sesso_op_(sesso_op),
		eta_(eta) {}
	
Operatore::~Operatore() = default;

std::string Operatore::getid() const {
    return id_;
}

std::string Operatore::getnome() const {
	return nome_;
}

std::string Operatore::getcognome() const {
	return cognome_;
}

bool Operatore::getstatus_attuale() const {
	return  status_attuale_;
}

std::string Operatore::getsesso_op() const {
	return sesso_op_;
}

unsigned int Operatore::geteta() const {
    return eta_;
}

void Operatore::setstatus_attuale () {
    if (getstatus_attuale()) status_attuale_ = false;
    else status_attuale_ = true;
}

bool Operatore::operator==(const Operatore& op) const {
    return (id_ == op.getid());
}

bool Operatore::operator!=(const Operatore& op) const {
    return (id_ != op.getid());
}
