#include "wiindow.h"


Wiindow::Wiindow() : QWidget()
{

    //Front

    //Le tab
    QTabWidget *onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 240, 160);

    //Les onglets
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;

    //Page 1
    //Item
    //Box
    QVBoxLayout *vbox1 = new QVBoxLayout;
    page1->setLayout(vbox1);

    //Page 2
    //Item
    fermer = new QPushButton("Quiter", this);
    //Box
    QVBoxLayout *vbox2 = new QVBoxLayout;
    QPushButton *BoutonTest = new QPushButton("TEST");
    vbox2->addWidget(fermer);
    vbox2->addWidget(BoutonTest);
    page2->setLayout(vbox2);

    //Ajout au tab
    onglets->addTab(page1, "Stats");
    onglets->addTab(page2, "Settings");
    //Back
    connect(fermer, SIGNAL(clicked()), qApp, SLOT(quit()));
}

