/* Path
 *
 * Desc:
 *  This program generates a Path puzzle. The board is ROWS x COLUMNS (5x4),
 * and every round the player chooses a source point and a target point
 * (totally four numbers), making the given button to be moved to the target
 * position (if possible). The game checks if the user-given move can be made.
 *  At start all green buttons are on the top row, and all red buttons are on
 * the bottom row. Game will end when all green buttons have been moved to the
 * bottom row, and all red buttons to the top row. It is not allowed to move a
 * button over another button.
 *  When printing the game board, green button is represented by 'G', red
 * button by 'R', empty hole by 'o', and unused position by empty space.
 *
 * Program author ( Fill with your own info )
 * Name: Asbah Amjad Usmani
 * Student number: H292962
 * UserID: khasus ( Necessary due to gitlab folder naming. )
 * E-Mail: asbahamjad.usmani@tuni.fi
 * Feedback language (fi/en): en
 *
 * Notes about the program and it's implementation:
 *
 * */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum Slot_type {RED, GREEN, EMPTY, UNUSED};
const unsigned int ROWS = 5;
const unsigned int COLUMS = 4;

const string INPUT_TEXT = "Enter start point (x, y) and destination point (x, y), or q to quit: ";
const string INVALID_POINT = "Invalid start/destination point.";
const string CANNOT_MOVE = "There is no path between start point and destination point.";
const string GAME_OVER = "Game over. Congratulations!";
const string MOVES_MADE = " move(s) made.";

//Point structure with x & y coordinates
struct Point{
    string x="";
    string y="";
};
// Prints the grid
void print(const vector<vector<int>>& g) /*vector of vectors or a compatible type*/
{
    cout << "===============" << endl;
    cout << "|   | 1 2 3 4 |" << endl;
    cout << "---------------" << endl;
    for(unsigned int i = 0; i < ROWS; ++i)
    {
        cout << "| " << i + 1 << " | ";
        for(unsigned int j = 0; j < COLUMS; ++j)
        {
            switch(g.at(i).at(j))
            {
            case GREEN: cout << "G "; break;
            case RED: cout << "R "; break;
            case EMPTY: cout << "o "; break;
            case UNUSED: cout << "  "; break;
            }
        }
        cout << "|" << endl;
    }
    cout << "===============" << endl;
}

// Converts the given numeric string to the corresponding integer
// (by calling stoi).
// If the given string is not numeric, returns 0.
unsigned int stoi_with_check(const string& str)
{
    bool is_numeric = true;
    for(unsigned int i = 0; i < str.length(); ++i)
    {
        if(not isdigit(str.at(i)))
        {
            is_numeric = false;
            break;
        }
    }
    if(is_numeric)
    {
        return stoi(str);
    }
    else
    {
        return 0;
    }
}

// More functions

int main()
{
    // More code
    // initializing grid vector according to enum values
    vector<vector<int>> grid {
        { 1, 1, 1, 1},
        { 3, 2, 3, 3},
        { 3, 2, 2, 3},
        { 3, 2, 3, 3},
        { 0, 0, 0, 0}
};
    Point p1,p2;

    print(grid);

    //user will give two points with x & y coordinates

    cout << INPUT_TEXT;
    cin >> p1.x >> p1.y >> p2.x >> p2.y;
    //integer values of x & y coordinates
    int i= stoi(p1.x);
    int j= stoi(p1.y);
    int i1= stoi(p2.x);
    int j1= stoi(p2.y);

    //The given points must consist of numbers
    if((stoi_with_check(p1.x)==0) || (stoi_with_check(p1.y)==0) || (stoi_with_check(p2.x)==0) || (stoi_with_check(p2.y)==0)){
        cout << INVALID_POINT;
    }
    //The given points must be inside the game board.
    // x should not be greater than 4 and x should not be greater than 5.
    else if((i>4) || (j>5) || (i1>4) || (j1>5)){
        cout << INVALID_POINT;
    }
    //The start point must have a button. Green button=1 and Red button=0
    else if((grid.at(j-1).at(i-1)!=1) && (grid.at(j-1).at(i-1)!=0)){
        cout << INVALID_POINT;
    }

    //The destination point must empty. Empty value is 2.
    else if(grid.at(j1-1).at(i1-1)!=2){
        cout << INVALID_POINT;
    }
    else{
        cout << "valid";
    }

    return 0;
}
