#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QDialog>

namespace Ui {
class gamescreen;
}

class gamescreen : public QDialog
{
    Q_OBJECT

public:
    explicit gamescreen(QWidget *parent = nullptr);
    ~gamescreen();

private:
    Ui::gamescreen *ui;
};

#endif // GAMESCREEN_H
