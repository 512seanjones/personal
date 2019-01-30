/*
By Sean Jones
CS-501 Final Project
This project was creating a connect 4 game
This was based off of final proect 2 and was exercise 8.20
*/

import java.util.Scanner;
public class ConnectFour{
    public static void main(String[] args){
        System.out.println("Welcome to Connect 4! Here are the rules for the game\n");
        printRules();
        while(true){
            Scanner input = new Scanner(System.in);
            System.out.println("Are you ready to play? Enter y to play or anything else to exit");
            char choice = input.next().charAt(0);
            if (choice != 'y'){
                System.out.println("Goodbye");
                return;
            }
            char[][] board = {
                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                {' ', ' ', ' ', ' ', ' ', ' ', ' '}};
            int moves = 0;
            printBoard(board);
            while(true){
                if (goPlayer(board, 'R')){
                    System.out.println("Winner! Congratulations Player 1\n");
                    break;
                }
                moves++;
                if (goPlayer(board, 'Y')){
                    System.out.println("Winner! Congratulations Player 2\n");
                    break;
                }
                moves++;
                if (moves == 42){
                    System.out.println("\nIt's a tie\n");
                    break;
                }
            }
            System.out.println("Time to play again!\n");
        }
    }

    public static void printRules(){
    	System.out.println("********************************");
    	System.out.println("*        CONNECT 4!!           *");
    	System.out.println("*                              *");
    	System.out.println("* The goal of this game is to  *");
    	System.out.println("* have four of your pieces     *");
    	System.out.println("* connected and to stop your   *");
    	System.out.println("* opponent from connecting     *");
    	System.out.println("* theirs!                      *");
        System.out.println("*                              *");
    	System.out.println("* You can achieve this goal by *");
    	System.out.println("* having your pieces connect   *");
    	System.out.println("* vertically, horizontally and *");
    	System.out.println("* diagonally!                  *");
    	System.out.println("*                              *");
    	System.out.println("* An R represents player 1's   *");
    	System.out.println("* piece                        *");
    	System.out.println("* An Y represents player 2's   *");
    	System.out.println("* piece                        *");
    	System.out.println("*                              *");
        System.out.println("* You will alternate placing   *");
        System.out.println("* pieces until someone wins or *");
        System.out.println("* the board is full            *");
        System.out.println("*                              *");
    	System.out.println("* Have Fun and Good Luck!!     *");
    	System.out.println("********************************");
    }

    public static void printBoard(char[][] board){
        System.out.print("\n");
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 7; j++){
                System.out.print("|");
                System.out.print(board[i][j]);
            }
            System.out.print("|\n");
        }
        System.out.println("---------------");
        System.out.println(" 0 1 2 3 4 5 6");
        System.out.print("\n");
    }

    public static boolean goPlayer(char[][] board, char player){
        Scanner input = new Scanner(System.in);
        boolean fill = false;
        boolean valid = false;
        int col = -1;
        int playerNum;
        if (player == 'R')
            playerNum = 1;
        else
            playerNum = 2;
        System.out.println("Player "+ playerNum + "'s turn (you are " + player + ")");
        while(!fill){
            while(!valid){
                input = new Scanner(System.in);
                try{
                    while (true){
                        System.out.print("What column would you like to place your piece in (0 - 6): ");
                        col = input.nextInt();
                        if (col < 0 || col > 6)
                            System.out.println("Please pick a column between 0 and 6");
                        else{
                            valid = true;
                            break;
                        }
                    }
                }
                catch (Exception e){
                    System.out.println("Invalid column choice");
                }
            }
            for (int i = 5; i >= 0; i--){
                if (board[i][col] == ' '){
                    board[i][col] = player;
                    fill = true;
                    break;
                }
            }
            if (!fill)
                System.out.println("That row is filled, please pick a different one");
        }
        printBoard(board);
        boolean win = checkWinner(board, player);
        return win;
    }

    public static boolean checkWinner(char[][] board, char player){
        int i, j;
        int row = 6;
        int column = 7;
		//checks horizontal
		for (i = 0; i < row; i++) {
			for (j = 0; j < column-3; j++) {
				if (board[i][j] == player && board[i][j + 1] == player && board[i][j + 2] == player && board[i][j + 3] == player)
					return true;
			}
		}
		//checks vertical
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column; j++) {
				if (board[i][j] == player && board[i + 1][j] == player && board[i + 2][j] == player && board[i + 3][j] == player)
					return true;
			}
		}
		//checks right diagonal(negative slope line)
		for (i = 0; i < row-3; i++) {
			for (j = 0; j < column-3; j++) {
				if (board[i][j] == player && board[i + 1][j + 1] == player && board[i + 2][j + 2] == player && board[i + 3][j + 3] == player)
					return true;
			}
		}
		//checks left diagonal(positive slope line)
		for (i = 0; i < row-3; i++) {
			for (j = 3; j < column; j++) {
				if (board[i][j] == player && board[i + 1][j - 1] == player && board[i + 2][j - 2] == player && board[i + 3][j - 3] == player)
					return true;
			}
		}
		return false;
    }
}
