// Lab 5
// Henry and Adam

#include "location.h"

void Location::setLocation (int newRow, int newColumn) {
    row = newRow;
    column = newColumn;
}

int Location::getRow() const {
    return row;
}

int Location::getColumn() const {
    return column;
}