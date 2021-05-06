#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QPushButton>
#include <QDropEvent>
#include <string>
#include <iostream>
using namespace std;


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
//Changes turnTracker from 1 to 0 or 0 to 1
void gamescreen::changeturn(bool isMill)
{
    if (isMill){
        turnTracker += 0;
    }
    else {
        turnTracker += 1;
        turnTracker = turnTracker % 2;
    }

}

void gamescreen::mill_output(int turnTracker)
{
    //if turnTracjer remainder == 0 output for gray team. 1 for black team
    if ((turnTracker % 2) == 0) {
        cout << "\nGray Team scored a mill! Remove a Black Team's piece" << endl;
    }
    else if ((turnTracker % 2) == 1) {
        cout << "\nBlack Team scored a mill! Remove a Gray Team's piece" << endl;
    }

}

void gamescreen::remove_piece(int turnTracker)
{
    cout << "entered remove_piece() " << endl;
    // if turnTracker == gray
    switch (turnTracker)
    {//FIXME
        case 0 :
            if(ui->space1->styleSheet() == "background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;" )
            {
                cout << "changing colors" << endl;
                ui->space1->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
            }

            else
            {
                cout << "incorrect choice try again" << endl;
            }

            break;
        case 1 :
            break;

    };
}

// detect_mill will check for mill every time a  piece is placed.
bool gamescreen::detect_mill(int pos)
{
    switch (pos)
    {
    case 1:
        // if pieces 1,2,3 are the same. then we have a mill
        if ( (ui->space1->styleSheet() == ui->space2->styleSheet()) && (ui->space2->styleSheet() == ui->space3->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }

        // if pieces 1,10,22 are the same. then we have a mill
        else if ( (ui->space1->styleSheet() == ui->space10->styleSheet()) && (ui->space10->styleSheet() == ui->space22->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }

    case 2:

        if ( (ui->space1->styleSheet() == ui->space2->styleSheet()) && (ui->space2->styleSheet() == ui->space3->styleSheet()) &&
             ui->space1->styleSheet() != "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        // if pieces 2,5,8 are the same. then we have a mill
        else if ( (ui->space2->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space8->styleSheet()) &&
             ui->space2->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 3:

        if ( (ui->space1->styleSheet() == ui->space2->styleSheet()) && (ui->space2->styleSheet() == ui->space3->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }

        // if pieces 3,15,24 are the same. then we have a mill
        else if ( (ui->space3->styleSheet() == ui->space15->styleSheet()) && (ui->space15->styleSheet() == ui->space24->styleSheet()) &&
             ui->space3->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 4:
        if ( (ui->space4->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space6->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }

        // if pieces 4,11,19 are the same. then we have a mill
        else if ( (ui->space4->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space19->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 5:
        if ( (ui->space4->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space6->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        // if pieces 2,5,8 are the same. then we have a mill
        else if ( (ui->space2->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space8->styleSheet()) &&
             ui->space2->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 6:
        if ( (ui->space4->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space6->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        // if pieces 6,14,21 are the same. then we have a mill
        else if ( (ui->space6->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space21->styleSheet()) &&
             ui->space6->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 7:
        if ( (ui->space7->styleSheet() == ui->space8->styleSheet()) && (ui->space8->styleSheet() == ui->space9->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space7->styleSheet() == ui->space12->styleSheet()) && (ui->space12->styleSheet() == ui->space16->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 8:
        if ( (ui->space7->styleSheet() == ui->space8->styleSheet()) && (ui->space8->styleSheet() == ui->space9->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space2->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space8->styleSheet()) &&
             ui->space2->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 9:
        if ( (ui->space7->styleSheet() == ui->space8->styleSheet()) && (ui->space8->styleSheet() == ui->space9->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space9->styleSheet() == ui->space13->styleSheet()) && (ui->space13->styleSheet() == ui->space18->styleSheet()) &&
             ui->space9->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 10:
        if ( (ui->space1->styleSheet() == ui->space10->styleSheet()) && (ui->space10->styleSheet() == ui->space22->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space10->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space12->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 11:
        if ( (ui->space10->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space12->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space4->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space19->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 12:
        if ( (ui->space10->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space12->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space7->styleSheet() == ui->space12->styleSheet()) && (ui->space12->styleSheet() == ui->space16->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 13:
        if ( (ui->space9->styleSheet() == ui->space13->styleSheet()) && (ui->space13->styleSheet() == ui->space18->styleSheet()) &&
             ui->space9->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space13->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space15->styleSheet()) &&
             ui->space13->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 14:
        if ( (ui->space13->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space15->styleSheet()) &&
             ui->space13->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space6->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space21->styleSheet()) &&
             ui->space6->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 15:
        if ( (ui->space3->styleSheet() == ui->space15->styleSheet()) && (ui->space15->styleSheet() == ui->space24->styleSheet()) &&
             ui->space3->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space13->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space15->styleSheet()) &&
             ui->space13->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 16:
        if ( (ui->space7->styleSheet() == ui->space12->styleSheet()) && (ui->space12->styleSheet() == ui->space16->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space16->styleSheet() == ui->space17->styleSheet()) && (ui->space17->styleSheet() == ui->space18->styleSheet()) &&
             ui->space16->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 17:
        if ( (ui->space16->styleSheet() == ui->space17->styleSheet()) && (ui->space17->styleSheet() == ui->space18->styleSheet()) &&
             ui->space16->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space17->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space23->styleSheet()) &&
             ui->space17->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 18:
        if ( (ui->space16->styleSheet() == ui->space17->styleSheet()) && (ui->space17->styleSheet() == ui->space18->styleSheet()) &&
             ui->space16->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space9->styleSheet() == ui->space13->styleSheet()) && (ui->space13->styleSheet() == ui->space18->styleSheet()) &&
             ui->space9->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 19:
        if ( (ui->space4->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space19->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space19->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space21->styleSheet()) &&
             ui->space19->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }

    case 20:
        if ( (ui->space19->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space21->styleSheet()) &&
             ui->space19->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space17->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space23->styleSheet()) &&
             ui->space17->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }


    case 21:
        if ( (ui->space19->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space21->styleSheet()) &&
             ui->space19->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space6->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space21->styleSheet()) &&
             ui->space6->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 22:
        // if pieces 1,10,22 are the same. then we have a mill
        if ( (ui->space1->styleSheet() == ui->space10->styleSheet()) && (ui->space10->styleSheet() == ui->space22->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space22->styleSheet() == ui->space23->styleSheet()) && (ui->space23->styleSheet() == ui->space24->styleSheet()) &&
             ui->space22->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }

    case 23:
        if ( (ui->space22->styleSheet() == ui->space23->styleSheet()) && (ui->space23->styleSheet() == ui->space24->styleSheet()) &&
             ui->space22->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space17->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space23->styleSheet()) &&
             ui->space17->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    case 24:
        if ( (ui->space3->styleSheet() == ui->space15->styleSheet()) && (ui->space15->styleSheet() == ui->space24->styleSheet()) &&
             ui->space3->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
        else if ( (ui->space22->styleSheet() == ui->space23->styleSheet()) && (ui->space23->styleSheet() == ui->space24->styleSheet()) &&
             ui->space22->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            mill_output(turnTracker);
            return true;
        }
    }

    // no mill detected
    return false;
};

void gamescreen::on_space1_clicked()
{
    if(is_mill == true) // each click will first check if mill is present..
    {//FIXME: IMPLEMENT remove_check() method
        remove_piece(turnTracker);
        cout << "outside remove_check()" << endl;
        ui->space1->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
        changeturn(is_mill);
    }
    else if (turnTracker == 0)//Gray's Turn
    {

        if (p1_num_pieces > 0) //will Set a piece gray if have pieces left to place
        {
            ui->space1->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(1); // check for mill
            changeturn(is_mill);
        }

    }
    else if (turnTracker == 1)//Black's Turn
    {

        if (p2_num_pieces > 0) //will set a piece black if have pieces left to place
        {
            ui->space1->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(1); // check for mill
            changeturn(is_mill);
        }

    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space2_clicked()
{
    if(is_mill == true)
    {
        ui->space2->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's Turn
    {

        if (p1_num_pieces > 0) //Place gray piece if pieces left
        {
            ui->space2->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(2);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's Turn
    {

        if (p2_num_pieces > 0) //Place black piece if pieces left
        {
            ui->space2->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(2);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space3_clicked()
{
    if(is_mill == true)
    {
        ui->space3->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) // Gray's turn
    {

        if (p1_num_pieces > 0) // Place a gray piece if pieces left
        {
            ui->space3->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(3);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {

        if (p2_num_pieces > 0) // Place black piece if pieces left
        {
            ui->space3->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(3);
            changeturn(is_mill);
        }

    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space4_clicked()
{
    if(is_mill == true)
    {
        ui->space4->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's Turn
    {
        if (p1_num_pieces > 0) //Place gray piece if pieces available
        {
            ui->space4->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(4);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {
        if (p2_num_pieces > 0) // Place piece if pieces available
        {
            ui->space4->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(4);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space5_clicked()
{
    if(is_mill == true)
    {
        ui->space5->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) // Grays turn
    {
        if (p1_num_pieces > 0) // Place a gray piece if any available
        {
            ui->space5->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(5);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if pieces available
        {
            ui->space5->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(5);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space6_clicked()
{
    if(is_mill == true)
    {
        ui->space6->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place a gray piece
        {
            ui->space6->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(6);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space6->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(6);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space7_clicked()
{
    if(is_mill == true)
    {
        ui->space7->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) // Place gray piece if piece available
        {
            ui->space7->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(7);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's Turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space7->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(7);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space8_clicked()
{
    if(is_mill == true)
    {
        ui->space8->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0)//Grays Turn
    {
        if (p1_num_pieces > 0) //Place a gray piece if available
        {
            ui->space8->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(8);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Blacks turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space8->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(8);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space9_clicked()
{
    if(is_mill == true)
    {
        ui->space9->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space9->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(9);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space9->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(9);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space10_clicked()
{
    if(is_mill == true)
    {
        ui->space10->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place a gray piece if available
        {
            ui->space10->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(10);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place a black piece
        {
            ui->space10->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(10);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space11_clicked()
{
    if(is_mill == true)
    {
        ui->space11->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Grays turn
    {
        if (p1_num_pieces > 0) //Place grey piece if available
        {
            ui->space11->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(11);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space11->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(11);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space12_clicked()
{
    if(is_mill == true)
    {
        ui->space12->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space12->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(12);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space12->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(12);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space13_clicked()
{
    if(is_mill == true)
    {
        ui->space13->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) // Place gray piece if available
        {
            ui->space13->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(13);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p1_num_pieces > 0) //Place black piece if available
        {
            ui->space13->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(13);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space14_clicked()
{
    if(is_mill == true)
    {
        ui->space14->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space14->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(14);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space14->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(14);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space15_clicked()
{
    if(is_mill == true)
    {
        ui->space15->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space15->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(15);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space15->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(15);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space16_clicked()
{
    if(is_mill == true)
    {
        ui->space16->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space16->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(16);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space16->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(16);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space17_clicked()
{
    if(is_mill == true)
    {
        ui->space17->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space17->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(17);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space17->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(17);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space18_clicked()
{
    if(is_mill == true)
    {
        ui->space18->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) // Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space18->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(18);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space18->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(18);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space19_clicked()
{
    if(is_mill == true)
    {
        ui->space19->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0)//Gray's turn
    {
        if (p1_num_pieces > 0)//Place gray piece if available
        {
            ui->space19->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(19);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space19->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(19);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space20_clicked()
{
    if(is_mill == true)
    {
        ui->space20->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) // Gray's turn
    {

        if (p1_num_pieces > 0) // Place gray piece if available
        {
            ui->space20->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(20);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space20->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(20);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space21_clicked()
{
    if(is_mill == true)
    {
        ui->space21->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker  == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space21->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(21);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space21->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(21);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space22_clicked()
{
    if(is_mill == true)
    {
        ui->space22->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0)//Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space22->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(22);
            changeturn(is_mill);
        }

    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) // Place black piece if available
        {
            ui->space22->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(22);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space23_clicked()
{
    if(is_mill == true)
    {
        ui->space23->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space23->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(23);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space23->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(23);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space24_clicked()
{
    if(is_mill == true)
    {
        ui->space24->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if (p1_num_pieces > 0) //Place gray piece if available
        {
            ui->space24->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            ui->p1_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(24);
            changeturn(is_mill);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if (p2_num_pieces > 0) //Place black piece if available
        {
            ui->space24->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p2_num_pieces--;
            ui->p2_pieces->setText(QString::number(p2_num_pieces));
            is_mill = detect_mill(24);
            changeturn(is_mill);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}
