#ifndef OPERATOREINFOVISITOR_H
#define OPERATOREINFOVISITOR_H

#include <QString>
#include "../Modello/OperatoreVisitorInterface.h"


class OperatoreInfoVisitor : public OperatoreVisitorInterface {
private:
    QString *widget;
public:
    QString *getWidget();

    virtual void visitSteward(Steward& steward);
    virtual void visitVVFF(VVFF& vvff);
    virtual void visitSanitari(Sanitari& sanitari);
    virtual void visitForzeArmate(ForzeArmate& forzearmate);

};

#endif // OPERATOREINFOVISITOR_H
