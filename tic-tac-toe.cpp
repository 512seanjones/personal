#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char board[3][3]={
	{ ' ',' ',' ' },
	{ ' ',' ',' ' },
	{ ' ',' ',' ' }};
	
void colorText(string message, int color){
	cout << "\033[1;" << color << "m" << message << "\033[0m";
	}

void createBoard(){
	for (int i=0; i<3; i++){
		stringstream ss;
		string s;
		ss << i+1;
		ss >> s;
		colorText(s, 31);
		colorText(":", 31);
		for (int j=0; j<3; j++){
			if (board[i][j] == ' '){
				//cout << "\033[1;44m \033[0m";
				colorText(" ", 44);
				}
			else {
				stringstream ss1;
				string s1;
				ss1 << board[i][j];
				ss1 >> s1;
				colorText(s1, 32);
				}
			if (j<2){
				colorText("|", 31);
				}
			}
		cout << endl;
		if (i<2){
			colorText("  -----", 31);
			cout << endl;
			}
		}	
	colorText("  A B C", 31);
	cout << endl;
	}
	
int convertNum(char letter){
	if (letter == 'a'|| letter == 'A'){
		return 0;
		}
	else if (letter == 'b'|| letter == 'B'){
		return 1;
		}
	else if (letter == 'c'|| letter == 'C'){
		return 2;
		}
	}	

void playerMove(){
	cout << "You are X, where do you want to go?" << endl;
	while (1){
		cout << "Please type a number then a letter and press enter" << endl;
		char choice[2];
		cin >> choice;
		if (choice[0] != '1' && choice[0] != '2' && choice[0] != '3'){
			cout << "Invalid Choice" << endl;
			continue;
			}
		else if (choice[1] != 'a'&& choice[1] != 'b' && choice[1] != 'c'&& choice[1] != 'A'&& choice[1] != 'B'&& choice[1] != 'C'){
			cout << "Invalid Choice" << endl;
			continue;
			}
		else{
			int num1 = (choice[0] - '0') - 1;
			int num2 = convertNum(choice[1]);
			if (board[num1][num2] != ' '){
				cout << "Can not move there" << endl;
				}
			else {
				board[num1][num2] = 'X';
				createBoard();
				break;
				}
			}
		}
	}

bool findOppening(char l){
	for (int i=0; i<3; i++){
		if (board[i][0] == board[i][1] && board[i][0] == l){
			if (board[i][2] == ' '){
				board[i][2] = 'O';
				return true;
				}
			}
		else if (board[i][0] == board[i][2] && board[i][0] == l){
			if (board[i][1] == ' '){
				board[i][1] = 'O';
				return true;
				}
			}
		else if (board[i][1] == board[i][2] && board[i][1] == l){
			if (board[i][0] == ' '){
				board[i][0] = 'O';
				return true;
				}
			}
		}
		
	for (int i=0; i<3; i++){
		if (board[0][i] == board[1][i] && board[0][i] == l){
			if (board[2][i] == ' '){
				board[2][i] = 'O';
				return true;
				}
			}
		else if (board[0][i] == board[2][i] && board[0][i] == l){
			if (board[1][i] == ' '){
				board[1][i] = 'O';
				return true;
				}
			}
		else if (board[1][i] == board[2][i] && board[1][i] == l){
			if (board[0][i] == ' '){
				board[0][i] = 'O';
				return true;
				}
			}
		}
		
	if (board[0][0] == board[1][1] && board [0][0] == l){
		if (board[2][2] == ' '){
			board[2][2] = 'O';
			return true;
			}
		}
	else if (board[0][0] == board[2][2] && board [0][0] == l){
		if (board[1][1] == ' '){
			board[1][1] = 'O';
			return true;
			}
		}
	else if (board[2][2] == board[1][1] && board [2][2] == l){
		if (board[0][0] == ' '){
			board[0][0] = 'O';
			return true;
			}
		}
		
	if (board[0][2] == board[1][1] && board [0][2] == l){
		if (board[2][0] == ' '){
			board[2][0] = 'O';
			return true;
			}
		}
	else if (board[0][2] == board[2][0] && board [0][2] == l){
		if (board[1][1] == ' '){
			board[1][1] = 'O';
			return true;
			}
		}
	else if (board[2][0] == board[1][1] && board [2][0] == l){
		if (board[0][2] == ' '){
			board[0][2] = 'O';
			return true;
			}
		}
	return false;
	}
	
void hardTurn(){
	cout << "My Turn..." << endl;
	bool moveBlocked = false;
	bool findWin = false;
	findWin = findOppening('O');
	if (findWin == true){
		createBoard();
		return;
		}	
	moveBlocked = findOppening('X');
	if (moveBlocked == false){
		if (board[0][0] == ' '){
			board[0][0] = 'O';
			}
		else if (board[0][2] == ' '){
			board[0][2] = 'O';
			}
		else if (board[2][2] == ' '){
			board[2][2] = 'O';
			}
		else if (board[2][0] == ' '){
			board[2][0] = 'O';
			}
		else {
			cout << "Error can not find move" << endl;
			}
		}
	createBoard();
	}

void easyTurn(){
	cout << "My Turn..." << endl;
	bool moveBlocked = false;
	bool findWin = false;
	findWin = findOppening('O');
	if (findWin == true){
		createBoard();
		return;
		}	
	moveBlocked = findOppening('X');
	if (moveBlocked == false){
		if (board[1][1] == ' '){
			board[1][1] = 'O';
			}
		else if (board[0][1] == ' '){
			board[0][1] = 'O';
			}
		else if (board[1][0] == ' '){
			board[1][0] = 'O';
			}
		else if (board[1][2] == ' '){
			board[1][2] = 'O';
			}
		else if (board[2][1] == ' '){
			board[2][1] = 'O';
			}
		else if (board[0][0] == ' '){
			board[0][0] = 'O';
			}
		else if (board[0][2] == ' '){
			board[0][2] = 'O';
			}
		else if (board[2][2] == ' '){
			board[2][2] = 'O';
			}
		else if (board[2][0] == ' '){
			board[2][0] = 'O';
			}
		else {
			cout << "Error can not find move" << endl;
			}
		}
	createBoard();	
	}
	
int checkWinner(){
	for (int i=0; i<3; i++){
		if (board[i][0] == board[i][1] &&  board[i][1] == board[i][2]){
			if (board[i][0] == 'X'){
				return 1;
				}
			if (board[i][0] == 'O'){
				return 2;
				}
			}
		}
	for (int i=0; i<3; i++){
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			if (board[0][i] == 'X'){
				return 1;
				}
			if (board[0][i] == 'O'){
				return 2;
				}
			}
		}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		if (board[0][0] == 'X'){
			return 1;
			}
		if (board[0][0] == 'O'){
			return 2;
			}
		}
	if (board[0][2] == board[1][1] &&  board[1][1] == board[2][0]){
		if (board[0][2] == 'X'){
			return 1;
			}
		if (board[0][2] == 'O'){
			return 2;
			}
		}
	return 0;
	}
	
int checkTie(){
	int count = 0;
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			if (board[i][j] == ' '){
				count ++;
				}
			}
		}
	return count;
	}

void clearBoard(){
	for (int i=0; i<3; i++){
		for (int j=0; j<3; j++){
			board[i][j] = ' ';
			}
		}
	}
int main(){
	while (1){
		bool gameOver = false;
		cout << "Type 1 to play, type anything else to exit" << endl;
		clearBoard();
		int play;
		cin >> play;
		if (play == 1){
			int choice;
			while (gameOver == false){
				cout << "Type 1 for Easy or 2 for Hard" << endl;
				cin >> choice;
				if (choice == 1){
					createBoard();
					while (1){
						playerMove();
						if (checkWinner()==1){
							cout << "Congrats you won!!" << endl;
							gameOver = true;
							break;
							}
						if (checkTie() == 0){
							cout << "It is a tie!!" << endl;
							gameOver = true;
							break;
							}
						if (board[1][1] == 'X'){
							hardTurn();
							}
						else {
							easyTurn();
							}
						if (checkWinner()==2){
							cout << "Haha I won!!" << endl;
							gameOver = true;
							break;
							}
						}
					}
				else if (choice == 2){
					while (1){
						if (board[1][1] == 'X' && board[2][2] == ' '){
							cout << "My Turn..." << endl;
							board[2][2] = 'O';
							createBoard();
							}
						else {
							hardTurn();
							}
						if (checkWinner() == 2){
							cout << "Haha I won!!" << endl;
							gameOver = true;
							break;
							}
						if (checkTie() == 0){
							cout << "It is a tie!!" << endl;
							gameOver = true;
							break;
							}
						playerMove();
						if (checkWinner() == 1){
							cout << "Congrats you won!!" << endl;
							gameOver = true;
							break;
							}
						}
					}
				else {
					cout << "Invalid Choice" << endl;
					}
				}
			}
		else {
			break;
			}
		}
	return 0;
	}
