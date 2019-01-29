#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>
using namespace std;

class node{
public:
    int row;
    int col;
    int box;
    /*
    1 2 3
    4 5 6
    7 8 9
    */
    int value;
    bool set;
    node* next;
    int list[10];

    node(){
        row = col = 0;
        box = 0;
        value = 0;
        set = false;
        next = NULL;
        for (int i = 0; i < 9; i++)
            list[i] = 0;
    }
};

class board{
public:
    node* start;

    board(){
        start = new node;
        node* temp;
        temp = start;
        for(int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                temp->row = i;
                temp->col = j;
                temp->box = setBox(i, j);
                temp->value = 0;
                temp->next = new node;
                temp = temp->next;
            }
        }
    }
    void enterValue(int r, int c, int v){
        node* temp;
        temp = start;
        for (int i = 0; i < (r*9 + c) ; i++){
            temp = temp->next;
        }
        if (temp->set){
            char x;
            cout << "Number already entered here, do you want to rewrite? (y/n) ";
            cin >> x;
            if (x != 'y')
                return;
        }
        if(checkCol(temp->col, v) && checkRow(temp->row, v) && checkSquare(temp->box, v)){
            temp->value = v;
            temp->set = true;
        }
        else
            cout << "This entry is not allowed\n";
    }
    int setBox(int r, int c){
        if (r <= 2){
            if (c <= 2)
                return 1;
            else if (c <= 5)
                return 2;
            else
                return 3;
        }
        else if (r <= 5){
            if (c <= 2)
                return 4;
            else if (c <= 5)
                return 5;
            else
                return 6;
        }
        else{
            if (c <= 2)
                return 7;
            else if (c <= 5)
                return 8;
            else
                return 9;
        }
    }
    node* createList(int x){
        node* temp = goToSquare(x);
        // creates list of possibilities for each box, numbers are zero if they won't work
        for (int i = 1; i <= 9; i++){
            if(checkCol(temp->col, i) && checkRow(temp->row, i) && checkSquare(temp->box, i) && temp->value < i)
                temp->list[i-1] = i;
            else
                temp->list[i-1] = 0;
        }
        return temp;
    }
    bool solve(){
        node *temp;
        // goes through list of possibilities guessing each one
        int counter = 1;
        int updown = 1;
        int i;
        //int animate = 0;
        while (counter > 0 && counter < 82){
            temp = createList(counter);
            if(!temp->set){
                for (i = 0; i < 9; i++){
                    if (temp->list[i] != 0){
                        temp->value = temp->list[i];
                        updown = 1;
                        counter++;
                        break;
                    }
                }
                if (i == 9){
                    temp->value = 0;
                    updown = 0;
                    counter--;
                }
            }
            else{ // this is a pre-set box
                if (updown == 1)
                    counter++;
                else
                    counter--;
            }
            // animate++;
            // if (animate == 250){
            //     display();
            //     system("cls");
            //     animate = 0;
            // }
        }
        if (counter == 0)
            return false;
        else
            return true;
    }
    node* goToSquare(int x){
        node* temp = start;
        for (int i = 1; i < x; i++)
            temp = temp->next;
        return temp;
    }
    bool checkRow(int r, int val){
        node* temp = start;
        while(temp != NULL){
            if (temp->row == r){
                if (temp->value == val)
                    return false;
            }
            temp = temp->next;
        }
        return true;
    }
    bool checkCol(int c, int val){
        node* temp = start;
        while(temp != NULL){
            if (temp->col == c){
                if (temp->value == val)
                    return false;
            }
            temp = temp->next;
        }
        return true;
    }
    bool checkSquare(int b, int val){
        node* temp = start;
        switch (b) {
            case 1:
                while (temp->row <= 2){
                    if(temp->col <= 2){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 2:
                while (temp->row <= 2){
                    if(temp->col >= 3 && temp->col <= 5){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 3:
                while (temp->row <= 2){
                    if(temp->col >= 6 && temp->col <= 8){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 4:
                while (temp->row <= 5){
                    if(temp->row >= 3 && temp->col <= 2){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 5:
                while (temp->row <= 5){
                    if(temp->row >= 3 && temp->col >= 3 && temp->col <= 5){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 6:
                while (temp->row <= 5){
                    if(temp->row >= 3 && temp->col >= 6 && temp->col <= 8){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 7:
                while (temp != NULL){
                    if(temp->row >= 6 && temp->col <= 2){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 8:
                while (temp != NULL){
                    if(temp->row >= 6 && temp->col >= 3 && temp->col <= 5){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
            case 9:
                while (temp != NULL){
                    if(temp->row >= 6 && temp->col >= 6 && temp->col <= 8){
                        if (temp->value == val)
                            return false;
                    }
                    temp = temp->next;
                }
                break;
        }
        return true;
    }
    void display(){
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        node* temp;
        temp = start;
        cout <<"-----------\n";
        for(int i = 0; i < 9; i++){
            if (i == 3 || i == 6)
                cout <<"-----------\n";
            for (int j = 0; j < 9; j++){
                if (temp->set == true)
                    SetConsoleTextAttribute(hConsole, 10);
                cout << temp->value;
                SetConsoleTextAttribute(hConsole, 15);
                temp = temp->next;
                if (j == 2 || j == 5)
                    cout << "|";
            }
            cout << '\n';
        }
        cout <<"-----------\n";
    }
};

int main(){
    board myBoard;
    int row, col, val;
    char choice = 'n';
    while(1){
        string fileName = "sodokuInput.txt";
        cout << "Would you like to load 'sodokuInput.txt'? (y/n): ";
        cin >> choice;
        if (choice != 'y'){
            cout << "What file would you like to load: ";
            cin >> fileName;
        }
        ifstream file(fileName);
        string line;
        row = col = val = 0;
        int num = 0;
        while (getline(file, line)){
            if (num != 3 && num != 7){
                for (int i = 0; i < 11; i++){
                    if (line[i] != '|'){
                        if (line[i] != '0'){
                            val = line[i] - '0';
                            myBoard.enterValue(row, col, val);
                        }
                        col++;
                    }
                }
                row++;
            }
            col = 0;
            num++;
            if(num > 10)
                break;
        }
        myBoard.display();
        cout << "Is this board correct? (y/n): ";
        cin >> choice;
        if (choice == 'y')
            break;
    }
    cout << "\nAttempting to solve...\n\n";
    if(myBoard.solve()){
        cout << "Successfully solved\n\n";
        myBoard.display();
    }
    else
        cout << "Could not solve\n";
    return 1;
}
