#include<iostream>
#include<string>
using namespace std;

string player1;
string player2;

//Learn who players are
void learnplayer1(){
	cout << "Please enter your name Player 1: ";
	cin >> player1;
}

void learnplayer2() {
	cout << "Please enter your name Player 2: ";
	cin >> player2;
}

//View rules of the game
void rules() {
	cout << "********************************" << endl;
	cout << "*        CONNECT 4!!           *" << endl;
	cout << "*                              *" << endl;
	cout << "* The goal of this game is to  *" << endl;
	cout << "* have four of your pieces     *" << endl;
	cout << "* connected, and to stop your  *" << endl;
	cout << "* opponent from connecting     *" << endl;
	cout << "* theirs!                      *" << endl;
	cout << "* You can achieve this goal by *" << endl;
	cout << "* having your pieces connect   *" << endl;
	cout << "* vertically, horizontally and *" << endl;
	cout << "* diagonally!                  *" << endl;
	cout << "*                              *" << endl;
	cout << "* An X represents player 1's   *" << endl;
	cout << "* piece                        *" << endl;
	cout << "* An O represents player 2's   *" << endl;
	cout << "* piece                        *" << endl;
	cout << "*                              *" << endl;
	cout << "* Have Fun and Good Luck!!     *" << endl;
	cout << "********************************" << endl;
}

const int row = 6;
const int column = 7;
char board[row][column] = {
	{ ' ',' ',' ',' ',' ',' ',' ' },
    { ' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ' } };

//Print the gameboard
void createboard() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			cout << "|" << board[i][j];
		}
		cout << "|" << endl;
	}
	cout << "---------------" << endl;
	cout << " 0 1 2 3 4 5 6" << endl;
}

//Counts moves so game can end in draw
int moves = 0;
//Player 1 makes a move
void move1() {
	int play1;
	while (1) {

		cout << endl << player1 << "'s turn" << endl << "You are X" << endl << endl;
		cout << "What column would you like to place your chip in?" << endl;
		cin >> play1;

		if (play1 > 6 || play1 < 0) {
			cout << "Pick a row between 0 and 6!" << endl;
		}
		else {
			break;
		}
	}

	int row1 = 5;
	while (1) {
		if (board[row1][play1] == 'X' || board[row1][play1] == 'O') {
			row1--;
		}
		else if (row1 < 0) {
			cout << "That column is filled!" << endl;
			break;
		}
		else {
			board[row1][play1] = 'X';
			moves++;
			break;
		}
	}
}

//Player 2 makes a move
void move2() {
	int play2;
	while (1) {

		cout << endl << player2 << "'s turn" << endl << "Your are O" << endl << endl;
		cout << "What column would you like to place your chip in?" << endl;
		cin >> play2;

		if (play2 > 6 || play2 < 0) {
			cout << "Pick a row between 0 and 6!" << endl;
		}
		else {
			break;
		}
	}
	int row2 = 5;
	while (1) {
		if (board[row2][play2] == 'X' || board[row2][play2] == 'O') {
			row2--;
		}
		else if (row2 < 0) {
			cout << "That column is filled!" << endl;
			break;
		}
		else {
			board[row2][play2] = 'O';
			moves++;
			break;
		}
	}
}

int checkwinner1() {

	int i, j;

	while (1) {

		//checks horizontal
		for (i = 0; i < row; i++) {
			for (j = 0; j < column-3; j++) {
				if (board[i][j] == 'X' && board[i][j + 1] == 'X' && board[i][j + 2] == 'X' && board[i][j + 3] == 'X') {
					cout << "11" << endl;
					return 1;
					break;
				}
			}
		}


		//checks vertical
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column; j++) {
				if (board[i][j] == 'X' && board[i + 1][j] == 'X' && board[i + 2][j] == 'X' && board[i + 3][j] == 'X') {
					cout << "12" << endl;
					return 1;
					break;
				}
			}
		}


		//checks right diagonal(negative slope line)
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column-3; j++) {
				if (board[i][j] == 'X' && board[i + 1][j + 1] == 'X' && board[i + 2][j + 2] == 'X' && board[i + 3][j + 3] == 'X') {
					cout << "13" << endl;
					return 1;
					break;
				}
			}
		}


		//checks left diagonal(positive slope line)
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column; j++) {
				if (board[i][j] == 'X' && board[i + 1][j - 1] == 'X' && board[i + 2][j - 2] == 'X' && board[i + 3][j - 3] == 'X') {
					cout << "14" << endl;
					return 1;
					break;
				}
			}
		}
		return 0;
		break;

	}
}

int checkwinner2() {

	int i, j;

	while (1) {

		//checks horizontal
		for (i = 0; i < row; i++) {
			for (j = 0; j < column-3; j++) {
				if (board[i][j] == 'O' && board[i][j + 1] == 'O' && board[i][j + 2] == 'O' && board[i][j + 3] == 'O') {
					cout << "21" << endl;
					return 2;
					break;
				}
			}
		}


		//checks vertical
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column; j++) {
				if (board[i][j] == 'O' && board[i + 1][j] == 'O' && board[i + 2][j] == 'O' && board[i + 3][j] == 'O') {
					cout << "22" << endl;
					return 2;
					break;
				}
			}
		}


		//checks right diagonal
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column-3; j++) {
				if (board[i][j] == 'O' && board[i + 1][j + 1] == 'O' && board[i + 2][j + 2] == 'O' && board[i + 3][j + 3] == 'O') {
					cout << "23" << endl;
					return 2;
					break;
				}
			}
		}


		//checks left diagonal
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column; j++) {
				if (board[i][j] == 'O' && board[i + 1][j - 1] == 'O' && board[i + 2][j - 2] == 'O' && board[i + 3][j - 3] == 'O') {
					cout << "24" << endl;
					return 2;
					break;
				}
			}
		}
		return 0;
		break;
	}
}

int main() {

	cout << "Lets Play Connect 4!" << endl << endl;
	createboard();
	cout << endl;
	learnplayer1();
	cout << endl << endl;
	learnplayer2();
	cout << endl << endl;

	int choice;
	while (1) {
		cout << "What would you like to do?" << endl;
		cout << "Press 1 to begin playing" << endl;
		cout << "Press 2 to view the rules" << endl;
		cout << "Press anything else to exit" << endl;

		cin >> choice;

		switch (choice) {
		case 1: {
			createboard();
			while (1) {
				int winner;
				move1();
				createboard();
				winner = checkwinner1();

				if (winner == 1) {
					cout << endl << "**Congrats " << player1 << ", you won!!!**" << endl << endl;
					break;
				}

				cout << endl;

				move2();
				createboard();
				winner = checkwinner2();

				if (winner == 2) {
					cout << endl << "**Congrats " << player2 << " you won!!!**" << endl << endl;
					break;
				}

				cout << endl;

				if (moves == 42) {
					cout << endl << "It's a draw!! " << endl << endl;
					break;
				}
			}
			return(1);
		}
		case 2: {
			rules();
			break;
		}
		default: {
			cout << "Goodbye" << endl;
			return(1);
		}
		}
	}
	while (1) {
		move1();
		createboard();
		move2();
		createboard();
	}
	return 1;
}
