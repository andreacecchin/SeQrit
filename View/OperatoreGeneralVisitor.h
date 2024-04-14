#ifndef OPERATOREGENERALVISITOR_H
#define OPERATOREGENERALVISITOR_H

#include <QString>
#include "../Modello/OperatoreVisitorInterface.h"


class OperatoreGeneralVisitor : public OperatoreVisitorInterface {
private:
    QString *widget;
public:
    QString *getWidget();

    virtual void visitSteward(Steward& steward);
    virtual void visitVVFF(VVFF& vvff);
    virtual void visitSanitari(Sanitari& sanitari);
    virtual void visitForzeArmate(ForzeArmate& forzearmate);

};

#endif // OPERATOREGENERALVISITOR_H
