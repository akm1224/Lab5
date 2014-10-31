// Lab 5
// Henry and Adam

#include "location.h"

void Location::setLocation (string newType, int newRow, int newColumn) {
    type = newType;
    row = newRow;
    column = newColumn;
}

int Location::getRow() const {
    return row;
}

int Location::getColumn() const {
    return column;
}