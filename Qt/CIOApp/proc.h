#ifndef PROC_H
#define PROC_H

#include <QWidget>

#include <QString>



#define LBUF 100

class Proc : public QWidget
{
    Q_OBJECT
public:
    explicit Proc(QWidget *parent = 0);
    void Procstat();
private:

signals:
    
public slots:
    
};

#endif // PROC_H
