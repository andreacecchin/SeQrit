#ifndef OPERATOREWARNINGVISITOR_H
#define OPERATOREWARNINGVISITOR_H

#include "../Modello/OperatoreVisitorInterface.h"


class OperatoreWarningVisitor : public OperatoreVisitorInterface {
private:
    bool warning;
public:
    bool getBool();

    virtual void visitSteward(Steward& steward);
    virtual void visitVVFF(VVFF& vvff);
    virtual void visitSanitari(Sanitari& sanitari);
    virtual void visitForzeArmate(ForzeArmate& forzearmate);

};

#endif // OPERATOREWARNINGVISITOR_H
