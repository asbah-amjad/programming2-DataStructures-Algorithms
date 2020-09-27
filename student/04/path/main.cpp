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
//To count moves
    int moves = 0;

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
void pathFinder(int i, int j, int i1, int j1, vector<vector<int>>& grid){

    //pure horizontal path, source and target lies on same row
    if(j==j1){
        if(i1>i){
            for(int k=i;k<i1-1;k++){
                if(grid[j-1][k]!=EMPTY)
                     cout << CANNOT_MOVE << endl;
                else{
                    cout << "move" << endl;
                    moves++;
                }

          }
        }
        else{
            for(int k=i1;k<i-1;k++){
                if(grid[j-1][k]!=EMPTY)
                     cout << CANNOT_MOVE << endl;
                else{
                    cout << "move" << endl;
                    moves++;
                }
        }
    }
  }
    //source and target do not lie on same row
    if(j!=j1){
           //for both 1 and 3 path is same to reach cross point
        if(i==1 || i==3){
            //horizontal right move check check
            if(grid[j-1][1]==EMPTY){
                   if(j==1){
                       if(grid[1][1]==EMPTY && grid[2][1]==EMPTY){
                           //reached cross point
                       }
                       else{
                           cout << CANNOT_MOVE << endl;
                       }
                   }
                   if(j==5){
                       if(grid[3][1]==EMPTY && grid[2][1]==EMPTY){
                           //reached cross point
                       }
                       else{
                           cout << CANNOT_MOVE << endl;
                       }
                   }
            }
            else{
                cout << CANNOT_MOVE << endl;
            }
        }
        if(i==2){
            if(j==1){
                if(grid[j][i-1]==EMPTY && grid[j+1][i-1]==EMPTY){
                    //reached cross point
                }
                else{
                    cout << CANNOT_MOVE << endl;
                }
            }
            if(j==5){
                if(grid[j-2][i-1]==EMPTY && grid[j-3][i-1]==EMPTY){
                    //reached cross point
                }
                else{
                    cout << CANNOT_MOVE << endl;
                }
            }
        }
        /*
        if(i==3){
            if(grid[j-1][1]==EMPTY){
                if(j==1){
                    if(grid[1][1]==EMPTY && grid[2][1]==EMPTY){
                        //reached cross point
                    }
                    else{
                        cout << CANNOT_MOVE << endl;
                    }
                }
                if(j==5){
                    if(grid[3][1]==EMPTY && grid[2][1]==EMPTY){
                        //reached cross point
                    }
                    else{
                        cout << CANNOT_MOVE << endl;
                    }
                }
            }
            else{
                cout << CANNOT_MOVE << endl;
            }
        }*/
            //horizontal left move check
            if(i==4){
                if(grid[j-1][2] == EMPTY && grid[j-1][1] == EMPTY){
                    if(j==1){
                        if(grid[1][1]==EMPTY && grid[2][1]==EMPTY){
                            //reached cross point
                        }
                        else{
                            cout << CANNOT_MOVE << endl;
                        }
                    }
                    if(j==5){
                        if(grid[3][1]==EMPTY && grid[2][1]==EMPTY){
                            //reached cross point
                        }
                        else{
                            cout << CANNOT_MOVE << endl;
                        }
                    }
                }
                else{
                    cout << CANNOT_MOVE << endl;
                }
            }


    }
   // source and target lie on straight path of check point
    if(i==2 && i1==2 && grid[i-1][i-1]==EMPTY && grid[i][i-1]==EMPTY && grid[i+1][i-1]==EMPTY){
        cout << "move" << endl;
        moves++;
    }


}
int main()
{
    // More code
    // initializing grid vector according to enum values
    vector<vector<int>> grid {
        { GREEN, GREEN, GREEN, GREEN},
        { UNUSED, EMPTY, UNUSED, UNUSED},
        { UNUSED, EMPTY, EMPTY, UNUSED},
        { UNUSED, EMPTY, UNUSED, UNUSED},
        { RED, RED, RED, RED}
};
    //user will give two points with x & y coordinates
    Point p1,p2;

    print(grid);

    while(true){

    cout << INPUT_TEXT;
    cin >> p1.x;

    if(p1.x == "q"){
    break;
    }

    cin >> p1.y >> p2.x >> p2.y;
    //integer values of x & y coordinates
    int i= stoi(p1.x);
    int j= stoi(p1.y);
    int i1= stoi(p2.x);
    int j1= stoi(p2.y);

    //The given points must consist of numbers
    if((stoi_with_check(p1.x)==0) || (stoi_with_check(p1.y)==0) || (stoi_with_check(p2.x)==0) || (stoi_with_check(p2.y)==0)){
        cout << INVALID_POINT << endl;
    }
    //The given points must be inside the game board.
    // x should not be greater than 4 and x should not be greater than 5.
    else if((i>4) || (j>5) || (i1>4) || (j1>5)){
        cout << INVALID_POINT<< endl;
    }
    //The start point must have a button.
    else if((grid.at(j-1).at(i-1)!=GREEN) && (grid.at(j-1).at(i-1)!=RED)){
        cout << INVALID_POINT<< endl;
    }

    //The destination point must empty.
    else if(grid.at(j1-1).at(i1-1)!=EMPTY){
        cout << INVALID_POINT<< endl;
    }
    else{
        cout << "valid" << endl;
        pathFinder(i,j,i1,j1,grid);
    }
   }
    return 0;
}
