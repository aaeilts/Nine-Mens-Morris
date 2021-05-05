#include "gamescreen.h"
#include "ui_gamescreen.h"
#include <QPushButton>
#include <QDropEvent>
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

/*
 *detect_mill will check for mill every time a  piece is placed.
 *return TRUE if mill detected
 *return FALSE if mill NOT detected
 */
bool gamescreen::detect_mill(int pos)
{
//#FIXME: FIX AND CALCULATE ALL CASES NECESARY TO FIND A MILL ON GAME BOARD
    switch (pos)
    {
    // if pieces 1,2,3 are the same. then we have a mill
    case 1:
        // if pieces 1,2,3 are the same. then we have a mill
        if ( (ui->space1->styleSheet() == ui->space2->styleSheet()) && (ui->space2->styleSheet() == ui->space3->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE ONE A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }

        // if pieces 1,10,22 are the same. then we have a mill
        else if ( (ui->space1->styleSheet() == ui->space10->styleSheet()) && (ui->space10->styleSheet() == ui->space22->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE ONE BPlayer got a mill! Remove an opponents piece" << endl;
            return true;
        }

    case 2:

        if ( (ui->space1->styleSheet() == ui->space2->styleSheet()) && (ui->space2->styleSheet() == ui->space3->styleSheet()) &&
             ui->space1->styleSheet() != "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER TWO.A: Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        // if pieces 2,5,8 are the same. then we have a mill
        else if ( (ui->space2->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space8->styleSheet()) &&
             ui->space2->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER TWO.BPlayer got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 3:

        if ( (ui->space1->styleSheet() == ui->space2->styleSheet()) && (ui->space2->styleSheet() == ui->space3->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER THREE.APlayer got a mill! Remove an opponents piece" << endl;
            return true;
        }

        // if pieces 3,15,24 are the same. then we have a mill
        else if ( (ui->space3->styleSheet() == ui->space15->styleSheet()) && (ui->space15->styleSheet() == ui->space24->styleSheet()) &&
             ui->space3->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER THREE.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 4:
        if ( (ui->space4->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space6->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER FOUR.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }

        // if pieces 4,11,19 are the same. then we have a mill
        else if ( (ui->space4->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space19->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER FOUR.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 5:
        if ( (ui->space4->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space6->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER FIVE.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        // if pieces 2,5,8 are the same. then we have a mill
        else if ( (ui->space2->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space8->styleSheet()) &&
             ui->space2->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER FIVE.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 6:
        if ( (ui->space4->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space6->styleSheet()) &&
             ui->space4->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER SIX.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        // if pieces 6,14,21 are the same. then we have a mill
        else if ( (ui->space6->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space21->styleSheet()) &&
             ui->space6->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER SIX.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 7:
        if ( (ui->space7->styleSheet() == ui->space8->styleSheet()) && (ui->space8->styleSheet() == ui->space9->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER SEVEN.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space7->styleSheet() == ui->space12->styleSheet()) && (ui->space12->styleSheet() == ui->space16->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER SEVEN.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 8:
        if ( (ui->space7->styleSheet() == ui->space8->styleSheet()) && (ui->space8->styleSheet() == ui->space9->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER EIGHT.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space2->styleSheet() == ui->space5->styleSheet()) && (ui->space5->styleSheet() == ui->space8->styleSheet()) &&
             ui->space2->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER EIGHT.BPlayer got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 9:
        if ( (ui->space7->styleSheet() == ui->space8->styleSheet()) && (ui->space8->styleSheet() == ui->space9->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE NUMBER NINE.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space9->styleSheet() == ui->space13->styleSheet()) && (ui->space13->styleSheet() == ui->space18->styleSheet()) &&
             ui->space9->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER NINE.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 10:
        if ( (ui->space1->styleSheet() == ui->space10->styleSheet()) && (ui->space10->styleSheet() == ui->space22->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE TEN B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space10->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space12->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER TEN.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 11:
        if ( (ui->space10->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space12->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE ELEVEN.A BPlayer got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space4->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space19->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER ELEVEN.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 12:
        if ( (ui->space10->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space12->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE TWELVE B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space7->styleSheet() == ui->space12->styleSheet()) && (ui->space12->styleSheet() == ui->space16->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER TWELVE.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 13:
        if ( (ui->space9->styleSheet() == ui->space13->styleSheet()) && (ui->space13->styleSheet() == ui->space18->styleSheet()) &&
             ui->space9->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER THIRTEEN.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space13->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space15->styleSheet()) &&
             ui->space13->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER THIRTEEN.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 14:
        if ( (ui->space13->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space15->styleSheet()) &&
             ui->space13->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 14.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space6->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space21->styleSheet()) &&
             ui->space6->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 14.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 15:
        if ( (ui->space3->styleSheet() == ui->space15->styleSheet()) && (ui->space15->styleSheet() == ui->space24->styleSheet()) &&
             ui->space3->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 15.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space13->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space15->styleSheet()) &&
             ui->space13->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 15.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 16:
        if ( (ui->space7->styleSheet() == ui->space12->styleSheet()) && (ui->space12->styleSheet() == ui->space16->styleSheet()) &&
             ui->space7->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 16.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space16->styleSheet() == ui->space17->styleSheet()) && (ui->space17->styleSheet() == ui->space18->styleSheet()) &&
             ui->space16->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 16.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 17:
        if ( (ui->space16->styleSheet() == ui->space17->styleSheet()) && (ui->space17->styleSheet() == ui->space18->styleSheet()) &&
             ui->space16->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 17.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space17->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space23->styleSheet()) &&
             ui->space17->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 17.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 18:
        if ( (ui->space16->styleSheet() == ui->space17->styleSheet()) && (ui->space17->styleSheet() == ui->space18->styleSheet()) &&
             ui->space16->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 18.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space9->styleSheet() == ui->space13->styleSheet()) && (ui->space13->styleSheet() == ui->space18->styleSheet()) &&
             ui->space9->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 18.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 19:
        if ( (ui->space4->styleSheet() == ui->space11->styleSheet()) && (ui->space11->styleSheet() == ui->space19->styleSheet()) &&
             ui->space10->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 19.a Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space19->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space21->styleSheet()) &&
             ui->space19->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 18.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }

    case 20:
        if ( (ui->space19->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space21->styleSheet()) &&
             ui->space19->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 20.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space17->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space23->styleSheet()) &&
             ui->space17->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 20.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }


    case 21:
        if ( (ui->space19->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space21->styleSheet()) &&
             ui->space19->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 21.A Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space6->styleSheet() == ui->space14->styleSheet()) && (ui->space14->styleSheet() == ui->space21->styleSheet()) &&
             ui->space6->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 21.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 22:
        // if pieces 1,10,22 are the same. then we have a mill
        if ( (ui->space1->styleSheet() == ui->space10->styleSheet()) && (ui->space10->styleSheet() == ui->space22->styleSheet()) &&
             ui->space1->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\n CASE 22a Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space22->styleSheet() == ui->space23->styleSheet()) && (ui->space23->styleSheet() == ui->space24->styleSheet()) &&
             ui->space22->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 22.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }

    case 23:
        if ( (ui->space22->styleSheet() == ui->space23->styleSheet()) && (ui->space23->styleSheet() == ui->space24->styleSheet()) &&
             ui->space22->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 23a Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space17->styleSheet() == ui->space20->styleSheet()) && (ui->space20->styleSheet() == ui->space23->styleSheet()) &&
             ui->space17->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 23.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    case 24:
        if ( (ui->space3->styleSheet() == ui->space15->styleSheet()) && (ui->space15->styleSheet() == ui->space24->styleSheet()) &&
             ui->space3->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 24.a Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
        else if ( (ui->space22->styleSheet() == ui->space23->styleSheet()) && (ui->space23->styleSheet() == ui->space24->styleSheet()) &&
             ui->space22->styleSheet()!= "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
        {
            cout << "\nCASE NUMBER 24.B Player got a mill! Remove an opponents piece" << endl;
            return true;
        }
    }

    // no mill detected
    return false;
};

void gamescreen::remove_piece_click()
{
    //#FIXME: DO WE STILL NEED THIS?
}


void gamescreen::on_space1_clicked()
{
    if(is_mill == true)
    {
        ui->space1->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if ((turnTracker % 2) == 0)// SET A PIECE GRAY
    {
        ui->space1->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(1); // check for mill
        turnTracker++;
    }
    else if ((turnTracker % 2) == 1)// SET A PIECE BLACK
    {
        ui->space1->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(1); // check for mill
        turnTracker++;
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
    else if ((turnTracker % 2) == 0)// SET A PIECE GRAY
    {
        ui->space2->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(2); // check for mill
        turnTracker++;
    }
    else if ((turnTracker % 2) == 1)// SET A PIECE BLACK
    {
        ui->space2->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(2); // check for mill
        turnTracker++;
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
    else if ((turnTracker % 2) == 0)// SET A PIECE GRAY
    {
        ui->space3->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(3); // check for mill
        turnTracker++;
    }
    else if ((turnTracker % 2) == 1)// SET A PIECE BLACK
    {
        ui->space3->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(3); // check for mill
        turnTracker++;
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
    else if ((turnTracker % 2) == 0)// SET A PIECE GRAY
    {
        ui->space4->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(4); // check for mill
        turnTracker++;
    }
    else if ((turnTracker % 2) == 1)// SET A PIECE BLACK
    {
        ui->space4->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(4); // check for mill
        turnTracker++;
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space5_clicked()
{
//#FIXME: FINISH UPDATING REST OF space_clicked() FUNCTIONS.
//#FIXME: MAKE SURE ALL PROPER NUMBERS ARE SENT FOR SWITCH CASES INSIDE detect_mill()
    if(is_mill == true)
    {
        ui->space5->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        is_mill = false;
    }
    else if ((turnTracker % 2) == 0)// SET A PIECE GRAY
    {
        ui->space5->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(4); // check for mill
        turnTracker++;
    }
    else if ((turnTracker % 2) == 1)// SET A PIECE BLACK
    {
        ui->space5->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
        is_mill = detect_mill(4); // check for mill
        turnTracker++;
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
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
