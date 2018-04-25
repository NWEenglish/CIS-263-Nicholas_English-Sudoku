/**********************************************************************
 * This code solves a Sudoku game by the use of the backtracking 
 * technique. The code will then print the solved Sudoku game at the
 * end of it's run.
 *
 * @author Nicholas English
 * @version 1.0
 * @date 4/22/2018
 *********************************************************************/

/* Librarie(s) */
#include <iostream>
#include <vector>
#include <string>

/* Main Function */
int main(int argc, char *argv[]) {

    /* Variable(s) */
    bool isSolved;

    /* Creates a board */
    int board[9][9] = {{ 0, 3, 0, 0, 0, 0, 0, 2, 0 },
	{ 0, 9, 0, 0, 0, 0, 0, 8, 5 },
	{ 5, 0, 0, 0, 8, 0, 4, 0, 0 },
	{ 4, 0, 7, 2, 0, 6, 8, 9, 0 },
	{ 0, 1, 0, 8, 0, 9, 0, 4, 0 },
	{ 0, 8, 9, 5, 0, 1, 3, 0, 2 },
	{ 0, 0, 3, 0, 1, 0, 0, 0, 9 },
	{ 9, 4, 0, 0, 0, 0, 0, 1, 0 },
	{ 0, 7, 0, 0, 0, 0, 0, 3, 0 }};

    /* Checks if the board was solved. */
    isSolved = solve(board,0,0);

    /* Prints out to the user the status of the board. */
    if(isSolved){
	std::cout << "Found a solution:\n" << std::endl;
	printBoard(board);
    }
    else {
	std::cout << "No solution found." << std::endl;
    }

    /* End of program reached */
    std::cout << "\n\n\n" << std::ebdl;
    return 0;
}

/**********************************************************************
 * Helper Functions
 *********************************************************************/

/**********************************************************************
 * solve is the function responsible for managing if the Sudoku board
 * is solved.
 *
 * @param board is a 9x9 board that holds the current items on the
 * 	Sudoku board.
 *********************************************************************/
bool solve( int board[9][9] ) {

    /* Variable(s) */
    int row;
    int col;
    int value;

    /* Checks if there are any unassinged locations first */
    if( !findBox )
	return true;

    /* Begins trying to place items onto the Sudoku board */
    // Attempt all digits between one and nine.
    for( value = 1; value <= 9; value++ ) {

	// Checks if spot is valid
	if( isValidSpace( board, row, col, value ) ) {

	    // Places it on the board for now.
	    board[row][col] = value;

	    // Begins recursion.
	    if( solve( board ) )
		return true;

	    // If it reaches here, this level of recursion fails.
	    // Therefore we remove the value from the current location.
	    board[row][col] = 0;
	} 

    }

}

/**********************************************************************
 * isValidSpace returns true or false depending on if that space is
 * available based on if the spot is open AND if it matches the correct
 * criteria to be allowed there.
 *
 * @param board is a 9x9 board that holds the current items on the
 * 	Sudoku board.
 * @param row is the current row the space is in.
 * @param col is the current column the space is in.
 * @return true if the spot is good or false if it is bad.
 *********************************************************************/
bool isValidSpace( int board[9][9], int row, int col, int value ) {

    // Checks if the value occures in the same row/column.
    for( int i = 0; i < 9; i++ ) {
	if( board[i][col] == value)
	    return false;
	if( board[row][i] == value)
	    return false;
    }

    // Variables
    int rowStart;
    int rowEnd;
    int colStart;
    int colEnd;

    // Find the start and end of the row.
    if ( row < 3 )
	rowStart = 0;
    else if ( row > 5 )
	rowStart = 6;
    else
	rowStart = 3;
    
    rowEnd = rowStart + 3;

    // Finds the start and end of the column.
    if ( col < 3 )
	colStart = 0;
    else if ( col > 5 )
	colStart = 6;
    else
	colStart = 3;

    colEnd = colStart + 3;

    // Checks if the value occures in the same box set.
    for( int i = rowStart; i < rowEnd; i++ )
	for( int j = colStart; j < colEnd; j++ )
	    if( board[i][j] == value )
		return false;

    // If reaches the end of the program, then it must be true.
    return true;

}

/**********************************************************************
 * findBox finds the next available spot for a number on the board.
 *
 * @param board is a 9x9 board that holds the current items on the
 * 	Sudoku board.
 * @param row holds the address of the space being checked.
 * @param col holds the address of the space being checked.
 * @return 
 *********************************************************************/
bool findBox(int board[9][9], int &row, int &col) {

    // Loops until it finds the first open space.
    for( int i = 0; i < 9; i++)
	for( int j = 0; j < 9; j++)
	     if( board[i][j] == 0 ) {
		row = i;
		col = j;
		return false;
	    }
    return true;

}

/**********************************************************************
 * printBoard is a function that prints the board. This will be called
 * only once the program has determined the Sudoku board has been
 * solved correctly.
 *
 * @param board is a 9x9 board that holds the current items on the 
 * 	Sudoku board.
 *********************************************************************/
void printBoard( int board[9][9] ) {

    for( int row = 0; row < 9; row++ ) {
	for ( int col = 0; col < 9; col++ )
	    std::cout << " " << board[row][col];

	std::cout << std::endl;
    }
}

