// Henry Bayuzick
// Adam Minor
// Lab 5

#ifndef LOCATION_H
#define LOCATION_H

#include <string>

using namespace std;

class Location {
private:
    string type;
    int row;
    int column;
public:
    Location() {
        type = "none";
        column = -1;
        row = -1;
    }
    
    int getType() const;
    int getColumn() const;
    int getRow() const;
    
    void setLocation (string type, int newRow, int newColumn);
};
#endif
