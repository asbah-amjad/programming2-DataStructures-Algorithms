#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int line_number=1;

    map<string, string> words;
    string inputFile = "";
    cout << "Input file: ";
    getline(cin,inputFile);
    ifstream file_object(inputFile);

    if(file_object){

        string line = "";

        while(getline(file_object, line, '\n')){

            vector<string> p;
            string temp;
            stringstream ss(line);
            while(getline(ss, temp, ' ')){

                if(find(p.begin(),p.end(),temp) == p.end()){
                p.push_back(temp);
                }

            }
            for(auto it=begin(p); it!=end(p); ++it){

                if(words.find(*it)==words.end()){

                    words.insert({*it,to_string(line_number)});

                }
                else{

                    string add = ", "+to_string(line_number);
                    words.at(*it) += add;

                }
            }

            ++line_number;
        }

        for(auto result : words){
            string r = result.second;
            stringstream count(r);
            vector<string> test;
            string t;
            while(getline(count, t, ',')){
                test.push_back(t);
            }
            cout << result.first << " " << test.size()<< ": " << result.second << endl;
        }
        file_object.close();
        return EXIT_SUCCESS;
    }
    else{    

        cout << "Error! The file " << inputFile <<" cannot be opened." << endl;
        return EXIT_FAILURE;

    }
}
