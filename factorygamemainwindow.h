#ifndef FACTORYGAMEMAINWINDOW_H
#define FACTORYGAMEMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class FactoryGameMainWindow;
}

class FactoryGameMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit FactoryGameMainWindow(QWidget *parent = 0);
    ~FactoryGameMainWindow();

private:
    Ui::FactoryGameMainWindow *ui;
};

#endif // FACTORYGAMEMAINWINDOW_H
