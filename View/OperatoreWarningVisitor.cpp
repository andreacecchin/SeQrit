#include "OperatoreWarningVisitor.h"
#include "../Modello/Steward.h"
#include "../Modello/VVFF.h"
#include "../Modello/Sanitari.h"
#include "../Modello/ForzeArmate.h"

bool OperatoreWarningVisitor::getBool() {
    return warning;
}

void OperatoreWarningVisitor::visitSteward(Steward& steward){
    steward.getid();    // per evitare il warning inutile che segnala il "non" utilizzo della variabile steward
    warning = false;
}
void OperatoreWarningVisitor::visitVVFF(VVFF& vvff){
    warning = vvff.getsegnalazione();
}
void OperatoreWarningVisitor::visitSanitari(Sanitari& sanitari){
    warning = sanitari.getsegnalazione();
}
void OperatoreWarningVisitor::visitForzeArmate(ForzeArmate& forzearmate){
    warning = forzearmate.getsegnalazione();

}
