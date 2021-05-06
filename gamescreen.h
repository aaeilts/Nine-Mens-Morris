#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QDialog>
#include <QPushButton>

//ERROR messages:
#define ERROR_ILLEGAL_REMOVE "This piece cannot be removed."

using namespace std;

namespace Ui {
class gamescreen;
}

class gamescreen : public QDialog
{
    Q_OBJECT

public:
    explicit gamescreen(QWidget *parent = nullptr);

    /*
     *turnTracker:      keeps track of who's turn it is
     *p1_num_pieces:    keeps track of total allowed pieces for p1
     *p2_num_pieces:    keeps track of total allowed pieces for p2
     *is_mill:          signals the program if there is a mill on board with T or F value.
     *
     */
    int turnTracker = 0;
    int p1_num_pieces = 9;
    int p2_num_pieces = 9;
    bool is_mill = false;

    ~gamescreen();

    /*
     * changeturn()... changes the turn
     * parameter:   isMill -> if mill is present. dont change turns
     */
    void changeturn(bool isMill);

    /* chekcs for mill
     *
     * parameter: pos -> where a piece was just placed.
     *
     * Returns: TRUE if mill detected
     *          FALSE if mill NOT detected
     */
    bool detect_mill(int pos);

    //output when a mill happens
    void mill_output(int turnTracker);

    /*
     * checks if its OK to remove a specific piece
     */
    //FIXME: FIGURE OUT HOW TO IMPLEMENT THIS METHOD
    void remove_piece(int turnTracker, QPushButton* pos);

    /*
     * method(s) to place a piece. spaces1-24 go from left to right. top to bottom.
     * on_space_clicked() executes when a click happens
     *
     */

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
