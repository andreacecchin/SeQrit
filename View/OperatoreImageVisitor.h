#ifndef OPERATOREIMAGEVISITOR_H
#define OPERATOREIMAGEVISITOR_H

#include <QPixmap>
#include "../Modello/OperatoreVisitorInterface.h"


class OperatoreImageVisitor : public OperatoreVisitorInterface {
private:
    QPixmap image;
public:
    QPixmap getImage();

    virtual void visitSteward(Steward& steward);
    virtual void visitVVFF(VVFF& vvff);
    virtual void visitSanitari(Sanitari& sanitari);
    virtual void visitForzeArmate(ForzeArmate& forzearmate);

};

#endif // OPERATOREIMAGEVISITOR_H
