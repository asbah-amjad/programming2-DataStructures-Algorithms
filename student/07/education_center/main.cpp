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
#include <utility>

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
}info;

using education_center = map<pair<string, pair<string, string>>, int>;

int main()
{
    string input_file = "";
    string line = "";
    string word = "";
    string location = "";
    string command = "";
    vector<string> row;
    education_center edu;

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
                    //pushing words in a vector
                    row.push_back(word);
                }
            }
            if(row.size() < 4){
                cout << "Error: empty field" << endl;
                return EXIT_FAILURE;
            }
            else{
                location = row[0];
                //storing course information from vector into struct
                info.theme = row[1];
                info.name = row[2];
                if(row[3]=="full"){
                    row[3] = 50;
                }
                info.enrollments = stoi(row[3]);
                //education_center.insert(make_pair(location, make_pair(info.theme, info.name)), info.enrollments);
                edu.insert({{location, {info.theme, info.name}}, {info.enrollments}});
                row.clear();
            }
        }
        /*
        cout << "> ";
        getline(cin, command);

        if(command == "quit"){
            return EXIT_SUCCESS;
        }*/
        for(auto& data: edu){
            cout << data.first.first << " ";
            cout << data.first.second.first << " " << data.first.second.second << " ";
            cout << data.second << endl;
        }

        file_object.close();
    }
    else{
        cout << "Error: the input file cannot be opened" << endl;
        return EXIT_FAILURE;
    }

    return 0;
}
