// Henry Bayuzick
// Adam Minor
// Lab 5

#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location {
private:
    int row;
    int column;
public:
    Location() {
        column = -1;
        row = -1;
    }
    
    int getColumn() const;
    int getRow() const;
    
    void setLocation (int newRow, int newColumn);
};
#endif
