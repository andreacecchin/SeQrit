#include "OperatoreGeneralVisitor.h"
#include <QLabel>
#include <QString>

#include "../Modello/Steward.h"
#include "../Modello/VVFF.h"
#include "../Modello/Sanitari.h"
#include "../Modello/ForzeArmate.h"

QString* OperatoreGeneralVisitor::getWidget() {
    return widget;
}

void OperatoreGeneralVisitor::visitSteward(Steward& steward){
    QString stato;
    (steward.getstatus_attuale()) ? stato = "Dispiegato" : stato = "In attesa";
    widget = new QString("\nNome:             " + QString::fromStdString(steward.getnome()) + "\n\n" +
                        "Cognome:       " + QString::fromStdString(steward.getcognome()) + "\n\n" +
                        "Sesso:              " + QString::fromStdString(steward.getsesso_op()) + "\n\n" +
                        "Età:                   " + QString::number(steward.geteta()) + "\n\n" +
                        "Stato attuale:   " + stato + "\n");
}
void OperatoreGeneralVisitor::visitVVFF(VVFF& vvff){
    QString stato;
    (vvff.getstatus_attuale()) ? stato = "Dispiegato" : stato = "In attesa";
    widget = new QString("\nNome:             " + QString::fromStdString(vvff.getnome()) + "\n\n" +
                        "Cognome:       " + QString::fromStdString(vvff.getcognome()) + "\n\n" +
                        "Sesso:              " + QString::fromStdString(vvff.getsesso_op()) + "\n\n" +
                        "Età:                   " + QString::number(vvff.geteta()) + "\n\n" +
                        "Stato attuale:   " + stato + "\n");
}
void OperatoreGeneralVisitor::visitSanitari(Sanitari& sanitari){
    QString stato;
    (sanitari.getstatus_attuale()) ? stato = "Dispiegato" : stato = "In attesa";
    widget = new QString("\nNome:             " + QString::fromStdString(sanitari.getnome()) + "\n\n" +
                        "Cognome:       " + QString::fromStdString(sanitari.getcognome()) + "\n\n" +
                        "Sesso:              " + QString::fromStdString(sanitari.getsesso_op()) + "\n\n" +
                        "Età:                   " + QString::number(sanitari.geteta()) + "\n\n" +
                        "Stato attuale:   " + stato + "\n");
}
void OperatoreGeneralVisitor::visitForzeArmate(ForzeArmate& forzearmate){
    QString stato;
    (forzearmate.getstatus_attuale()) ? stato = "Dispiegato" : stato = "In attesa";
    widget = new QString("\nNome:             " + QString::fromStdString(forzearmate.getnome()) + "\n\n" +
                        "Cognome:       " + QString::fromStdString(forzearmate.getcognome()) + "\n\n" +
                        "Sesso:              " + QString::fromStdString(forzearmate.getsesso_op()) + "\n\n" +
                        "Età:                   " + QString::number(forzearmate.geteta()) + "\n\n" +
                        "Stato attuale:   " + stato + "\n");
}
