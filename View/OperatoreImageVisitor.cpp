#include "OperatoreImageVisitor.h"
#include "../Modello/Steward.h"
#include "../Modello/VVFF.h"
#include "../Modello/Sanitari.h"
#include "../Modello/ForzeArmate.h"

QPixmap OperatoreImageVisitor::getImage() {
    return image;
}

void OperatoreImageVisitor::visitSteward(Steward& steward){
    QPixmap uomo(":Icone/SM.png");
    QPixmap donna(":Icone/SF.png");
    if (steward.getsesso_op() == "M") {
        image = uomo;
    } else image = donna;
}
void OperatoreImageVisitor::visitVVFF(VVFF& vvff){
    QPixmap uomo(":Icone/VM.png");
    QPixmap donna(":Icone/VF.png");
    if (vvff.getsesso_op() == "M") {
        image = uomo;
    } else image = donna;
}
void OperatoreImageVisitor::visitSanitari(Sanitari& sanitari){
    QPixmap uomo(":Icone/MM.png");
    QPixmap donna(":Icone/MF.png");
    if (sanitari.getsesso_op() == "M") {
       image = uomo;
    } else image = donna;
}
void OperatoreImageVisitor::visitForzeArmate(ForzeArmate& forzearmate){
    QPixmap uomo(":Icone/FM.png");
    QPixmap donna(":Icone/FF.png");
    if (forzearmate.getsesso_op() == "M") {
        image = uomo;
    } else image = donna;
}
