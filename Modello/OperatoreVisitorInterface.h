#ifndef OPERATOREVISITORINTERFACE_H
#define OPERATOREVISITORINTERFACE_H

class Steward;
class VVFF;
class Sanitari;
class ForzeArmate;

class OperatoreVisitorInterface {

  public:
    virtual ~OperatoreVisitorInterface() = default;
    virtual void visitSteward(Steward& steward) = 0;
    virtual void visitVVFF(VVFF& vvff) = 0;
    virtual void visitSanitari(Sanitari& sanitari) = 0;
    virtual void visitForzeArmate(ForzeArmate& forzearmate) = 0;

};

#endif // OPERATOREVISITORINTERFACE_H
