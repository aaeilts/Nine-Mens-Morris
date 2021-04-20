#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QPushButton>
#include <QDropEvent>

gamescreen::gamescreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gamescreen)
{
    ui->setupUi(this);

    //connect(ui->space1, SIGNAL(clicked()), this, SLOT(on_space1_clicked()));
}

gamescreen::~gamescreen()
{
    delete ui;
}

void gamescreen::on_space1_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space1->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space1->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space2_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space2->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space2->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space3_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space3->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space3->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space4_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space4->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space4->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space5_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space5->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space5->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space6_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space6->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space6->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space7_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space7->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space7->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space8_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space8->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space8->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space9_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space9->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space9->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space10_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space10->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space10->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space11_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space11->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space11->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space12_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space12->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space12->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space13_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space13->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space13->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space14_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space14->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space14->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space15_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space15->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space15->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space16_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space16->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space16->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space17_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space17->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space17->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space18_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space18->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space18->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space19_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space19->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space19->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space20_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space20->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space20->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space21_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space21->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space21->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space22_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space22->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space22->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space23_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space23->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space23->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}

void gamescreen::on_space24_clicked()
{
    if ((turnTracker % 2) == 0)
    {
    ui->space24->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else if ((turnTracker % 2) == 1)
    {
    ui->space24->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
    }
    else{
        turnTracker = turnTracker + 0;
    }
    turnTracker++;
}
