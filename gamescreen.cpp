#include "gamescreen.h"
#include "ui_gamescreen.h"

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
