#include "Window.h"
#include "OperatoreInfoVisitor.h"
#include "OperatoreGeneralVisitor.h"
#include "OperatoreStatoVisitor.h"
#include "OperatoreWarningVisitor.h"
#include "OperatoreImageVisitor.h"

Window::Window(QWidget *parent) : QWidget(parent) {
    this->setMinimumSize(1024,600);
    this->setStyleSheet("background-color: #5d5b59; color: white");
    this->setWindowTitle("SeQrit - San Siro Stadio");
    this->setWindowIcon(QIcon(":Icone/IconaApp"));

    //componenti principali della finestra
    Labellista= new QLabel("CODICI IDENTIFICATIVI OPERATORI");
    Labellista->setStyleSheet("font-weight: bold; font-size: 14pt");
    Labellista->setVisible(false);

    lista = new QListWidget();
    lista->setAlternatingRowColors(true);
    lista->setSortingEnabled(true);
    lista->setStyleSheet("alternate-background-color: #5d5b59;background-color: #868482;font-size: 15pt");

    ricercaid = new QLineEdit();
    ricercaid->setPlaceholderText("Inserisci ID da cercare:");
    ricercaid->setVisible(false);

    tastoricerca = new QPushButton("");
    tastoricerca->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_F));
    tastoricerca->setShortcutEnabled(false);
    tastoricerca->setIcon(QIcon(":Icone/IconaRicerca"));
    tastoricerca->resize(25, 25);
    tastoricerca->setVisible(false);

    QHBoxLayout *ricerca = new QHBoxLayout();
    ricerca->addWidget(ricercaid);
    ricerca->addWidget(tastoricerca);

    tastocaricamento = new QPushButton("Carica i dati presenti in D̲atabase");
    tastocaricamento->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_D));
    tastocaricamento->setStyleSheet("background-color:black; color:grey");

    QVBoxLayout *identita = new QVBoxLayout();
    identita->addWidget(Labellista);
    identita->addWidget(lista);
    identita->addWidget(tastocaricamento);
    identita->addLayout(ricerca);

    Labelinfo = new QLabel("INFORMAZIONI DELL'OPERATORE SELEZIONATO");
    Labelinfo->setStyleSheet("font-weight: bold; font-size: 14pt");
    Labelinfo->setVisible(false);
    PannelloImmagine = new QLabel();

    tastolicenzia = new QPushButton("C̲ancella operatore");
    tastolicenzia->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    tastolicenzia->setStyleSheet("background-color:black; color:grey");
    tastolicenzia->setVisible(false);
    tastolicenzia->setShortcutEnabled(false);
    tastomodificastato = new QPushButton("M̲odifica stato");
    tastomodificastato->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_M));
    tastomodificastato->setStyleSheet("background-color:black; color:grey");
    tastomodificastato->setShortcutEnabled(false);
    tastomodificastato->setVisible(false);

    PannelloGeneral = new QLabel();
    PannelloGeneral->setAlignment(Qt::AlignTop);
    PannelloGeneral->setStyleSheet("font-size: 12pt");
    PannelloInfo = new QLabel();
    PannelloInfo->setAlignment(Qt::AlignTop);
    PannelloInfo->setStyleSheet("font-size: 12pt");
    StatoImmagine = new QLabel();
    StatoImmagine->setAlignment(Qt::AlignLeft);
    Warning = new QLabel();
    QPixmap segnala(":Icone/IconaSegnalazione");
    Warning->setPixmap(segnala.scaledToHeight(30));
    Warning->setAlignment(Qt::AlignLeft);
    Warning->setVisible(false);

    QHBoxLayout *icon = new QHBoxLayout();
    icon->addWidget(StatoImmagine);
    icon->addWidget(Warning);
    icon->setAlignment(Qt::AlignLeft);

    QVBoxLayout *infosx = new QVBoxLayout();
    infosx->setAlignment(Qt::AlignTop);
    infosx->addWidget(Labelinfo);
    infosx->addWidget(PannelloGeneral);
    infosx->addLayout(icon);
    infosx->addWidget(PannelloInfo);

    QVBoxLayout *infodx = new QVBoxLayout();
    infodx->addWidget(PannelloImmagine);
    infodx->addStretch();
    infodx->addWidget(tastolicenzia);
    infodx->addWidget(tastomodificastato);

    QHBoxLayout *info = new QHBoxLayout();
    info->addLayout(infosx);
    info->addLayout(infodx);

    tastoassumi = new QPushButton("Aggiungi un n̲uovo operatore");
    tastoassumi->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_N));
    tastoassumi->setStyleSheet("background-color:black; color:grey");
    tastoassumi->setVisible(false);
    tastoassumi->setShortcutEnabled(false);

    QVBoxLayout *informazioni = new QVBoxLayout();
    informazioni->addLayout(info);
    informazioni->addWidget(tastoassumi);

    //logo dell'applicazione visibile durante l'apertura del programma
    logo = new QLabel();
    QPixmap logoapp(":Icone/Logo.png");
    logo->setPixmap(logoapp.scaledToHeight(300));

    //componenti per aggiungere un nuovo operatore
    QVBoxLayout *aggiungi = new QVBoxLayout();
    newoperatorepanel = new NewOperatorePanel();
    newoperatorepanel->setVisible(false);
    conferma = new QPushButton("Conferma");
    conferma->setStyleSheet("background-color:black; color:grey");
    conferma->setVisible(false);

    aggiungi->addWidget(newoperatorepanel);
    aggiungi->addStretch();
    aggiungi->addWidget(conferma);

    QHBoxLayout *layoutfinale = new QHBoxLayout();
    layoutfinale->addLayout(identita);
    layoutfinale->addLayout(aggiungi);
    layoutfinale->addStretch();
    layoutfinale->addWidget(logo);
    layoutfinale->addLayout(informazioni);
    setLayout(layoutfinale);

    //funzionamento dei bottoni - controllo di tutta l'applicazione
    connect(tastocaricamento, &QPushButton::clicked, [this]{
        database = QFileDialog::getOpenFileName(this, "Carica il Database","","Json (*.json)" );
        while ( database == "" ) {
             QMessageBox::critical(this, "Errore", "Caricamento del Database non avvenuto correttamente. Riprova.");
             database = QFileDialog::getOpenFileName(this, "Carica il Database","","Json (*.json)" );
        }
        tastocaricamento->setShortcutEnabled(false);
        logo->setVisible(false);
        Labellista->setVisible(true);
        tastoricerca->setVisible(true);
        tastoricerca->setShortcutEnabled(true);
        ricercaid->setVisible(true);
        caricamento(database);
        inizializzalista(lista);
        tastocaricamento->setVisible(false);
        tastoassumi->setVisible(true);
        tastoassumi->setShortcutEnabled(true);
     });
    connect(tastoricerca, &QPushButton::clicked, [this]{
        tastomodificastato->setVisible(false);
        tastomodificastato->setShortcutEnabled(false);
        tastolicenzia->setVisible(false);
        tastolicenzia->setShortcutEnabled(false);
        Labelinfo->setVisible(false);
        PannelloGeneral->clear();
        PannelloInfo->clear();
        PannelloImmagine->clear();
        StatoImmagine->clear();
        Warning->setVisible(false);
        ricercaoperatore(lista);
        ricercaid->setText("");
    });
    connect(tastomodificastato, &QPushButton::clicked, [this]{
        modifica();
        salvataggio(database);
        OperatoreStatoVisitor svisitor;
        OperatoreGeneralVisitor gvisitor;
        specifico()->accept(svisitor);
        StatoImmagine->setPixmap(svisitor.getWidget().scaledToHeight(30));
        specifico()->accept(gvisitor);
        PannelloGeneral->setText(*gvisitor.getWidget());
    });
    connect(tastolicenzia, &QPushButton::clicked, [this]{
        elimina();
        salvataggio(database);
        tastomodificastato->setVisible(false);
        tastomodificastato->setShortcutEnabled(false);
        tastolicenzia->setVisible(false);
        tastolicenzia->setShortcutEnabled(false);
        Labelinfo->setVisible(false);
        PannelloGeneral->clear();
        PannelloInfo->clear();
        PannelloImmagine->clear();
        StatoImmagine->clear();
        Warning->setVisible(false);
        ricercaid->setText("");
        ricercaoperatore(lista);
    });
    connect(lista, &QListWidget::currentRowChanged, [this]{
        Labelinfo->setVisible(true);

        OperatoreInfoVisitor visitor;
        OperatoreGeneralVisitor gvisitor;
        OperatoreStatoVisitor svisitor;
        OperatoreWarningVisitor wvisitor;
        OperatoreImageVisitor ivisitor;

        specifico()->accept(gvisitor);
        PannelloGeneral->setText(*gvisitor.getWidget());
        specifico()->accept(svisitor);
        StatoImmagine->setPixmap(svisitor.getWidget().scaledToHeight(30));
        specifico()->accept(visitor);
        PannelloInfo->setText(*visitor.getWidget());
        specifico()->accept(wvisitor);
        Warning->setVisible( wvisitor.getBool() );
        specifico()->accept(ivisitor);
        PannelloImmagine->setPixmap(ivisitor.getImage().scaledToHeight(200));
        tastomodificastato->setVisible(true);
        tastomodificastato->setShortcutEnabled(true);
        tastolicenzia->setVisible(true);
        tastolicenzia->setShortcutEnabled(true);
    });
    connect(tastoassumi, &QPushButton::clicked, [this]{
        predisponiaggiunta();
        newoperatorepanel->reset();
    });
    connect(conferma, &QPushButton::clicked, [this]{
        if (checkid()) {
            QMessageBox::critical(this, "Errore", "Il codice ID selezionato è già assegnato ad un altro operatore. Modifica per continuare.");
        } else {
            if (checkname()) {
                QMessageBox::critical(this, "Errore", "Operatore deve avere in database un nome e un cognome. Modifica per continuare.");
            } else {
                aggiungisteward();
                postaggiunta();
                newoperatorepanel->reset();
                ricercaid->setText("");
                ricercaoperatore(lista);
            }
        }
    });
}





















void Window::caricamento(const QString database){
    QFile file(database);
    if (file.open(QIODevice::ReadOnly)) {
        QJsonDocument documento = QJsonDocument::fromJson(file.readAll());
        QJsonObject arrayobj = documento.object();
        QJsonArray array = arrayobj["Operatore"].toArray();
        for(int i=0;i < array.size(); i++){
            QJsonObject oggetto = array[i].toObject();
            QString id_operatore = oggetto["id"].toString();
            if (id_operatore[0] == 'S') {
                contenitore.aggiungi( new Steward(oggetto["id"].toString().toStdString(),
                                             oggetto["nome"].toString().toStdString(),
                                             oggetto["cognome"].toString().toStdString(),
                                             oggetto["status_attuale"].toBool(),
                                             oggetto["sesso"].toString().toStdString(),
                                             oggetto["eta"].toInt(),
                                             oggetto["internazionale"].toBool(),
                                             oggetto["stipendio"].toInt()
                                            ));
            }
            if (id_operatore[0] == 'V') {
                contenitore.aggiungi( new VVFF(oggetto["id"].toString().toStdString(),
                                          oggetto["nome"].toString().toStdString(),
                                          oggetto["cognome"].toString().toStdString(),
                                          oggetto["status_attuale"].toBool(),
                                          oggetto["sesso"].toString().toStdString(),
                                          oggetto["eta"].toInt(),
                                          oggetto["segnalazione"].toBool(),
                                          oggetto["piattaforma"].toBool()
                                         ));
            }
            if (id_operatore[0] == 'F') {
                contenitore.aggiungi( new ForzeArmate(oggetto["id"].toString().toStdString(),
                                                 oggetto["nome"].toString().toStdString(),
                                                 oggetto["cognome"].toString().toStdString(),
                                                 oggetto["status_attuale"].toBool(),
                                                 oggetto["sesso"].toString().toStdString(),
                                                 oggetto["eta"].toInt(),
                                                 oggetto["segnalazione"].toBool(),
                                                 oggetto["corpo_op"].toString().toStdString(),
                                                 oggetto["arma"].toBool()
                                                ));
            }
            if (id_operatore[0] == 'M') {
                contenitore.aggiungi( new Sanitari(oggetto["id"].toString().toStdString(),
                                              oggetto["nome"].toString().toStdString(),
                                              oggetto["cognome"].toString().toStdString(),
                                              oggetto["status_attuale"].toBool(),
                                              oggetto["sesso"].toString().toStdString(),
                                              oggetto["eta"].toInt(),
                                              oggetto["segnalazione"].toBool(),
                                              oggetto["gruppo_op"].toString().toStdString(),
                                              oggetto["blsd"].toBool()
                                             ));
            }
        }
        file.close();
    }
}

void Window::salvataggio(const QString database) {
    QFile file(database);
    if(file.open(QIODevice::WriteOnly)) {
        QJsonArray array;
        for(auto it = contenitore.begin(); it != contenitore.end(); ++it) {
            QJsonObject oggetto;
            if ( dynamic_cast<Steward*> (*it)) {
                oggetto.insert("id", QJsonValue::fromVariant(QString::fromStdString((*it)->getid())));
                oggetto.insert("nome", QJsonValue::fromVariant(QString::fromStdString((*it)->getnome())));
                oggetto.insert("cognome", QJsonValue::fromVariant(QString::fromStdString((*it)->getcognome())));
                oggetto.insert("status_attuale", QJsonValue::fromVariant((*it)->getstatus_attuale()));
                oggetto.insert("sesso", QJsonValue::fromVariant(QString::fromStdString((*it)->getsesso_op())));
                oggetto.insert("eta", QJsonValue::fromVariant((*it)->geteta()));
                oggetto.insert("internazionale", QJsonValue::fromVariant(static_cast<Steward*>(*it)->getinternazionale()));
                oggetto.insert("stipendio", QJsonValue::fromVariant(static_cast<Steward*>(*it)->getstipendio()));
            }
            if (dynamic_cast<VVFF*> (*it)) {
                oggetto.insert("id", QJsonValue::fromVariant(QString::fromStdString((*it)->getid())));
                oggetto.insert("nome", QJsonValue::fromVariant(QString::fromStdString((*it)->getnome())));
                oggetto.insert("cognome", QJsonValue::fromVariant(QString::fromStdString((*it)->getcognome())));
                oggetto.insert("status_attuale", QJsonValue::fromVariant((*it)->getstatus_attuale()));
                oggetto.insert("sesso", QJsonValue::fromVariant(QString::fromStdString((*it)->getsesso_op())));
                oggetto.insert("eta", QJsonValue::fromVariant((*it)->geteta()));
                oggetto.insert("segnalazione", QJsonValue::fromVariant(static_cast<VVFF*>(*it)->getsegnalazione()));
                oggetto.insert("piattaforma", QJsonValue::fromVariant(static_cast<VVFF*>(*it)->getpiattaforma()));
            }
            if (dynamic_cast<ForzeArmate*> (*it)) {
                oggetto.insert("id", QJsonValue::fromVariant(QString::fromStdString((*it)->getid())));
                oggetto.insert("nome", QJsonValue::fromVariant(QString::fromStdString((*it)->getnome())));
                oggetto.insert("cognome", QJsonValue::fromVariant(QString::fromStdString((*it)->getcognome())));
                oggetto.insert("status_attuale", QJsonValue::fromVariant((*it)->getstatus_attuale()));
                oggetto.insert("sesso", QJsonValue::fromVariant(QString::fromStdString((*it)->getsesso_op())));
                oggetto.insert("eta", QJsonValue::fromVariant((*it)->geteta()));
                oggetto.insert("segnalazione", QJsonValue::fromVariant(static_cast<ForzeArmate*>(*it)->getsegnalazione()));
                oggetto.insert("corpo_op", QJsonValue::fromVariant(QString::fromStdString(static_cast<ForzeArmate*>(*it)->getcorpo())));
                oggetto.insert("arma", QJsonValue::fromVariant(static_cast<ForzeArmate*>(*it)->getarma()));
            }
            if (dynamic_cast<Sanitari*> (*it)) {
                oggetto.insert("id", QJsonValue::fromVariant(QString::fromStdString((*it)->getid())));
                oggetto.insert("nome", QJsonValue::fromVariant(QString::fromStdString((*it)->getnome())));
                oggetto.insert("cognome", QJsonValue::fromVariant(QString::fromStdString((*it)->getcognome())));
                oggetto.insert("status_attuale", QJsonValue::fromVariant((*it)->getstatus_attuale()));
                oggetto.insert("sesso", QJsonValue::fromVariant(QString::fromStdString((*it)->getsesso_op())));
                oggetto.insert("eta", QJsonValue::fromVariant((*it)->geteta()));
                oggetto.insert("segnalazione", QJsonValue::fromVariant(static_cast<Sanitari*>(*it)->getsegnalazione()));
                oggetto.insert("gruppo_op", QJsonValue::fromVariant(QString::fromStdString(static_cast<Sanitari*>(*it)->getgruppo())));
                oggetto.insert("blsd", QJsonValue::fromVariant(static_cast<Sanitari*>(*it)->getblsd()));
            }
            array.append(oggetto);

        }
        QJsonObject arrayobj;
        arrayobj.insert(QString("Operatore"), QJsonValue(array));
        file.write(QJsonDocument(arrayobj).toJson());
        file.close();
    }
}

void Window::elimina() {
    std::string id_selezionato = (lista->currentItem()->text()).toStdString();
    for(auto it = contenitore.begin(); it!=contenitore.end(); ++it){
        if((*it)->getid()==id_selezionato) {
           contenitore.cancella(contenitore.cercapos(*it));
           break;
        }
    }
}

void Window::modifica() {
    std::string id_selezionato = (lista->currentItem()->text()).toStdString();
    for(auto it = contenitore.begin(); it != contenitore.end(); ++it){
        if((*it)->getid()==id_selezionato){
            (*it)->setstatus_attuale();
            break;
        }
    }
}

// returna il puntatore all'operatore attualmente indicato in list, così da poter chiamare su esso i visitor
Operatore* Window::specifico() {
    std::string id_selezionato = (lista->currentItem()->text()).toStdString();
    for(auto it = contenitore.begin(); it != contenitore.end(); ++it){
        if((*it)->getid() == id_selezionato){
            return (*it);
        }
    }
    //impossibile raggiungere la fine del ciclo senza un return
}

void Window::aggiungisteward() {
    std::string newruolo = newoperatorepanel->getid();
    if ( newruolo[0] == 'S' ) {
        contenitore.aggiungi( new Steward(newoperatorepanel->getid(),
                                     newoperatorepanel->getnome(),
                                     newoperatorepanel->getcognome(),
                                     newoperatorepanel->getstato(),
                                     newoperatorepanel->getsesso(),
                                     newoperatorepanel->geteta(),
                                     newoperatorepanel->getinter(),
                                     newoperatorepanel->getstipendio()
                                     ));
    }
    if ( newruolo[0] == 'M' ) {
        contenitore.aggiungi( new Sanitari(newoperatorepanel->getid(),
                                      newoperatorepanel->getnome(),
                                      newoperatorepanel->getcognome(),
                                      newoperatorepanel->getstato(),
                                      newoperatorepanel->getsesso(),
                                      newoperatorepanel->geteta(),
                                      false,
                                      newoperatorepanel->getgruppo(),
                                      newoperatorepanel->getblsd()
                                      ));
    }
    if ( newruolo[0] == 'F' ) {
        contenitore.aggiungi( new ForzeArmate(newoperatorepanel->getid(),
                                         newoperatorepanel->getnome(),
                                         newoperatorepanel->getcognome(),
                                         newoperatorepanel->getstato(),
                                         newoperatorepanel->getsesso(),
                                         newoperatorepanel->geteta(),
                                         false,
                                         newoperatorepanel->getcorpo(),
                                         newoperatorepanel->getarma()
                                         ));
    }
    if ( newruolo[0] == 'V' ) {
        contenitore.aggiungi( new VVFF(newoperatorepanel->getid(),
                                  newoperatorepanel->getnome(),
                                  newoperatorepanel->getcognome(),
                                  newoperatorepanel->getstato(),
                                  newoperatorepanel->getsesso(),
                                  newoperatorepanel->geteta(),
                                  false,
                                  newoperatorepanel->getpiattaforma()
                                  ));
    }
    salvataggio(database);
}









void Window::inizializzalista(QListWidget* lista) {
    lista->reset();
    lista->clear();
    for(auto it = contenitore.begin(); it != contenitore.end(); ++it) {
        QListWidgetItem* operat = new QListWidgetItem();
        operat->setText(QString::fromStdString((*it)->getid()));
        operat->setTextAlignment(Qt::AlignCenter);
        lista->addItem(operat);
    }
}

void Window::ricercaoperatore(QListWidget* lista){
    lista->reset();
    lista->clear();
    for(auto it = contenitore.begin(); it != contenitore.end(); ++it) {
        if((ricercaid->text().toStdString() == (*it)->getid()) || (ricercaid->text() == "")) {
            QListWidgetItem* id_cercato = new QListWidgetItem();
            id_cercato->setText(QString::fromStdString((*it)->getid()));
            id_cercato->setTextAlignment(Qt::AlignCenter);
            lista->addItem(id_cercato);
        }
    }
    if(lista->count() == 0){
        QMessageBox::critical(this, "ID non esistente", "Nessun operatore in database riporta tale codice identificativo.");
        ricercaid->setText("");
    }
}

void Window::predisponiaggiunta() {
    Labellista->setVisible(false);
    lista->setVisible(false);
    ricercaid->setVisible(false);
    tastoricerca->setVisible(false);
    tastoricerca->setShortcutEnabled(false);
    Labelinfo->setVisible(false);
    PannelloImmagine->clear();
    tastolicenzia->setVisible(false);
    tastolicenzia->setShortcutEnabled(false);
    tastomodificastato->setVisible(false);
    tastomodificastato->setShortcutEnabled(false);
    PannelloGeneral->clear();
    PannelloInfo->clear();
    StatoImmagine->clear();
    Warning->setVisible(false);
    tastoassumi->setVisible(false);
    tastoassumi->setShortcutEnabled(false);

    newoperatorepanel->setVisible(true);
    conferma->setVisible(true);
    logo->setVisible(true);
}

bool Window::checkid() {
    std::string search = newoperatorepanel->getid();
    for(auto it = contenitore.begin(); it != contenitore.end(); ++it) {
        if (search == (*it)->getid()) return true; //errore
    }
    return false; // tutto ok
}

bool Window::checkname() {
    std::string nome = newoperatorepanel->getnome();
    std::string cognome = newoperatorepanel->getcognome();
    if (nome == "" || cognome == "") return true; // errore
    return false; // tutto ok
}

void Window::postaggiunta() {
    Labellista->setVisible(true);
    lista->setVisible(true);
    ricercaid->setVisible(true);
    tastoricerca->setVisible(true);
    tastoricerca->setShortcutEnabled(true);
    Labelinfo->setVisible(false);
    tastoassumi->setVisible(true);
    tastoassumi->setShortcutEnabled(true);

    newoperatorepanel->setVisible(false);
    conferma->setVisible(false);

    logo->setVisible(false);
}
