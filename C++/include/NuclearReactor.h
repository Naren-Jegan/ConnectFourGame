#ifndef NUCLEARREACTOR_H_INCLUDED
#define NUCLEARREACTOR_H_INCLUDED
#include<vector>
using namespace std;
#include "NuclearCell.h"
//Board for the Game
struct Move{
    string player;
    int row,column;
};
struct Point{
    int row,column;
};
void writeToJson(string player);
class NuclearReactor{
        NuclearCell cells[Constants::ROWS][Constants::COLUMNS]; // 2D BOARD made of cells with "ROWS" rows and "COLUMNS" columns
        NuclearCell lastmove; //Cell on which the last bomb was dropped into

    public:

        //Constructor with the starting player as parameter
        NuclearReactor();

	   //CopyConstructor
        NuclearReactor(NuclearReactor const &NR);

	   //Get last ooponent move
        NuclearCell getRecentOpponentMove();

        //Drops the bomb in the "column" if it is a valid move
        void dropBomb(int column,Constants::PlayerType P);

        //checks whether a bomb/defusal kit can be placed at the given column number
        bool isBombPlaceable(int column_number);
        //Get the Color of the cell at (row,column)
        Constants::NuclearCellStatus getCellStatus(int row,int column);

	    //check whether game is ovver
	    Constants::PlayerType isGameOver();
};


#endif // NUCLEARREACTOR_H_INCLUDED
