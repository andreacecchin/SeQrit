QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Modello/ForzeArmate.cpp \
    Modello/Operatore.cpp \
    Modello/ProntoIntervento.cpp \
    Modello/Sanitari.cpp \
    Modello/Steward.cpp \
    Modello/VVFF.cpp \
    View/NewOperatorePanel.cpp \
    View/OperatoreGeneralVisitor.cpp \
    View/OperatoreImageVisitor.cpp \
    View/OperatoreInfoVisitor.cpp \
    View/OperatoreStatoVisitor.cpp \
    View/OperatoreWarningVisitor.cpp \
    View/Window.cpp \
    main.cpp

HEADERS += \
    Modello/Array.h \
    Modello/ForzeArmate.h \
    Modello/Operatore.h \
    Modello/OperatoreVisitorInterface.h \
    Modello/ProntoIntervento.h \
    Modello/Sanitari.h \
    Modello/Steward.h \
    Modello/VVFF.h \
    View/NewOperatorePanel.h \
    View/OperatoreGeneralVisitor.h \
    View/OperatoreImageVisitor.h \
    View/OperatoreInfoVisitor.h \
    View/OperatoreStatoVisitor.h \
    View/OperatoreWarningVisitor.h \
    View/Window.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
