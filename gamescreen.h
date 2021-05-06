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
    ~gamescreen();

    /*
     * turnTracker:         keeps track of who's turn it is
     * p0_num_pieces:       keeps track of total allowed pieces for p1
     * p1_num_pieces:       keeps track of total allowed pieces for p2
     * is_mill:             signals the program if there is a mill on board with T or F value.
     * p0_pieces_on_board:  keeps track of current number of pieces on board for p1
     * p1_pieces_on_board   keeps track of current number of pieces on board for p2
     * globalChage          Used when moving a piece
     */

    int turnTracker = 0;
    int p0_num_pieces = 3;
    int p1_num_pieces = 3;
    bool is_mill = false;
    bool changed = false;
    int p0_pieces_on_board = 0;
    int p1_pieces_on_board = 0;
    bool game_end = false;
    QVector<QPushButton*> move_from;
    QVector<QString> styleMemory;
    QVector<QPushButton*> buttons;
    QVector<QPushButton*> tempButtonHolder;
    QVector<QVector<int>> adjacents = {{2, 10}, {1,3}, {2, 15},
                                       {5,11}, {2, 4, 6, 8}, {5,16},
                                       {8,12}, {5,7,9}, {8,13},
                                       {1,11,22}, {4, 10, 12, 19}, {7,11,16},
                                       {9,14,18}, {6,13,15,21}, {3,14,24},
                                       {12,17}, {16,18,20}, {13,17},
                                       {11,20}, {17,19,21,23}, {14,20},
                                       {10,23}, {20,22,24}, {15,23}};
    bool secondPhase = false;
    int createvector = 0;
    //QList<QList<QPushButton*>> adjacents;

    /*
     *
     *
     */
    void PopulateVector();

    void CheckPhaseTwo(QPushButton* button);

    void IfChanged(QPushButton* button2);

    /*
     *movePieces
     *
     *parameter:    place ->
     */

    void changeturn(bool isMill);

    void endgame(int p0_num_pieces, int p2_num_pieces, int p0_pieces_on_board, int p1_pieces_on_board);

    void movePieces(int place);

    void WhiteToBlue(QPushButton* button1);

    void phaseTwo(int place);

    void ChangeAdjacentEmpty(int switchCase);

    void moveAPiece(int index);

    /*
     *fly_phase()
     *
     *parameter:    pos-> object that points to which piece we want to FLY/move (based on next click)
     *              turnTracker-> used in switch/case to see who gets to FLY/move
     */
    void fly_phase(QPushButton* pos,int turnTracker);
//    bool fly_check();

    /*
     * detect_mill()
     * parameter: pos -> where a piece was just placed.
     *
     * Returns: TRUE if mill detected
     *          FALSE if mill NOT detected
     */
    bool detect_mill(int pos);

    /*
     * changeturn()... changes the turn
     * parameter:   isMill -> if mill is present. dont change turns
     */
    void changeturn(bool isMill);

    //output when a mill happens
    void mill_output(int turnTracker);

    /*
     * remove_piece()
     * checks if its OK to remove a specific piece
     *
     * parameter:   turnTracker-> use in switch/case to see who gets to remove
     *              pos-> object that points to which piece we want to remove (based on next click)
     */
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
