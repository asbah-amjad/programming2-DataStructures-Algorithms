#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int line_number=0;
    int word_count = 0;
    map<string, string> words;
    string inputFile = "";
    cout << "Input file: ";
    getline(cin,inputFile);
    ifstream file_object(inputFile);

    if(file_object){

        string line = "";

        while(getline(file_object, line, '\n')){
            line_number = 1;
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
                    word_count = 1;
                }
                else{
                    string add = ", "+to_string(line_number);
                    words.at(*it) += add;
                    word_count++;
                }
            }

            line_number++;
        }

        for(auto result : words){
            cout << result.first << " " << word_count<< ": " << result.second << endl;
        }
        file_object.close();
        return EXIT_SUCCESS;
    }
    else{    

        cout << "Error! The file " << inputFile <<" cannot be opened." << endl;
        return EXIT_FAILURE;

    }
}
