#ifndef WIINDOW_H
#define WIINDOW_H

#include <QWidget>
#include <QtGui>
#include <QPushButton>
#include <QObject>
#include <QApplication>
#include <QObject>
#include <QString>
#include <string>
#include <QProcess>

class Wiindow : public QWidget
{
    Q_OBJECT

public:
    Wiindow();
    int getPort();
    QString getIP();

public slots:
    void ChangePort(int p_port);
    void ChangeIP(QString p_IP);

    void ProcStat();
    void RAMStat();
private:
    int port;
    QString IP;
    QPushButton *fermer;
    QPushButton *Proc;
    QLabel *ProcTxt;
    QPushButton *RAM;
    QLabel *RAMTxt;
    QLineEdit *IPfield;
    QLabel *Info;
    QSpinBox *Port;
};

#endif // WIINDOW_H
