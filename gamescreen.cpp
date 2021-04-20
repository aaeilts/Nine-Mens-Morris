#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QDrag>

gamescreen::gamescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamescreen)
{
    ui->setupUi(this);

}

gamescreen::~gamescreen()
{
    delete ui;
}
