/* Education_center
 *
 * Desc:
 *  This program reads the course collection data of different education centers from a
 * file at startup. Input file contains the data in the format
 * <location>;<theme>;<course_name>;<number_of_enrollments>, then it stores them in
 * a suitable data structure and gives the user the opportunity
 * to search the data structure using different commands like locations,
 * courses <location> <theme>, available, courses_in_theme <theme>, favorite_theme.
 * To exit the program, user must enter the quit.
 *
 * Program author
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
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

const string FULL = "full";
const string UNKOWN_CMND = "Error: Unknown command: ";
const string WRONG_PARAM = "Error: error in command ";
const string UNKOWN_LOCATION = "Error: unknown location name";
const string UNKOWN_THEME = "Error: unknown theme";

struct course {
    string name;
    string theme;
    int enrollments;
}c;

map<string,course> education_center;

void print_struct(struct course a){
    cout << a.theme << " " << a.name << " " << a.enrollments << endl;
}

int main()
{
    string input_file = "";
    string line = "";
    string word = "";
    vector<string> row;

    cout << "Input file: ";
    getline(cin, input_file);
    ifstream file_object(input_file);

    if(file_object){

        while(getline(file_object, line, '\n')){
            //used for breaking words
            stringstream s(line);
            while(getline(s, word, ';')){

                //fields cannot be empty or filled with spaces only
                if(word.empty() || word==" "){
                    cout << "Error: empty field" << endl;
                    return EXIT_FAILURE;
                }
                else{
                    row.push_back(word);

                }
            }
            if(row.size() < 4){
                cout << "Error: empty field" << endl;
                return EXIT_FAILURE;
            }
            else{
                c.theme = row[1];
                c.name = row[2];
                if(row[3] == "full"){
                    row[3] = 50;
                }
                c.enrollments = stoi(row[3]);
                education_center.insert({row[0], c});
                row.clear();
            }
        }
        for(auto& data: education_center){
            cout << data.first << endl;
            print_struct(data.second);
        }
        file_object.close();
    }
    else{
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }

    return 0;
}
