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
    int turnTracker = 0;
    ~gamescreen();

private slots:


    void on_space1_clicked();

    void on_space2_clicked();

    void on_space3_clicked();

    void on_space4_clicked();

    void on_space5_clicked();

    void on_space6_clicked();

    void on_space7_clicked();

    void on_space8_clicked();

    void on_space9_clicked();

    void on_space10_clicked();

    void on_space11_clicked();

    void on_space12_clicked();

    void on_space13_clicked();

    void on_space14_clicked();

    void on_space15_clicked();

    void on_space16_clicked();

    void on_space17_clicked();

    void on_space18_clicked();

    void on_space19_clicked();

    void on_space20_clicked();

    void on_space21_clicked();

    void on_space22_clicked();

    void on_space23_clicked();

    void on_space24_clicked();

private:
    Ui::gamescreen *ui;
};

#endif // GAMESCREEN_H
