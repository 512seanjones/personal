#include<iostream>
#include<string>

using namespace std;

//Explain rules of the game

void explainrules() {

	cout << "***********************************************" << endl;
	cout << "*                                             *" << endl;
	cout << "* Some General Rules about this game:         *" << endl;
	cout << "*                                             *" << endl;
	cout << "* Player 1 and Player 2 each fill thier boards*" << endl;
	cout << "* with ships varying in length.               *" << endl;
	cout << "* They will then alternate turns choosing     *" << endl;
	cout << "* locations on the board to try and sink the  *" << endl;
	cout << "* enemy's ships.                              *" << endl;
	cout << "*                                             *" << endl;
	cout << "* Letters on the board represents a different *" << endl;
	cout << "* friendly ships.                             *" << endl;
	cout << "*                                             *" << endl;
	cout << "* A represents the Aircraft Carrier           *" << endl;
	cout << "* B represents the Battleship                 *" << endl;
	cout << "* D represents the Destroyer                  *" << endl;
	cout << "* S represents the Submarine                  *" << endl;
	cout << "* P represents the Patrol Boat                *" << endl;
	cout << "*                                             *" << endl;
	cout << "* An X on the board represents an enemy hit on*" << endl;
	cout << "* the friendly ship                           *" << endl;
	cout << "*                                             *" << endl;
	cout << "* A o on the board represnts a miss on the    *" << endl;
	cout << "* attempt to sink the enemy's ship            *" << endl;
	cout << "*                                             *" << endl;
	cout << "* A * on the board represent a hit on the     *" << endl;
	cout << "* attempt to sink the enemy's ship            *" << endl;
	cout << "*                                             *" << endl;
	cout << "*             Good Luck                       *" << endl;
	cout << "*                                             *" << endl;
	cout << "* Make the terminal the height of this box    *" << endl;
	cout << "* for the best size to play on!               *" << endl;
	cout << "*                                             *" << endl;
	cout << "* and NO SCREEN LOOKING!!!                    *" << endl;
	cout << "*                                             *" << endl;
	cout << "***********************************************" << endl;
}

string player1;
string player2;

//Learn who players are
string learnplayer1() {
	cout << "Player 1 what is your name: " << endl << endl;
	cin >> player1;
	cout << endl << "Welcome " << player1 << "!" << endl << endl;
	return player1;
}

string learnplayer2() {
	cout << "Player 2 what is your name: " << endl << endl;
	cin >> player2;
	cout << endl << "Welcome " << player2 << "!" << endl << endl;
	return player2;
}

//Gameboard for ships
const int rows = 10;
const int columns = 10;
char board1[rows][columns] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
    { ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' } }; //board with player 1's ships
char board2[rows][columns] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' } };//board with player 2's ships
char board1d[rows][columns] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' } }; //board for player 1 to track hits and misses
char board2d[rows][columns] = {
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' },
	{ ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ' } }; //board for player 2 to track hits and misses

//Gameboard that displays ships
void makeGameboard1() {
	cout << player1 << "'s board" << endl;
	cout << "*|| A B C D E F G H I J" << endl;
	cout << "=======================" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "||";
		for (int j = 0; j < 10; j++) {
			cout << " " << board1[i][j];
		}
		cout << endl;
	}
}

void makeGameboard2() {
	cout << player2 << "'s board" << endl;
	cout << "*|| A B C D E F G H I J" << endl;
	cout << "=======================" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "||";
		for (int j = 0; j < 10; j++) {
			cout << " " << board2[i][j];
		}
		cout << endl;
	}
}

//Display board for opponenet to keep track of hits and misses
void displayGameboard1() {
	cout << endl << "Previous attacks: " << endl << endl;
	cout << "*|| A B C D E F G H I J" << endl;
	cout << "=======================" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "||";
		for (int j = 0; j < 10; j++) {
			cout << " " << board1d[i][j];
		}
		cout << endl;
	}
}

void displayGameboard2() {
	cout << endl << "Previous attacks: " << endl << endl;
	cout << "*|| A B C D E F G H I J" << endl;
	cout << "=======================" << endl;
	for (int i = 0; i < 10; i++) {
		cout << i << "||";
		for (int j = 0; j < 10; j++) {
			cout << " " << board2d[i][j];
		}
		cout << endl;
	}
}

//Change the column letter to a number, takes user's input and allows it to be put into the gameboard
int findNumberforColumn(char x) {

	int num = 0;

	if (x == 'A' || x == 'a') {
		num = 0;
	}
	if (x == 'B' || x == 'b') {
		num = 1;
	}
	if (x == 'C' || x == 'c') {
		num = 2;
	}
	if (x == 'D' || x == 'd') {
		num = 3;
	}
	if (x == 'E' || x == 'e') {
		num = 4;
	}
	if (x == 'F' || x == 'f') {
		num = 5;
	}
	if (x == 'G' || x == 'g') {
		num = 6;
	}
	if (x == 'H' || x == 'h') {
		num = 7;
	}
	if (x == 'I' || x == 'i') {
		num = 8;
	}
	if (x == 'J' || x == 'j') {
		num = 9;
	}
	return num;
}

//Determine where ships are and what way they are facing
void positionship1(int size, char let) {

	string orientation;
	cout << "The ship is vertical, would you like it to be horizontal? (y/n)" << endl;
	cin >> orientation;

	if (orientation == "y") {

		//keep row constant
		char startlet;
		int start;
		int row;
		int end;

		while (1) {
			cout << "Where would you like to start? " << "Enter the starting point (Enter the letter then the number ex. A0): ";
			cin >> startlet >> row;
			start = findNumberforColumn(startlet);
			end = start + size - 1;

			if (board1[row][start] != ' ' || board1[row][end] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 3 && board1[row][start+1] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 4 && (board1[row][start+1] != ' ' || board1[row][start+2] != ' ')) {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (end > 9) {
				cout << "You need to pick a location that matches the length of the ship" << endl;
			}

			else {
				break;
			}
		}

		for (start; start <= end; start++) {
			board1[row][start] = let;
		}
	}

	else {

		char letter;
		int column;
		int startrow;
		int endrow;

		//keep column constant
		while (1) {
			cout << "Where would you like to start? " << "Enter the starting point (Enter the letter then the number ex. A0): ";
			cin >> letter >> startrow;
			endrow = startrow + size - 1;
			column = findNumberforColumn(letter);

			if (board1[startrow][column] != ' ' || board1[endrow][column] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 3 && board1[startrow + 1][column] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 4 && (board1[startrow + 1][column] != ' ' || board1[startrow + 2][column] != ' ')) {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (endrow > 9) {
				cout << "You need to pick a location that matches the length of the ship" << endl;
			}

			else {
				break;
			}
		}

		for (startrow; startrow <= endrow; startrow++) {
			board1[startrow][column] = let;
		}
	}
}

void positionship2(int size, char let) {

	string orientation;
	cout << "The ship is vertical, would you like it to be horizontal? (y/n)" << endl;
	cin >> orientation;

	if (orientation == "y") {
		char startlet;
		int start;
		int row;
		char endlet;
		int end;

		//keep row constant
		while (1) {
			cout << "Where would you like to start? " << "Enter the starting point (Enter the letter then the number ex. A0): ";
			cin >> startlet >> row;
			start = findNumberforColumn(startlet);
			end = start + size - 1;

			if (board2[row][start] != ' ' || board2[row][end] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 3 && board2[row][start + 1] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 4 && (board2[row][start + 1] != ' ' || board2[row][start + 2] != ' ')) {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (end > 9) {
				cout << "You need to pick a location that matches the length of the ship" << endl;
			}

			else {
				break;
			}
		}

		for (start; start <= end; start++) {
			board2[row][start] = let;
		}
	}

	else {

		char letter;
		int column;
		int startrow;
		int endrow;

		//keep column constant
		while (1) {
			cout << "Where would you like to start? " << "Enter the starting point (Enter the letter then the number ex. A0): ";
			cin >> letter >> startrow;
			endrow = startrow + size - 1;
			column = findNumberforColumn(letter);

			if (board2[startrow][column] != ' ' || board2[endrow][column] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 3 && board2[startrow + 1][column] != ' ') {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (size == 4 && (board2[startrow + 1][column] != ' ' || board2[startrow + 2][column] != ' ')) {
				cout << "This placement interferes with another ship" << endl;
			}

			else if (endrow > 9) {
				cout << "You need to pick a location that matches the length of the ship" << endl;
			}

			else {
				break;
			}
		}

		for (startrow; startrow <= endrow; startrow++) {
			board2[startrow][column] = let;
		}
	}
}


//Player 1 places ships
void placeac1() {
	cout << "Place your Aircraft Carrier (5 spaces)" << endl;
	positionship1(5, 'A');
}

void placeBattleship1() {
	cout << "Place your Battleship (4 spaces)" << endl;
	positionship1(4, 'B');
}

void placeDestroyer1() {
	cout << "Place your Destroyer (3 spaces)" << endl;
	positionship1(3, 'D');
}

void placeSub1() {
	cout << "Place your Submarine (3 spaces)" << endl;
	positionship1(3, 'S');
}

void placePB1() {
	cout << "Place your Patrol Boat (2 spaces)" << endl;
	positionship1(2, 'P');
}

//Player 2 places ships
void placeac2() {
	cout << "Place your Aircraft Carrier (5 spaces)" << endl;
	positionship2(5, 'A');
}

void placeBattleship2() {
	cout << "Place your Battleship (4 spaces)" << endl;
	positionship2(4, 'B');
}

void placeDestroyer2() {
	cout << "Place your Destroyer (3 spaces)" << endl;
	positionship2(3, 'D');
}

void placeSub2() {
	cout << "Place your Submarine (3 spaces)" << endl;
	positionship2(3, 'S');
}

void placePB2() {
	cout << "Place your Patrol Boat (2 spaces)" << endl;
	positionship2(2, 'P');
}

//Set up the board with ships from each player
void setup() {
	makeGameboard1();
	cout << endl << "*when placing ships, they go from left to right or top to bottom" << endl << endl;
	cout << player1 << ", it's time to place your ships!" << endl << "NO LOOKING " << player2 << endl << endl;
	placeac1();
	makeGameboard1();
	placeBattleship1();
	makeGameboard1();
	placeDestroyer1();
	makeGameboard1();
	placeSub1();
	makeGameboard1();
	placePB1();
	makeGameboard1();

	cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;

	makeGameboard2();
	cout << endl << "*when placing ships, they go from left to right or top to bottom" << endl << endl;
	cout << player2 << ", it's time to place your ships!" << endl << "NO LOOKING " << player1 << endl << endl;
	placeac2();
	makeGameboard2();
	placeBattleship2();
	makeGameboard2();
	placeDestroyer2();
	makeGameboard2();
	placeSub2();
	makeGameboard2();
	placePB2();
	makeGameboard2();

	cout << endl << endl << endl << endl << endl << endl << endl << endl;
}

//Track amount of hits

int hit1 = 0; //player one was hit this amount of times
int hit2 = 0; //player two was hit this amount of times

			  //Player 1 makes a move
			  //includes checking for a hit or miss
void player1turn() {
	char let;
	int column;
	int row;
	cout << endl;
	makeGameboard1();
	cout << endl;
	displayGameboard1();
	cout << endl;
	cout << "Choose a position to attack (Enter letter then number ex. A0)" << endl;
	cin >> let >> row;
	column = findNumberforColumn(let);

	if (board2[row][column] != ' ') {
		cout << "*********" << endl;
		cout << "* Hit!! *" << endl;
		cout << "*********" << endl;
		board2[row][column] = 'X';
		board1d[row][column] = '*';
		hit2++;
	}

	//Let them know they already guessed that spot
	else if (board2[row][column] == 'X' || board1d[row][column] == 'o') {
		cout << endl << "You have already guessed that position" << endl;
	}

	else {
		cout << "********" << endl;
		cout << "* Miss *" << endl;
		cout << "********" << endl;
		board1d[row][column] = 'o';
	}
}

//Player 2 makes a move
void player2turn() {
	char let;
	int column;
	int row;
	cout << endl;
	makeGameboard2();
	cout << endl;
	displayGameboard2();
	cout << endl;
	cout << "Choose a position to attack (Enter letter then number ex. A0)" << endl;
	cin >> let >> row;
	column = findNumberforColumn(let);

	if (board1[row][column] != ' ') {
		cout << "*********" << endl;
		cout << "* Hit!! *" << endl;
		cout << "*********" << endl;
		board1[row][column] = 'X';
		board2d[row][column] = '*';
		hit1++;
	}

	else if (board1[row][column] == 'X' || board2d[row][column] == 'o') {
		cout << "You have already guessed that position" << endl;
	}

	else {
		cout << "********" << endl;
		cout << "* Miss *" << endl;
		cout << "********" << endl;
		board2d[row][column] = 'o';
	}
}

int ac1;
int battleship1;
int destroyer1;
int sub1;
int pb1;

//See if any of player 1's ships sunk
void checkac1() {

	ac1 = 0;

	//Decides if there is still at least part of the ship left
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board1[i][j] == 'A') {
				ac1 = 1;
				break;
			}
		}
	}


	if (ac1 != 1) {
		cout << player1 << "'s Aircraft Carrier sunk" << endl;
		ac1 = 2;
	}
}

void checkBattleship1() {

	battleship1 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board1[i][j] == 'B') {
				battleship1 = 1;
				break;
			}
		}
	}

	if (battleship1 != 1) {
		cout << player1 << "'s Battleship sunk" << endl;
		battleship1 = 2;
	}
}

void checkDestroyer1() {

	destroyer1 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board1[i][j] == 'D') {
				destroyer1 = 1;
				break;
			}
		}
	}

	if (destroyer1 != 1) {
		cout << player1 << "'s Destroyer sunk" << endl;
		destroyer1 = 2;
	}
}

void checkSub1() {

	sub1 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board1[i][j] == 'S') {
				sub1 = 1;
				break;
			}
		}
	}

	if (sub1 != 1) {
		cout << player1 << "'s Submarine sunk" << endl;
		sub1 = 2;
	}
}

void checkPB1() {

	pb1 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board1[i][j] == 'P') {
				pb1 = 1;
				break;
			}
		}
	}

	if (pb1 != 1) {
		cout << player1 << "'s Patrol Boat sunk" << endl;
		pb1 = 2;
	}
}

//Checks all of pllayer 1's ships
void checksinks1() {
	if (ac1 != 2) {
		checkac1();
	}
	if (battleship1 != 2) {
		checkBattleship1();
	}
	if (destroyer1 != 2) {
		checkDestroyer1();
	}
	if (sub1 != 2) {
		checkSub1();
	}
	if (pb1 != 2) {
		checkPB1();
	}
}

int ac2;
int battleship2;
int destroyer2;
int sub2;
int pb2;

//See if any of player 2's ships sunk
void checkac2() {

	ac2 = 0;

	//Decides if there is still at least part of the ship left
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board2[i][j] == 'A') {
				ac2 = 1;
				break;
			}
		}
	}


	if (ac2 != 1) {
		cout << player2 << "'s Aircraft Carrier sunk" << endl;
		ac2 = 2;
	}
}

void checkBattleship2() {

	battleship2 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board2[i][j] == 'B') {
				battleship2 = 1;
				break;
			}
		}
	}

	if (battleship2 != 1) {
		cout << player2 << "'s Battleship sunk" << endl;
		battleship2 = 2;
	}
}

void checkDestroyer2() {

	destroyer2 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board2[i][j] == 'D') {
				destroyer2 = 1;
				break;
			}
		}
	}

	if (destroyer2 != 1) {
		cout << player2 << "'s Destroyer sunk" << endl;
		destroyer2 = 2;
	}
}

void checkSub2() {

	sub2 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board2[i][j] == 'S') {
				sub2 = 1;
				break;
			}
		}
	}

	if (sub2 != 1) {
		cout << player2 << "'s Submarine sunk" << endl;
		sub2 = 2;
	}
}

void checkPB2() {

	pb2 = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (board2[i][j] == 'P') {
				pb2 = 1;
				break;
			}
		}
	}

	if (pb2 != 1) {
		cout << player2 << "'s Patrol Boat sunk" << endl;
		pb2 = 2;
	}
}

//Checks all of player 2's ships
void checksinks2() {
	if (ac2 != 2) {
		checkac2();
	}
	if (battleship2 != 2) {
		checkBattleship2();
	}
	if (destroyer2 != 2) {
		checkDestroyer2();
	}
	if (sub2 != 2) {
		checkSub2();
	}
	if (pb2 != 2) {
		checkPB2();
	}
}

//Check for a winner
int checkWinner1() {

	int winner = 0;

	if (hit2 == 17) {
		winner = 1;
	}
	else {
		winner = 0;
	}
	return winner;
}

//If there's 17 total hits, then all the ships were sunk

int checkWinner2() {

	int winner = 0;

	if (hit1 == 17) {
		winner = 2;
	}
	else {
		winner = 0;
	}
	return winner;
}


////////// MAIN FUNCTION ///////////
int main() {

	cout << "LET'S PLAY SOME BATTLESHIP" << endl << endl;
	player1 = learnplayer1();
	player2 = learnplayer2();
	cout << "Here are your gameboards: " << endl << endl;
	makeGameboard1();
	cout << endl;
	makeGameboard2();
	cout << endl;

	int choice;

	while (1) {

		//Menu

		cout << endl;
		cout << "What would you like to do:" << endl;
		cout << "Press 1 to begin playing" << endl;
		cout << "Press 2 to view the rules of the game" << endl;
		cout << "Press anything else to exit" << endl;
		cin >> choice;
		cout << endl;

		switch (choice) {

		case 1: {
			cout << "Let's Start Playing!" << endl << endl;
			setup();
			int winner;
			while (1) {
				//Player 1 takes turn, check if they sunk any ships, check if they won
				player1turn();
				checksinks2();
				winner = checkWinner1();
				if (winner == 1) {
					cout << endl << "Congrats " << player1 << ", you are the winner!" << endl << endl;
					break;
				}
				//Same for player 2
				player2turn();
				checksinks1();
				winner = checkWinner2();
				if (winner == 2) {
					cout << endl << "Congrats " << player2 << ", you are the winner!" << endl << endl;
					break;
				}
			}
			return(1);
		}

		case 2: {
			explainrules();
			break;
		}

		default: {
			cout << "Goodbye" << endl;
			return(1);
		}
		}
	}

	return 1;
}
