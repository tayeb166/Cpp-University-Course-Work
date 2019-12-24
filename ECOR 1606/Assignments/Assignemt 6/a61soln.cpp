/*
Assignment #6 Part #1 TIC TAC TOE
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;


// initialize takes a nine element gameBoard and doesn't return anything.
// It sets the elements of the gameBoard to integers from 1 to 9 starting
// from the upper left.
void initialize(int gameBoard[]){
	int i;
	for (i=0;i<9;i++){
		gameBoard[i]=i+1;		// set up the board with cell number in each location
	} // end for
} // end initialize


// playCell takes a player (0 for "O", 1 for "X"), a position (1 to 9),
// and the nine element gameBoard, and returns true if the move is legal
// (i.e. that spot is not yet taken), and false otherwise.  If the move is
// legal it changes the position to that players number (10 for "O", 11 for "X").
// If the player or position input is invalid, it returns false;
bool playCell(int player, int position, int gameBoard[]){
	// check for invalid input 
	if (player<0 || player>1 || position<1 || position>9) {
		return false;
	}
	// check board							
	if (gameBoard[position-1]<10){	// not yet used
		gameBoard[position-1]=player+10;	// set position to be 10 or 11 depending on player
		return true;
	} // end if
	return false; // position was already taken
} // end playCell


// winCheck checks the gameBoard for a winner.
// Returns 0 if "O" has won; 1 if "X" has won; and -1 if no winner (yet).
// It assumes the board has only 1 winner.
// (the "const" indicates that we will not change the gameBoard in this function.)
int winCheck (const int gameBoard[]){
	int i;	
	
	// check the rows (0,1,2 or 3,4,5 or 6,7,8)
	for (i=0;i<9;i+=3){
		if (gameBoard[i]==gameBoard[i+1] && gameBoard[i]==gameBoard[i+2]){
			return gameBoard[i]-10;		// subtract 10 for the winner	
		}
	}// end for
	
	// check the columns (0,3,6 or 1,4,7 or 2,5,8)	
	for(i=0;i<3;i++) {  
		if (gameBoard[i]==gameBoard[i+3] && gameBoard[i]==gameBoard[i+6]){
			return gameBoard[i]-10;		// subtract 10 for the winner
		} // end if
	} // end for
	
	// check the diagonal starting upper left (0,4,8)
	if (gameBoard[0]==gameBoard[4] && gameBoard[0]==gameBoard[8]){
		return gameBoard[0]-10;		// subtract 10 for the winner
	} 
	
	// check the other diagonal (2,4,6)
	if (gameBoard[2]==gameBoard[4] && gameBoard[2]==gameBoard[6]){
		return gameBoard[2]-10;		// subtract 10 for the winner
	} // end if
	
	// if we get here, there is no winner (yet)
	return -1;

} // end winCheck


// printBoard takes the gameBoard and doesn't return anything.
// It prints out the current state of the board to the display.
// (the "const" indicates that we will not change the gameBoard in this function.)
void printBoard(const int gameBoard[]){
	int i;
	for (i=0; i<9; i++) {
		// if it's the start of a row, print a horizontal divider line and the first
		// vertical line of the next line
		if (i%3==0) {
			cout << endl << "+-----+-----+-----+" << endl << "|  ";
		}
		
		// if it's a 10, output "O", if it's 11, output "X", otherwise
		// output the current contents
		if (gameBoard[i]==10) {
			cout << "O";
		} else if (gameBoard[i]==11) {
			cout << "X";
		} else {
			cout << gameBoard[i];
		}
		// output a vertical line
		cout << "  |  ";
	}//end for
	// output the bottom horizontal divider line
	cout << endl << "+-----+-----+-----+" << endl;
}//end printBoard


// (getIntBP is an improved version of getInt written in Assignment #5, Question #1,
// as it is "bullet-proof".)
// Returns an integer value from the user between minimum and 
// maximum, inclusive.
// We assume that the calling function has output the initial 
// request for input.
// This function will check the value entered and output an error 
// message until a value in the correct range is entered.
// This function deals correctly with non-integer inputs.
int getIntBP(int minimum, int maximum){
	int value;
    // loop until we get an integer value between minimum and maximum, inclusive
    for(;;) {
        cin >> value;
        // loop until we have an integer input
        while (cin.fail()) { // invalid (non-integer) input, output error message and flush buffer
			cout << "Input must be an integer between " << minimum << " and "
             	 << maximum << " inclusive, try again: ";
			cin.clear(); cin.ignore(INT_MAX, '\n'); // throw away the line of input
			cin >> value;
		}
		if (value>=minimum && value<=maximum) { // valid range, so return it
            return value;
        }
        // value was outside valid range, so output error message
        cout << "Input must be an integer between " << minimum << " and "
             << maximum << " inclusive, try again: ";
    }//end for
}//end getInt


int main() {
	
	int board[9], // the tic-tac-toe board
		move, // the move number: 0 to 8
		turn, //  0 = "O"'s turn; 1 = "X"'s turn
		playerFirst=0, // we start with "O" going first
		winPlayer; // 0 is "O", 1 is "X", -1 is no winner yet or tie
	char player[2] = {'O','X'};	// a character array 'O' or 'X'
	
	// play until user enters 0 to stop
	for(;;) { 
		
		// initialize and print the board
		initialize(board);
		printBoard(board);
		
		// loop once for every turn (max of 9)
		for (move=0; move<9; move++) {
			
			turn = (move+playerFirst)%2; // 0 (O) or 1 (X)'s turn
			
			// that player makes a move
			for(;;){
				cout << "Player " << player[turn] << " choose cell to play in: ";
				if (playCell(turn,getIntBP(1,9),board)) {
					break;	
				}
				cout << "Cell already used" << endl;
			} // end for
			
			printBoard(board);	// show the board
			
			// check for a winner if this is the fifth move or more (moves start at 0)
			if (move>3) {
				winPlayer=winCheck(board); // look for a winner if 5 or more moves
				if (winPlayer!=-1) { // we have a winner
					cout << "Player " << player[winPlayer] << " wins!\n\n";
					playerFirst=(winPlayer+1)%2; // other player goes first next time
					break; // this game is over
				}//end if
			}//end if
		} // end for move
		
		// check for no winner
		if (winPlayer==-1){		// no one won
			cout << "Game is a draw.\n\n";
			playerFirst=(playerFirst+1)%2;	// Flip the first player for next game
		} // end if
		
		cout << "Do you wish to play again (Enter 1 for Yes or 0 for No)?: ";
		// if user enters 0, we exit, otherwise continue
		if (!getIntBP(0,1)) {
			break;
		}
	} // end for
	
	system ("PAUSE"); return 0;

} // end main


