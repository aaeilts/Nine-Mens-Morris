#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QMainWindow>
#include "gamescreen.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TitleScreen; }
QT_END_NAMESPACE

class TitleScreen : public QMainWindow
{
    Q_OBJECT

public:
    TitleScreen(QWidget *parent = nullptr);
    ~TitleScreen();

private slots:
    void on_pushButton_clicked();

private:
    Ui::TitleScreen *ui;
    gamescreen *gameScreen;
};
#endif // TITLESCREEN_H
