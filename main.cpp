// Henry Bayuzick
// Adam Minor
// Lab 5

#include <iostream>
#include <fstream>
#include <string>
#include "location.h"

using namespace std;

Location cheeseLocations[40000];
Location mouseLocations[40000];

ifstream mazeInput("maze.txt", ios::in);
int rows = 0;
int columns = 0;
char rowsByColumns[200][200];
int mouseRow = -1;
int mouseColumn = -1;
int piecesOfCheese = 0;
int mouseMoves = 0;
int mouseDead = 0;

int currentRow = -1;
int currentColumn = -1;

void printMaze();

void mouseLocation(int &row, int &column);

char checkRight();
char checkLeft();
char checkAbove();
char checkBelow();

void mouseMove();

void moveRight();
void moveLeft();
void moveAbove();
void moveBelow();

void checkForCheese();

int main() {
    
    for (int i = 0; i < 200; i++) {
        rowsByColumns[i][i] = -1;
    }
    
    if (mazeInput.is_open()) {
        mazeInput >> rows >> columns;
        
        cout << "Rows: " << rows << " Columns: " << columns << endl;
        
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < columns; c++) {
                char mazeChar = -1;
                mazeInput >> mazeChar;
                cout << mazeChar;
                rowsByColumns[r][c] = mazeChar;
            }
            cout << "\n";
        }
        
        mazeInput >> mouseRow >> mouseColumn;
        
        mouseLocations[0].setLocation(mouseRow, mouseColumn);
        
        cout << "The mouse is located at: " << mouseLocations[0].getRow() << "x" << mouseLocations[0].getColumn() << endl;
        rowsByColumns[mouseLocations[0].getRow()][mouseLocations[0].getColumn()] = 'M';
        mouseLocation(currentRow, currentColumn);
        
        mazeInput >> piecesOfCheese;
        
        cout << "There are " << piecesOfCheese << " piece(s) of cheese." << endl;
        
        for (int i = 0; i < piecesOfCheese; i++) {
            int cheeseRow = -1;
            int cheeseColumn = -1;
            
            mazeInput >> cheeseRow >> cheeseColumn;
            
            cheeseLocations[i].setLocation(cheeseRow, cheeseColumn);
            rowsByColumns[cheeseLocations[i].getRow()][cheeseLocations[i].getColumn()] = 'c';
            
            cout << "Cheese located at: " << cheeseLocations[i].getRow() << "x" << cheeseLocations[i].getColumn() << endl;
            printMaze();
        }
        
        
    }
    
    else {
        cout << "\nUnable to open file.\n";
    }
    
    cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
    
    while (piecesOfCheese > 0) {
        if (mouseDead == 1) {
            break;
        }
        mouseMove();
    }
    
    if (mouseDead == 1) {
        cout << "Couldn't find all the cheese. The mouse died.\n";
    }
    
    else {
        cout << "The mouse found all the cheese! The mouse survived.\n";
    }
    
    mazeInput.close();

}

void printMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << rowsByColumns[r][c];
        }
        cout << "\n";
    }
}

void checkForCheese() {
    if (rowsByColumns[currentRow][currentColumn] == 'c') {
        cout << "You've found cheese!" << endl;
        piecesOfCheese--;
        cout << piecesOfCheese << " pieces of cheese left." << endl;
    }
}

void mouseLocation(int &row, int &column) {
    row = mouseLocations[mouseMoves].getRow();
    column = mouseLocations[mouseMoves].getColumn();
}

char checkRight() {
    return rowsByColumns[currentRow][currentColumn+1];
}

char checkLeft() {
    return rowsByColumns[currentRow][currentColumn-1];
}

char checkAbove() {
    return rowsByColumns[currentRow-1][currentColumn];
}

char checkBelow() {
    return rowsByColumns[currentRow+1][currentColumn];
}

void mouseMove() {
    if (checkRight() == '.' || checkRight() == 'c') {
        moveRight();
    }
    else if (checkLeft() == '.' || checkLeft() == 'c') {
        moveLeft();
    }
    else if (checkAbove() == '.' || checkAbove() == 'c') {
        moveAbove();
    }
    else if (checkBelow() == '.' || checkBelow() == 'c') {
        moveBelow();
    }
    else {
        cout << mouseMoves;
        if (mouseMoves == 0) {
            mouseDead = 1;
        }
        else {
            cout << "Moved to checkpoint \n";
            rowsByColumns[currentRow][currentColumn] = 'm';
            currentRow = mouseLocations[mouseMoves-1].getRow();
            currentColumn = mouseLocations[mouseMoves-1].getColumn();
            mouseLocation(currentRow, currentColumn);
            rowsByColumns[currentRow][currentColumn] = 'M';
            printMaze();
            mouseMoves--;
        }
    }
}

void moveRight() {
    cout << "Moved right \n";
    mouseMoves++;
    rowsByColumns[currentRow][currentColumn] = 'm';
    mouseLocations[mouseMoves].setLocation(currentRow, currentColumn+1);
    mouseLocation(currentRow, currentColumn);
    checkForCheese();
    rowsByColumns[currentRow][currentColumn] = 'M';
    printMaze();
    cout << mouseMoves;
    cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
}

void moveLeft() {
    cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
    cout << "Moved left \n";
    mouseMoves++;
    rowsByColumns[currentRow][currentColumn] = 'm';
    mouseLocations[mouseMoves].setLocation(currentRow, currentColumn-1);
    mouseLocation(currentRow, currentColumn);
    checkForCheese();
    rowsByColumns[currentRow][currentColumn] = 'M';
    printMaze();
     cout << mouseMoves;
    cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
}

void moveAbove() {
    cout << "Moved above \n";
    mouseMoves++;
    rowsByColumns[currentRow][currentColumn] = 'm';
    mouseLocations[mouseMoves].setLocation(currentRow-1, currentColumn);
    mouseLocation(currentRow, currentColumn);
    checkForCheese();
    rowsByColumns[currentRow][currentColumn] = 'M';
    printMaze();
    cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
}

void moveBelow() {
    cout << "Moved below \n";
    mouseMoves++;
    rowsByColumns[currentRow][currentColumn] = 'm';
    mouseLocations[mouseMoves].setLocation(currentRow+1, currentColumn);
    mouseLocation(currentRow, currentColumn);
    checkForCheese();
    rowsByColumns[currentRow][currentColumn] = 'M';
    printMaze();
    cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
}