//
//  location.cpp
//  Lab 5
//
//  Created by Henry on 10/22/14.
//  Copyright (c) 2014 Henry Bayuzick. All rights reserved.
//

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