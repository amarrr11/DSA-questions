#include <bits/stdc++.h>

using namespace std;

class Game {

public: 

    int grid[9][9];

    void generateSudoku() {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                grid[i][j] = 0;
       
    }

    void printSudoku() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                cout << grid[row][col] << " ";
            }
            cout << endl;
        }
    }

    void userInput() {
        int row, col, num;                    
        char cont;                            
        cout << "Enter your Sudoku values. Input in the format: row(1-9) col(1-9) value(1-9)." << endl;
        cout << "Type 'q' to stop input and start the game." << endl;

        while (true) {
            cout << "Enter row, column, and value (e.g., 1 2 5 for row 1, column 2, value 5): ";

            cin >> row >> col >> num; 

            // if (cin.fail()) {                       
            //     cin.clear();         
            //     cin.ignore(10000, '\n');                         
            //     cout << "Invalid input! Please enter numbers between 1 and 9." << endl;
            //     continue; 
            // }

            if (row >= 1 && row <= 9 && col >= 1 && col <= 9 && num >= 1 && num <= 9) {
                grid[row - 1][col - 1] = num; 
            } else {
                cout << "Invalid input! Please enter numbers between 1 and 9." << endl;
                continue;   
            }

            cout << "Do you want to continue adding numbers (y/n)? ";
            cin >> cont;                     
            
            if (cont == 'n' || cont == 'N') { 
                break;
            }
        }
    }

    void play() {
        char choice;
        cout << "Do you want to solve this Sudoku puzzle? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            if (solveSudoku()) {
                cout << "\nSolved Sudoku Board:\n";
                printSudoku();
            } else {
                cout << "No solution exists!";
            }
        } else {
            cout << "Okay! Exiting the game.";
        }
    }

    bool solveSudoku() {
        int row, col;
        bool isEmpty = true;
        for (row = 0; row < 9; row++) {
            for (col = 0; col < 9; col++) {
                if (grid[row][col] == 0) {
                    isEmpty = false;
                    break;
                }
            }
            if (!isEmpty) {
                break;
            }
        }

        if (isEmpty) {
            return true; 
        }

        for (int num = 1; num <= 9; num++) {
            if (isSafe(row, col, num)) {
                grid[row][col] = num; 

                if (solveSudoku()) {
                    return true;  
                }

                grid[row][col] = 0;  
            }
        }
        return false;  
    }


    bool isSafe(int row, int col, int num) {
        
        for (int x = 0; x < 9; x++){
            if (grid[row][x] == num){
                return false;
            }
        }

        for (int x = 0; x < 9; x++){
            if (grid[x][col] == num){
                return false;
            }
        }
    
        int startRow = row - row % 3, startCol = col - col % 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (grid[i + startRow][j + startCol] == num){
                    return false;
                }
            }
        }

        return true;
    }
    
};

int main() {

    Game sudokuGame;
    sudokuGame.generateSudoku();

    sudokuGame.userInput();

    cout << "\nYour Initial Sudoku Board:\n";
    sudokuGame.printSudoku();

    sudokuGame.play();

    return 0;
}