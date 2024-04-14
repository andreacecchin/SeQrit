#include "NewOperatorePanel.h"

NewOperatorePanel::NewOperatorePanel(QWidget *parent) : QWidget(parent) {

    inserimento = new QLabel("INSERIMENTO DATI\nNUOVO OPERATORE");
    inserimento->setStyleSheet("font-weight: bold; font-size: 14pt");
    inserimento->setAlignment(Qt::AlignCenter);

    tipo = new QLabel("Ruolo: ");
    newtipo = new QComboBox();
    newtipo->addItem("Steward");
    newtipo->addItem("Medico");
    newtipo->addItem("Forza dell'ordine");
    newtipo->addItem("Vigile del fuoco");
    QHBoxLayout *tipoh = new QHBoxLayout();
    tipoh->addWidget(tipo);
    tipoh->addWidget(newtipo);

    numeroid = new QLabel("Numero ID: ");
    newnumeroid = new QSpinBox();
    newnumeroid->setMinimum(1);
    newnumeroid->setMaximum(99);
    QHBoxLayout *numeroidh = new QHBoxLayout();
    numeroidh->addWidget(numeroid);
    numeroidh->addWidget(newnumeroid);

    nome = new QLabel("Nome:        ");
    newnome = new QLineEdit();
    QHBoxLayout *nomeh = new QHBoxLayout();
    nomeh->addWidget(nome);
    nomeh->addWidget(newnome);

    cognome = new QLabel("Cognome: ");
    newcognome = new QLineEdit();
    QHBoxLayout *cognomeh = new QHBoxLayout();
    cognomeh->addWidget(cognome);
    cognomeh->addWidget(newcognome);

    sesso = new QLabel("Sesso: ");
    newsesso = new QComboBox();
    newsesso->addItem("Maschio");
    newsesso->addItem("Femmina");
    QHBoxLayout *sessoh = new QHBoxLayout();
    sessoh->addWidget(sesso);
    sessoh->addWidget(newsesso);

    eta = new QLabel("Età: ");
    neweta = new QSpinBox();
    neweta->setMinimum(18);
    neweta->setMaximum(70);
    QHBoxLayout *etah = new QHBoxLayout();
    etah->addWidget(eta);
    etah->addWidget(neweta);

    inter = new QLabel("Internazionale? ");
    newinter = new QCheckBox();
    QHBoxLayout *interh = new QHBoxLayout();
    interh->addWidget(inter);
    interh->addWidget(newinter);

    stipendio = new QLabel("Stipendio: ");
    newstipendio = new QSpinBox();
    newstipendio->setMinimum(1);
    newstipendio->setMaximum(10);
    QHBoxLayout *stipendioh = new QHBoxLayout();
    stipendioh->addWidget(stipendio);
    stipendioh->addWidget(newstipendio);

    piattaforma = new QLabel("Autorizzazione\npiattaforma? ");
    newpiattaforma = new QCheckBox();
    QHBoxLayout *piattaformah = new QHBoxLayout();
    piattaformah->addWidget(piattaforma);
    piattaformah->addWidget(newpiattaforma);

    corpo = new QLabel("Corpo di appartenenza: ");
    newcorpo = new QComboBox();
    newcorpo->addItem("Polizia");
    newcorpo->addItem("Carabinieri");
    newcorpo->addItem("Esercito");
    QHBoxLayout *corpoh = new QHBoxLayout();
    corpoh->addWidget(corpo);
    corpoh->addWidget(newcorpo);

    arma = new QLabel("Arma da fuoco? ");
    newarma = new QCheckBox();
    QHBoxLayout *armah = new QHBoxLayout();
    armah->addWidget(arma);
    armah->addWidget(newarma);

    gruppo = new QLabel("Gruppo di appartenenza: ");
    newgruppo = new QComboBox();
    newgruppo->addItem("Croce Rossa");
    newgruppo->addItem("Croce Verde");
    QHBoxLayout *gruppoh = new QHBoxLayout();
    gruppoh->addWidget(gruppo);
    gruppoh->addWidget(newgruppo);

    blsd = new QLabel("Autorizzazione\ndefibrillatore? ");
    newblsd = new QCheckBox();
    QHBoxLayout *blsdh = new QHBoxLayout();
    blsdh->addWidget(blsd);
    blsdh->addWidget(newblsd);

    stato = new QLabel("Dispiegare? ");
    newstato = new QCheckBox();
    QHBoxLayout *statoh = new QHBoxLayout();
    statoh->addWidget(stato);
    statoh->addWidget(newstato);


    QVBoxLayout *finalenew = new QVBoxLayout(this);
    finalenew->addWidget(inserimento);
    finalenew->addLayout(tipoh);
    finalenew->addLayout(numeroidh);
    finalenew->addLayout(nomeh);
    finalenew->addLayout(cognomeh);
    finalenew->addLayout(sessoh);
    finalenew->addLayout(etah);
    finalenew->addLayout(interh);
    finalenew->addLayout(stipendioh);
    finalenew->addLayout(piattaformah);
    finalenew->addLayout(corpoh);
    finalenew->addLayout(armah);
    finalenew->addLayout(gruppoh);
    finalenew->addLayout(blsdh);
    finalenew->addLayout(statoh);

    finalenew->setAlignment(Qt::AlignTop);
    finalenew->setSpacing(30);

    connect(newtipo, &QComboBox::currentTextChanged, [this]{
        notvisible();
        if(newtipo->currentText() == "Steward") {
            stipendio->setVisible(true);
            newstipendio->setVisible(true);
            inter->setVisible(true);
            newinter->setVisible(true);
        }
        else if(newtipo->currentText() == "Medico") {
            gruppo->setVisible(true);
            newgruppo->setVisible(true);
            blsd->setVisible(true);
            newblsd->setVisible(true);
        }
        else if(newtipo->currentText() == "Forza dell'ordine") {
            corpo->setVisible(true);
            newcorpo->setVisible(true);
            arma->setVisible(true);
            newarma->setVisible(true);
        }
        else if(newtipo->currentText() == "Vigile del fuoco") {
            piattaforma->setVisible(true);
            newpiattaforma->setVisible(true);
        }
    });

}

std::string NewOperatorePanel::getid() const {
    int num = newnumeroid->value();
    QString numid;
    (num < 9) ? numid = "0" + QString::number(num) : numid = QString::number(num);
    QString finalid = newtipo->currentText().first(1) + numid;
    return finalid.toStdString();
}

std::string NewOperatorePanel::getnome() const {
    return (newnome->text()).toStdString();
}

std::string NewOperatorePanel::getcognome() const {
    return (newcognome->text()).toStdString();
}

std::string NewOperatorePanel::getsesso() const {
    return (newsesso->currentText().first(1)).toStdString();
}

unsigned int NewOperatorePanel::geteta() const {
    return neweta->value();
}

bool NewOperatorePanel::getinter() const {
    return newinter->isChecked();
}

unsigned int NewOperatorePanel::getstipendio() const {
    return newstipendio->value();
}

bool NewOperatorePanel::getstato() const {
    return newstato->isChecked();
}

bool NewOperatorePanel::getpiattaforma() const {
    return newpiattaforma->isChecked();
}

std::string NewOperatorePanel::getcorpo() const {
    return (newcorpo->currentText()).toStdString();
}

bool NewOperatorePanel::getarma() const {
    return newarma->isChecked();
}

std::string NewOperatorePanel::getgruppo() const {
    return (newgruppo->currentText()).toStdString();
}

bool NewOperatorePanel::getblsd() const {
    return newblsd->isChecked();
}

void NewOperatorePanel::reset() {
    newtipo->setCurrentText("Steward");
    newnumeroid->setValue(1);
    newnome->setText("");
    newcognome->setText("");
    newsesso->setCurrentText("Maschio");
    neweta->setValue(18);
    newinter->setCheckState(Qt::Unchecked);
    newstipendio->setValue(1);
    newstato->setCheckState(Qt::Unchecked);
    newpiattaforma->setCheckState(Qt::Unchecked);
    newcorpo->setCurrentText("Polizia");
    newarma->setCheckState(Qt::Unchecked);
    newgruppo->setCurrentText("Croce Rossa");
    newblsd->setCheckState(Qt::Unchecked);
    notvisible();
    inter->setVisible(true);
    newinter->setVisible(true);
    stipendio->setVisible(true);
    newstipendio->setVisible(true);
}

void NewOperatorePanel::notvisible() {
    inter->setVisible(false);
    newinter->setVisible(false);
    stipendio->setVisible(false);
    newstipendio->setVisible(false);
    piattaforma->setVisible(false);
    newpiattaforma->setVisible(false);
    corpo->setVisible(false);
    newcorpo->setVisible(false);
    arma->setVisible(false);
    newarma->setVisible(false);
    gruppo->setVisible(false);
    newgruppo->setVisible(false);
    blsd->setVisible(false);
    newblsd->setVisible(false);
}
