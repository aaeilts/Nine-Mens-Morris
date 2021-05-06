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

void gamescreen::WhiteToBlue(QPushButton* button1){
    if (button1->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;" )
    {
        button1->setStyleSheet("background-color: blue;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        changed = true;
        tempButtonHolder.append(button1);
    }
}

//This function populates the declared vector "adjacents" with the adjacent angles of the index+1 space
void gamescreen::PopulateVector(){
    if (createvector == 0)
    {
        buttons.push_back(ui->space1);
        buttons.push_back(ui->space2);
        buttons.push_back(ui->space3);
        buttons.push_back(ui->space4);
        buttons.push_back(ui->space5);
        buttons.push_back(ui->space6);
        buttons.push_back(ui->space7);
        buttons.push_back(ui->space8);
        buttons.push_back(ui->space9);
        buttons.push_back(ui->space10);
        buttons.push_back(ui->space11);
        buttons.push_back(ui->space12);
        buttons.push_back(ui->space13);
        buttons.push_back(ui->space14);
        buttons.push_back(ui->space15);
        buttons.push_back(ui->space16);
        buttons.push_back(ui->space17);
        buttons.push_back(ui->space18);
        buttons.push_back(ui->space19);
        buttons.push_back(ui->space20);
        buttons.push_back(ui->space21);
        buttons.push_back(ui->space22);
        buttons.push_back(ui->space23);
        buttons.push_back(ui->space24);
        createvector++;
    }
}

void gamescreen::movePieces(int place){
    if (secondPhase){
        phaseTwo(place);
    }
    else{
        ChangeAdjacentEmpty(place);
    }


}

void gamescreen::CheckPhaseTwo(QPushButton* button){
    if (button->styleSheet() == "background-color: cyan;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")
}

void gamescreen::IfChanged(QPushButton* button2){
    if (changed)
    {
        button2->setStyleSheet("background-color: cyan;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        secondPhase = true;
        move_from.push_back(button2);
    }
}

void gamescreen::phaseTwo(int place){
    if (tempButtonHolder.contains(buttons[place-1])) //If the button pressed was in our temp (adjacent) button list
    {
        if (turnTracker == 0){ //If gray's turn turn it to gray
            buttons[place-1]->setStyleSheet("background-color: gray;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        }
        else{ // Otherwise its blacks turn turn it to black
            buttons[place-1]->setStyleSheet("background-color: black;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
        }
    }
    tempButtonHolder.removeOne(buttons[place-1]); // Remove button the player selected
    for (int i = 0; i < tempButtonHolder.size(); i++)
    {
        tempButtonHolder[i]->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
    } //^^ turns the buttons back to white
    tempButtonHolder.clear();
    changeturn(true);
}


//void gamescreen::moveAPiece(int index){}

void gamescreen::ChangeAdjacentEmpty(int switchCase){
    switch(switchCase){
    case 1:
        WhiteToBlue(ui->space2);
        WhiteToBlue(ui->space10);
        IfChanged(ui->space1);
        break;
    case 2:
        WhiteToBlue(ui->space1);
        WhiteToBlue(ui->space3);
        WhiteToBlue(ui->space5);
        IfChanged(ui->space2);
        break;
    case 3:
        WhiteToBlue(ui->space2);
        WhiteToBlue(ui->space15);
        IfChanged(ui->space3);
        break;
    case 4:
        WhiteToBlue(ui->space5);
        WhiteToBlue(ui->space11);
        IfChanged(ui->space4);
        if (changed)
        {
            ui->space4->setStyleSheet("background-color: cyan;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
            secondPhase = true;
        }
        break;
    case 5:
        WhiteToBlue(ui->space2);
        WhiteToBlue(ui->space4);
        WhiteToBlue(ui->space6);
        WhiteToBlue(ui->space8);
        IfChanged(ui->space5);
        break;
    case 6:
        WhiteToBlue(ui->space5);
        WhiteToBlue(ui->space14);
        IfChanged(ui->space6);
        break;
    case 7:
        WhiteToBlue(ui->space8);
        WhiteToBlue(ui->space12);
        IfChanged(ui->space7);
        break;
    case 8:
        WhiteToBlue(ui->space5);
        WhiteToBlue(ui->space7);
        WhiteToBlue(ui->space9);
        IfChanged(ui->space8);
        break;
    case 9:
        WhiteToBlue(ui->space8);
        WhiteToBlue(ui->space13);
        IfChanged(ui->space9);
        break;
    case 10:
        WhiteToBlue(ui->space1);
        WhiteToBlue(ui->space11);
        WhiteToBlue(ui->space22);
        IfChanged(ui->space10);
        break;
    case 11:
        WhiteToBlue(ui->space4);
        WhiteToBlue(ui->space10);
        WhiteToBlue(ui->space12);
        WhiteToBlue(ui->space19);
        IfChanged(ui->space11);
        break;
    case 12:
        WhiteToBlue(ui->space7);
        WhiteToBlue(ui->space11);
        WhiteToBlue(ui->space16);
        IfChanged(ui->space12);
        break;
    case 13:
        WhiteToBlue(ui->space9);
        WhiteToBlue(ui->space14);
        WhiteToBlue(ui->space18);
        IfChanged(ui->space13);
        break;
    case 14:
        WhiteToBlue(ui->space6);
        WhiteToBlue(ui->space13);
        WhiteToBlue(ui->space15);
        WhiteToBlue(ui->space21);
        IfChanged(ui->space14);
        break;
    case 15:
        WhiteToBlue(ui->space3);
        WhiteToBlue(ui->space14);
        WhiteToBlue(ui->space24);
        IfChanged(ui->space15);
        break;
    case 16:
        WhiteToBlue(ui->space12);
        WhiteToBlue(ui->space17);
        IfChanged(ui->space16);
        break;
    case 17:
        WhiteToBlue(ui->space16);
        WhiteToBlue(ui->space18);
        WhiteToBlue(ui->space20);
        IfChanged(ui->space17);
        break;
    case 18:
        WhiteToBlue(ui->space13);
        WhiteToBlue(ui->space17);
        IfChanged(ui->space18);
        break;
    case 19:
        WhiteToBlue(ui->space11);
        WhiteToBlue(ui->space20);
        IfChanged(ui->space19);
        break;
    case 20:
        WhiteToBlue(ui->space17);
        WhiteToBlue(ui->space19);
        WhiteToBlue(ui->space21);
        WhiteToBlue(ui->space23);
        IfChanged(ui->space20);
        break;
    case 21:
        WhiteToBlue(ui->space14);
        WhiteToBlue(ui->space20);
        IfChanged(ui->space21);
        break;
    case 22:
        WhiteToBlue(ui->space10);
        WhiteToBlue(ui->space23);
        IfChanged(ui->space22);
        break;
    case 23:
        WhiteToBlue(ui->space20);
        WhiteToBlue(ui->space22);
        WhiteToBlue(ui->space24);
        IfChanged(ui->space23);
        break;
    case 24:
        WhiteToBlue(ui->space15);
        WhiteToBlue(ui->space23);
        IfChanged(ui->space24);
        break;
    }
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
   if (turnTracker == 0)
   {
        ui->turn_label->setText("Player 1's Turn");
   }
   else if (turnTracker == 1)
   {
       ui->turn_label->setText("Player 2's Turn");
   }
   else{
       ui->turn_label->setText("TurnTracker Error");
   }

}

//mill_output outputs specific mill message for whichever team got it.
void gamescreen::mill_output(int turnTracker)
{
    //if turnTracjer remainder == 0 output for gray team. 1 for black team
    if (turnTracker == 0) {
        cout << "\n***Gray Team scored a mill! Remove a Black Team's piece***" << endl;
    }
    else if (turnTracker == 1) {
        cout << "\n***Black Team scored a mill! Remove a Gray Team's piece***" << endl;
    }

}

//checks if desired piece to be removed is applicable... then removes piece
void gamescreen::remove_piece(int turnTracker, QPushButton* pos)
{
    switch (turnTracker)
    {
        // if gray gets mill
        case 0 :
            //if position = black piece. 'remove' piece
            if(pos->styleSheet() == "background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;")
            {
                pos->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
                cout << "*** removing piece ***" << endl;
                is_mill = false; // piece removed, turn mill status OFF.
            }
            //else if position is gray OR white, pick a different piece
            else if( (pos->styleSheet() == "background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;") ||
                     (pos->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;"))
            {
                cout << "incorrect choice try again" << endl;
            }
            break;
        //if black gets mill
        case 1 :
            if(pos->styleSheet() == "background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;")
            {
                cout << "removing piece..." << endl;
                pos->setStyleSheet("background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;");
            }
            else if( (pos->styleSheet() == "background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;") ||
                     (pos->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;"))
            {
                cout << "incorrect choice try again" << endl;
            }
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
    PopulateVector(); //Populates vector of board spaces on first run through

    if(is_mill == true) // each click will first check if mill is present..
    {//FIXME: IMPLEMENT remove_check() method
        remove_piece(turnTracker, ui->space1);
        changeturn(is_mill);
    }
    else if (turnTracker == 0)//Gray's Turn
    {

        if ((p0_num_pieces > 0) && (ui->space1->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //will Set a piece gray if have pieces left to place
        {
            ui->space1->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_pieces_on_board++;
            p0_num_pieces--;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(1); // check for mill
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(1);
        }
    }
    else if (turnTracker == 1)//Black's Turn
    {

        if ((p1_num_pieces > 0) && (ui->space1->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //will set a piece black if have pieces left to place
        {
            ui->space1->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(1); // check for mill
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(1);
        }

    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space2_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space2);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's Turn
    {

        if ((p0_num_pieces > 0) && (ui->space2->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if pieces left
        {
            ui->space2->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_pieces_on_board++;
            p0_num_pieces--;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(2);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(2);
        }
    }
    else if (turnTracker == 1) //Black's Turn
    {

        if ((p1_num_pieces > 0) && (ui->space2->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if pieces left
        {
            ui->space2->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(2);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(2);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space3_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space3);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) // Gray's turn
    {

        if ((p0_num_pieces > 0) && (ui->space3->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place a gray piece if pieces left
        {
            ui->space3->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_pieces_on_board++;
            p0_num_pieces--;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(3);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(3);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {

        if ((p1_num_pieces > 0) && (ui->space3->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if pieces left
        {
            ui->space3->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(3);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(3);
        }

    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space4_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space4);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's Turn
    {
        if ((p0_num_pieces > 0) && (ui->space4->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if pieces available
        {
            ui->space4->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_pieces_on_board++;
            p0_num_pieces--;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(4);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(4);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space4->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place piece if pieces available
        {
            ui->space4->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
             p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(4);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(4);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space5_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space5);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) // Grays turn
    {
        if ((p0_num_pieces > 0) && (ui->space5->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place a gray piece if any available
        {
            ui->space5->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_pieces_on_board++;
            p0_num_pieces--;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(5);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(5);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space5->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if pieces available
        {
            ui->space5->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(5);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(5);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space6_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space6);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space6->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place a gray piece
        {
            ui->space6->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_pieces_on_board++;
            p0_num_pieces--;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(6);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(6);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space6->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space6->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(6);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(6);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space7_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space7);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space7->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place gray piece if piece available
        {
            ui->space7->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(7);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(7);
        }
    }
    else if (turnTracker == 1) //Black's Turn
    {
        if ((p1_num_pieces > 0) && (ui->space7->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space7->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(7);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(7);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space8_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space8);
        changeturn(is_mill);
    }
    else if (turnTracker == 0)//Grays Turn
    {
        if ((p0_num_pieces > 0) && (ui->space8->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place a gray piece if available
        {
            ui->space8->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(8);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(8);
        }
    }
    else if (turnTracker == 1) //Blacks turn
    {
        if ((p1_num_pieces > 0) && (ui->space8->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space8->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(8);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(8);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space9_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space9);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space9->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space9->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(9);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(9);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space9->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space9->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(9);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(9);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space10_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space10);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space10->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place a gray piece if available
        {
            ui->space10->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(10);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(10);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space10->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place a black piece
        {
            ui->space10->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(10);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(10);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space11_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space11);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Grays turn
    {
        if ((p0_num_pieces > 0) && (ui->space11->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place grey piece if available
        {
            ui->space11->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(11);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(11);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space11->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space11->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(11);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(11);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space12_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space12);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space12->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space12->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(12);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(1);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space12->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space12->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(12);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(1);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space13_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space13);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space13->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place gray piece if available
        {
            ui->space13->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(13);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(13);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space13->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space13->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(13);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(13);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space14_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space14);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space14->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space14->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(14);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(14);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space14->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space14->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(14);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(14);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space15_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space15);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space15->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space15->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(15);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(15);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space15->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space15->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(15);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(15);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space16_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space16);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space16->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space16->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(16);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(16);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space16->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space16->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(16);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(16);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space17_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space17);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space17->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space17->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(17);
            changeturn(is_mill);  
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(17);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space17->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space17->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(17);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(17);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space18_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space18);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) // Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space18->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space18->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(18);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(18);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space18->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space18->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(18);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(18);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space19_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space19);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space19->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space19->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(19);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(19);
        }
    }
    else if (turnTracker == 1) // Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space19->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space19->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(19);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(19);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space20_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space20);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) // Gray's turn
    {

        if ((p0_num_pieces > 0) && (ui->space20->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place gray piece if available
        {
            ui->space20->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(20);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(20);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space20->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space20->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(20);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(20);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space21_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space21);
        changeturn(is_mill);
    }
    else if (turnTracker  == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space21->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space21->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(21);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(21);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space21->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space21->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(21);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(21);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space22_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space22);
        changeturn(is_mill);
    }
    else if (turnTracker == 0)//Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space22->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space22->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(22);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(22);
        }

    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space22->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) // Place black piece if available
        {
            ui->space22->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(22);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(22);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space23_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space23);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space23->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space23->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(23);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(23);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space23->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space23->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(23);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(23);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}

void gamescreen::on_space24_clicked()
{
    PopulateVector(); //Populates vector of board spaces on first run through
    if(is_mill == true)
    {
        remove_piece(turnTracker, ui->space24);
        changeturn(is_mill);
    }
    else if (turnTracker == 0) //Gray's turn
    {
        if ((p0_num_pieces > 0) && (ui->space24->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place gray piece if available
        {
            ui->space24->setStyleSheet("background-color: gray; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p0_num_pieces--;
            p0_pieces_on_board++;
            ui->p1_pieces->setText(QString::number(p0_num_pieces));
            is_mill = detect_mill(24);
            changeturn(is_mill);
        }
        else if ((p0_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(24);
        }
    }
    else if (turnTracker == 1) //Black's turn
    {
        if ((p1_num_pieces > 0) && (ui->space24->styleSheet() == "background-color: white;\n border-style: solid;\n border-width:1px;\n border-radius:10px;\n border-color: black;\n max-width:20px;\n max-height:20px;\n min-width:20px;\n min-height:20px;")) //Place black piece if available
        {
            ui->space24->setStyleSheet("background-color: black; border-style: solid; border-width: 1px; border-radius: 10px; border-color: black; max-width: 20px; max-height: 20px; min-width :20px; min-height: 20px;");
            p1_num_pieces--;
            p1_pieces_on_board++;
            ui->p2_pieces->setText(QString::number(p1_num_pieces));
            is_mill = detect_mill(24);
            changeturn(is_mill);
        }
        else if ((p1_pieces_on_board > 3) && (p0_num_pieces == 0)) //Move piece phase. If the button is blue, it changes immediately when clicked to turn players color.
        {
            movePieces(24);
        }
    }
    else
    {
        turnTracker = turnTracker + 0;
    }
}
