#include "OperatoreStatoVisitor.h"
#include "../Modello/Steward.h"
#include "../Modello/VVFF.h"
#include "../Modello/Sanitari.h"
#include "../Modello/ForzeArmate.h"

QPixmap OperatoreStatoVisitor::getWidget() {
    return widget;
}

void OperatoreStatoVisitor::visitSteward(Steward& steward){
    QPixmap dispiegato(":Icone/IconaSchierato.png");
    QPixmap attesa(":Icone/IconaAttesa.png");
    if (steward.getstatus_attuale()) {
        widget = dispiegato;
    } else widget = attesa;
}
void OperatoreStatoVisitor::visitVVFF(VVFF& vvff){
    QPixmap dispiegato(":Icone/IconaSchierato.png");
    QPixmap attesa(":Icone/IconaAttesa.png");
    if (vvff.getstatus_attuale()) {
        widget = dispiegato;
    } else widget = attesa;
}
void OperatoreStatoVisitor::visitSanitari(Sanitari& sanitari){
    QPixmap dispiegato(":Icone/IconaSchierato.png");
    QPixmap attesa(":Icone/IconaAttesa.png");
    if (sanitari.getstatus_attuale()) {
        widget = dispiegato;
    } else widget = attesa;
}
void OperatoreStatoVisitor::visitForzeArmate(ForzeArmate& forzearmate){
    QPixmap dispiegato(":Icone/IconaSchierato.png");
    QPixmap attesa(":Icone/IconaAttesa.png");
    if (forzearmate.getstatus_attuale()) {
        widget = dispiegato;
    } else widget = attesa;
}
