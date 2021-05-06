#include "titlescreen.h"
#include "ui_titlescreen.h"


TitleScreen::TitleScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TitleScreen)
{
    ui->setupUi(this);
}

TitleScreen::~TitleScreen()
{
    delete ui;
}


void TitleScreen::on_pushButton_clicked()
{
//    gamescreen gameScreen;
//    gameScreen.setModal(true);
//    gameScreen.exec();

    hide();                                 //Hides title window when opening second window
    gameScreen = new gamescreen(this);
    gameScreen->show();
}

