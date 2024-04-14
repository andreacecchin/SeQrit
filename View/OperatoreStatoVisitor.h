#ifndef OPERATORESTATOVISITOR_H
#define OPERATORESTATOVISITOR_H

#include <QPixmap>
#include "../Modello/OperatoreVisitorInterface.h"


class OperatoreStatoVisitor : public OperatoreVisitorInterface {
private:
    QPixmap widget;
public:
    QPixmap getWidget();

    virtual void visitSteward(Steward& steward);
    virtual void visitVVFF(VVFF& vvff);
    virtual void visitSanitari(Sanitari& sanitari);
    virtual void visitForzeArmate(ForzeArmate& forzearmate);

};

#endif // OPERATORESTATOVISITOR_H
