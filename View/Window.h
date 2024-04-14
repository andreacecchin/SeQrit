#ifndef WINDOW_H
#define WINDOW_H
#include <QWidget>
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QMessageBox>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QFileDialog>

#include "../Modello/Array.h"
#include "../Modello/Operatore.h"
#include "../Modello/Steward.h"
#include "../Modello/Sanitari.h"
#include "../Modello/VVFF.h"
#include "../Modello/ForzeArmate.h"
#include "NewOperatorePanel.h"


class Window: public QWidget {
    Q_OBJECT
private:
    QString database;
    Array<Operatore*> contenitore;
    QLabel *logo;
    QListWidget *lista;
    QLabel *Labellista;
    QLineEdit *ricercaid;
    QPushButton *tastoricerca;
    QPushButton *tastocaricamento;
    QPushButton *tastomodificastato;
    QPushButton *tastolicenzia;
    QLabel *Labelinfo;
    QLabel *PannelloImmagine;
    QLabel *PannelloInfo;
    QLabel *PannelloGeneral;
    QLabel *StatoImmagine;
    QLabel *Warning;
    QPushButton *tastoassumi;
    QPushButton *conferma;
    NewOperatorePanel *newoperatorepanel;

private slots:
    void inizializzalista(QListWidget*);
    void ricercaoperatore(QListWidget*);
    void caricamento(const QString);
    void salvataggio(const QString);
    void elimina();
    void modifica();
    void predisponiaggiunta();
    bool checkid();
    bool checkname();
    void postaggiunta();
    void aggiungisteward();
    Operatore* specifico();

public:
    Window(QWidget *parent = 0);
};

#endif
