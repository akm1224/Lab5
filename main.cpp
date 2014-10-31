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
        
        mouseLocations[0].setLocation("mouse", mouseRow, mouseColumn);
        
        cout << "The mouse is located at: " << mouseLocations[0].getRow() << "x" << mouseLocations[0].getColumn() << endl;
        rowsByColumns[mouseLocations[0].getRow()-1][mouseLocations[0].getColumn()-1] = 'M';
        
        mazeInput >> piecesOfCheese;
        
        cout << "There are " << piecesOfCheese << " piece(s) of cheese." << endl;
        
        for (int i = 0; i < piecesOfCheese; i++) {
            int cheeseRow = -1;
            int cheeseColumn = -1;
            
            mazeInput >> cheeseRow >> cheeseColumn;
            
            cheeseLocations[i].setLocation("cheese", cheeseRow, cheeseColumn);
            rowsByColumns[cheeseLocations[i].getRow()-1][cheeseLocations[i].getColumn()-1] = 'c';
            
            cout << "Cheese located at: " << cheeseLocations[i].getRow() << "x" << cheeseLocations[i].getColumn() << endl;
        }
    }
    
    else {
        cout << "\nUnable to open file.\n";
    }
    
    cout << "Map" << endl;
    printMaze();
    
    while (piecesOfCheese > 0) {
        mouseLocation(currentRow, currentColumn);
        
        cout << "Mouses current location is: " << currentRow << "x" << currentColumn << endl;
        
        if (rowsByColumns[currentRow][currentColumn] == 'c') {
            cout << "You've found cheese!" << endl;
            piecesOfCheese--;
            rowsByColumns[currentRow][currentColumn] = 'm';
            cout << piecesOfCheese << " pieces of cheese left." << endl;
        }
        else {
            mouseMove();
        }
        
    }
    cout << checkRight(tempRow,tempColumn) << endl;
    cout << checkLeft(tempRow,tempColumn) << endl;
    cout << checkAbove(tempRow,tempColumn) << endl;
    cout << checkBelow(tempRow,tempColumn) << endl;
    
    mazeInput.close();
    
//    get location
//    if (location == cheese location)
//        found it
//        else
//            check all around
//            if (not + or m)
//                get locations of . (rows, columns) and store in array
//                mark current location as "m"
//                if multiple locations in array
//                    add location of (rows, columns) intersection to stack to later backtrack
//                    out of the multiple multiple moves, take first available move
//                    else
//                        make only available move

}

void printMaze() {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < columns; c++) {
            cout << rowsByColumns[r][c];
        }
        cout << "\n";
    }
}

void mouseLocation(int &row, int &column) {
    row = mouseLocations[mouseMoves].getRow()-1;
    column = mouseLocations[mouseMoves].getColumn()-1;
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
    if (checkRight() == '.') {
        moveRight();
    }
    else if (checkLeft() == '.') {
        moveLeft();
    }
    else if (checkAbove() == '.') {
        moveUp();
    }
    else if (checkBelow() == '.') {
        moveDown();
    }
    else {
        currentRow = mouseLocations[mouseMoves-1].getRow();
        currentColumn = mouseLocations[mouseMoves-1].getColumn();
        mouseMoves--;
    }
}