#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QDialog>

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
     *is_mill:          signals the program if there is a mill on board with T or F value.
     *
     */
    int turnTracker = 0;
    bool is_mill = false;

// possibleMillPositions =
//        {{0,1,2}}, // 1
//        {{0,9,21}},
//        {{1,4,7}},
//        {{2,14,23}},
//        {{3,4,5}},
//        {{3,10,18}},
//        {{5,13,20}},
//        {{6,7,8}},
//        {{6,11,15}},
//        {{8,12,17}},
//        {{9,10,11}},
//        {{12,13,14}},
//        {{15,16,17}},
//        {{16,19,22}},
//        {{18,19,20}},
//        {{21,22,23}} //16

    ~gamescreen();

private slots:

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
     * method(s) to place a piece. spaces1-24 go from left to right. top to bottom.
     * on_space_clicked() executes when a click happens
     *
     */
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
