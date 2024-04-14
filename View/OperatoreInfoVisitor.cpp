#include "OperatoreInfoVisitor.h"
#include "../Modello/Steward.h"
#include "../Modello/VVFF.h"
#include "../Modello/Sanitari.h"
#include "../Modello/ForzeArmate.h"

QString* OperatoreInfoVisitor::getWidget() {
    return widget;
}

void OperatoreInfoVisitor::visitSteward(Steward& steward){
    QString inter;
    (steward.getinternazionale() == true) ? inter = "Si" : inter = "No" ;
    widget = new QString("\nInternazionale:      " + inter + "\n\n" +
                        "Stipendio orario:   " + QString::number(steward.getstipendio()) + "€");
}
void OperatoreInfoVisitor::visitVVFF(VVFF& vvff){
    QString piatta;
    (vvff.getpiattaforma() == true) ? piatta = "Si" : piatta = "No" ;
    QString warning;
    (vvff.getsegnalazione() == true) ? warning = "Si" : warning = "No";
    widget = new QString("\nSegnalazione:   " + warning + "\n\n" +
                         "Autorizzato a utilizzare piattaforme sollevatrici:   " + piatta );
}
void OperatoreInfoVisitor::visitSanitari(Sanitari& sanitari){
    QString blsd;
    (sanitari.getblsd() == true) ? blsd = "Si" : blsd = "No";
    QString warning;
    (sanitari.getsegnalazione() == true) ? warning = "Si" : warning = "No";
    widget = new QString("\nSegnalazione:   " + warning + "\n\n" +
                        "Gruppo di appartenenza:   " + QString::fromStdString(sanitari.getgruppo()) + "\n\n" +
                        "Autorizzato a utilizzare defibrillatore semiautomatico:   " + blsd);
}
void OperatoreInfoVisitor::visitForzeArmate(ForzeArmate& forzearmate){
    QString arma;
    (forzearmate.getarma() == true) ? arma = "Arma da fuoco" : arma = "Taser elettrico";
    QString warning;
    (forzearmate.getsegnalazione() == true) ? warning = "Si" : warning = "No";
    widget = new QString("\nSegnalazione:   " + warning + "\n\n" +
                        "Corpo di appartenenza:   " + QString::fromStdString(forzearmate.getcorpo()) + "\n\n" +
                        "Arma in dotazione:           " + arma);
}
