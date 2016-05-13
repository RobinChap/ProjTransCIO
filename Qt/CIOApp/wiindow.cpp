#include "wiindow.h"
#include "proc.h"
#include "ram.h"


Wiindow::Wiindow() : QWidget()
{

    //Front

    //Le tab
    QTabWidget *onglets = new QTabWidget(this);
    onglets->setGeometry(30, 20, 400, 400);

    //Les onglets
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QWidget *page3 = new QWidget;

    //Page 1
    //Item

    ProcTxt = new QLabel("BlaBal Bonjoir");
    Proc = new QPushButton("Start", this);
    //Box
    QVBoxLayout *vbox1 = new QVBoxLayout;

    vbox1->addWidget(ProcTxt);
    vbox1->addWidget(Proc);
    page1->setLayout(vbox1);

    //Page 2
    //Item

    RAMTxt = new QLabel("BlaBal Bonjoir");
    RAM = new QPushButton("Start", this);
    //Box
    QVBoxLayout *vbox2 = new QVBoxLayout;

    vbox2->addWidget(RAMTxt);
    vbox2->addWidget(RAM);
    page2->setLayout(vbox2);

    //Page 3
    //Item
    fermer = new QPushButton("Quiter", this);
    IPfield = new QLineEdit;

    Port = new QSpinBox;
    Port->setMaximum(99999);

    IP = "IP:Port:";
    Info = new QLabel(IP);
    //Box
    QVBoxLayout *vbox3 = new QVBoxLayout;

    vbox3->addWidget(IPfield);
    vbox3->addWidget(Port);
    vbox3->addWidget(Info);
    vbox3->addWidget(fermer);
    page3->setLayout(vbox3);

    //Ajout au tab
    onglets->addTab(page1, "Proc");
    onglets->addTab(page2, "RAM");
    onglets->addTab(page3, "Settings");
    //Back
    connect(fermer, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(Port, SIGNAL(valueChanged(int)), this, SLOT(ChangePort(int)));
    QObject::connect(IPfield, SIGNAL(textChanged(QString)), this, SLOT(ChangeIP(QString)));
    QObject::connect(Proc, SIGNAL(clicked()), this, SLOT(ProcStat()));
    QObject::connect(RAM, SIGNAL(clicked()), this, SLOT(RAMStat()));
}

void Wiindow::ChangePort(int p_port){

    port = p_port;
    QString Sport = QString::number(port);
    Info->setText("IP: " + IP + " Port : " + Sport);
}

void Wiindow::ChangeIP(QString p_IP){
    IP = p_IP;
    QString Sport = QString::number(port);
    Info->setText("IP: " + IP + " Port : " + Sport);
}

QString Wiindow::getIP(){
    return IP;
}

int Wiindow::getPort(){
    return port;
}

void Wiindow::ProcStat(){

    QString program = "/home/robin/ProjTransCIO/Qt/CIOApp/CheckProc";
    QString Sport = QString::number(port);
    QStringList arguments;
    arguments << IP << Sport << "/home/robin/ProjTransCIO/Objet/Stat/stat2";

    QProcess *Process = new QProcess(this);
    Process->start(program, arguments);
    if(Process->waitForFinished()){
        QString result = Process->readAllStandardOutput();
        ProcTxt->setText(result);
    }
}

void Wiindow::RAMStat(){

    QString program = "/home/robin/ProjTransCIO/Qt/CIOApp/CheckProc";
    QString Sport = QString::number(port);
    QStringList arguments;
    arguments << IP << Sport << "/home/robin/ProjTransCIO/Objet/RAM/Ram";

    QProcess *Process = new QProcess(this);
    Process->start(program, arguments);
    if(Process->waitForFinished()){
        QString result = Process->readAllStandardOutput();
        RAMTxt->setText(result);
    }
}
