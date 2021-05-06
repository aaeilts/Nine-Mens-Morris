#include "titlescreen.h"
#include "ui_titlescreen.h"
#include <QMessageBox>



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



void TitleScreen::on_pushButton_2_clicked()
{
  QMessageBox::information(this,"Rules","In the beginning of the game each player starts with 9 pieces each. To start the game white places a piece in a vacant spot on the board and player being to take turn on placing pieces on vacant spots of the board players can also move their pieces to adjacent vacant places on the board to block their opponent from creating a mill. The objective of the game is to get your pieces to form a mill (a line across the board connecting adjacent pieces of one color) so you can remove one of your opponent’s pieces as long as it is not a part of an existing mill unless those are the only pieces available to be moved. When a player is down to 3 pieces left on the board that player in now allowed to fly by moving to any vacant spot on the board. Once a player has fewer than 3 pieces or no longer can make a legal move the game is over and the other player wins!  ");
}
