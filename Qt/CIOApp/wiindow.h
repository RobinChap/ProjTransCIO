#ifndef WIINDOW_H
#define WIINDOW_H

#include <QWidget>
#include <QtWidgets>
#include <QPushButton>
#include <QObject>
#include <QApplication>

class Wiindow : public QWidget
{

public:
    Wiindow();
private:
    QPushButton *fermer;
};

#endif // WIINDOW_H
