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
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

struct course {
    string name;
    string theme;
    int enrollments;
}info;

using education_center = map<pair<string, pair<string, string>>, int>;
//for string comparison
bool compare_fn(string a, string b){
    return a<b;
}

std::vector<std::string> split(const std::string& s, const char delimiter, bool ignore_empty = false){
    std::vector<std::string> result;
    std::string tmp = s;

    while(tmp.find(delimiter) != std::string::npos)
    {
        std::string new_part = tmp.substr(0, tmp.find(delimiter));
        tmp = tmp.substr(tmp.find(delimiter)+1, tmp.size());
        if(not (ignore_empty and new_part.empty()))
        {
            result.push_back(new_part);
        }
    }
    if(not (ignore_empty and tmp.empty()))
    {
        result.push_back(tmp);
    }
    return result;
}

int main()
{
    string input_file = "";
    string line = "", word = "";
    string location = "";
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
                location = row.at(0);
                //storing course information from vector into struct
                info.theme = row.at(1);
                info.name = row.at(2);
                if(row.at(3)=="full"){
                    row.at(3) = "50";
                }
                info.enrollments = stoi(row.at(3));
                // inserting data into map
                education_center::iterator iter = edu.find({location, {info.theme, info.name}});
                //if key doesn't exist in map, then store the data
                if(iter == edu.end()){
                    edu.insert({{location, {info.theme, info.name}}, {info.enrollments}});
                }
                //otherwise update the value
                else{
                    iter->second = info.enrollments;
                }
                row.clear();
            }
        }

        while(true){

        cout << "> ";
        string command = "";
        getline(cin, command);
        vector<string> param = split(command, ' ', true);

        if(param.at(0) == "quit"){
            return EXIT_SUCCESS;
        }

        else if(param.at(0) == "locations"){
            vector<string> loc;

            for(auto& location : edu){
                if(find(loc.begin(), loc.end(), location.first.first) == loc.end()){
                    loc.push_back(location.first.first);
                }
            }
            //alphabetical ordered vector
            sort(loc.begin(), loc.end(), compare_fn);
            for(auto& data : loc){
                cout << data << endl;
            }
        }

        else if(param.at(0) == "courses"){
            string a = param.at(2);
            //vector for storing all locations present in map
            vector<string> locations;
            //vector for storing all themes present in map
            vector<string> themes;

            if(param.size() < 3){
                cout << "Error: error in command courses" << endl;
            }

            //theme name consist of more than one word
            if(param.size() > 3){
                string t = param.at(2)+" "+param.at(3);
                t.erase(remove(t.begin(), t.end(), '\"'), t.end());
                param.at(2) = t;
            }
            //theme surrounded by double quotes
            if(a.at(0)=='\"' && a.at(a.length()-1)=='\"'){
                param.at(2) = a.substr(1, a.length()-2);
            }

            for(auto& p : edu){

                if(find(locations.begin(), locations.end(), p.first.first) == locations.end()){
                    locations.push_back(p.first.first); //locations
                }

                if(find(themes.begin(), themes.end(), p.first.second.first) == themes.end()){
                    themes.push_back(p.first.second.first); //themes
                }
            }

            if((find(locations.begin(), locations.end(), param.at(1)) != locations.end()) &&
                    (find(themes.begin(), themes.end(), param.at(2)) != themes.end())){
                for(auto& course : edu){
                    if((param.at(1) == course.first.first) && (param.at(2) == course.first.second.first)){
                        cout << course.first.second.second << " --- ";
                        if(course.second == 50){
                            cout << "full" << endl;
                        }
                        else{
                            cout << course.second << " enrollments" << endl;
                        }
                    }
                }
            }
            else if(find(locations.begin(), locations.end(), param.at(1)) == locations.end()){
                cout << "Error: unkown location name" << endl;
            }
            else if(find(themes.begin(), themes.end(), param.at(2)) == themes.end()){
                cout << "Error: unkown theme" << endl;
            }
            else if((find(locations.begin(), locations.end(), param.at(1)) == locations.end()) &&
                    (find(themes.begin(), themes.end(), param.at(2)) == themes.end())){
                cout << "Error: unkown location name" << endl;
            }
        }

        else if(param.at(0) == "courses_in_theme"){
            //vector for storing all themes present in map
            vector<string> param_1;
            for(auto& p : edu){
                if(find(param_1.begin(), param_1.end(), p.first.second.first) == param_1.end()){
                    param_1.push_back(p.first.second.first); //themes
                }
            }

            if(find(param_1.begin(), param_1.end(), param.at(1)) != param_1.end()){
                //vector for storing all course name corresponding to themes present in map
                vector<string> theme;
                for(auto& c_theme : edu){
                    if(param.at(1) == c_theme.first.second.first){
                        if(find(theme.begin(), theme.end(), c_theme.first.second.second) == theme.end()){
                        theme.push_back(c_theme.first.second.second); //course name
                        }
                    }
                }
                //alphabetical ordered vector
                sort(theme.begin(), theme.end(), compare_fn);
                for(auto& result : theme){
                    cout << result << endl;
                }
            }
            else{
                cout << "Error: unkown theme" << endl;
            }

        }

        else if(param.at(0) == "favorite_theme"){
            map<string, int> fav_theme;
            int max=0;
            vector<string> t;

            for(auto& fav : edu){

                map<string, int>::iterator it = fav_theme.find(fav.first.second.first);
                if(it == fav_theme.end()){
                    fav_theme.insert({fav.first.second.first, fav.second});
                }
                else{
                    it->second = (it->second + fav.second);
                }
            }
            if(fav_theme.size()==0){
                cout << "No enrollments" << endl;
            }
            else{
                //finding max enrollments
                for(auto& it : fav_theme){
                  if(it.second > max){
                      max = it.second;
                  }
                }
                cout << max << " enrollments in themes" << endl;

                for(auto& theme : fav_theme){
                    if(theme.second == max){
                        cout << "--- " << theme.first << endl;
                    }
                }
            }
        }

        else if(param.at(0) == "available"){

            for(auto& free_courses : edu){
                if(free_courses.second < 50){
                    cout << free_courses.first.first << " : ";
                    cout << free_courses.first.second.first << " : ";
                    cout << free_courses.first.second.second << endl;
                }
            }
        }

        else{
            cout << "Error: Unknown command: " << param.at(0) << endl;
        }

        }


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
