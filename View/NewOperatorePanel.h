#ifndef NEWOPERATOREPANEL_H
#define NEWOPERATOREPANEL_H
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QPushButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QString>

class NewOperatorePanel : public QWidget {
    Q_OBJECT
private:
    QLabel *inserimento;
    QLabel *tipo;
    QComboBox *newtipo;
    QLabel *numeroid;
    QSpinBox *newnumeroid;
    QLabel *nome;
    QLineEdit *newnome;
    QLabel *cognome;
    QLineEdit *newcognome;
    QLabel *sesso;
    QComboBox *newsesso;
    QLabel *eta;
    QSpinBox *neweta;
    QLabel *stato;
    QCheckBox *newstato;
    QLabel *inter;
    QCheckBox *newinter;
    QLabel *stipendio;
    QSpinBox *newstipendio;
    QLabel *piattaforma;
    QCheckBox *newpiattaforma;
    QLabel *corpo;
    QComboBox *newcorpo;
    QLabel *arma;
    QCheckBox *newarma;
    QLabel *gruppo;
    QComboBox *newgruppo;
    QLabel *blsd;
    QCheckBox *newblsd;
    QPushButton *conferma;
public:
    NewOperatorePanel(QWidget *parent = 0);
    std::string getid() const;
    std::string getnome() const;
    std::string getcognome() const;
    std::string getsesso() const;
    unsigned int geteta() const;
    bool getstato() const;
    bool getinter() const;
    unsigned int getstipendio() const;
    bool getpiattaforma() const;
    std::string getcorpo() const;
    bool getarma() const;
    std::string getgruppo() const;
    bool getblsd() const;
    void reset();
    void notvisible();
};

#endif // NEWOPERATOREPANEL_H
