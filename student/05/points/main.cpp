#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int main(){

    map<string, int> players;

    string inputFile = "";
    cout << "Input file: ";
    getline(cin,inputFile);
    ifstream file_object(inputFile);

    if(file_object){
        cout << "Final scores:" << endl;

        string line;
        while(getline(file_object, line, '\n')){
            vector<string> p;
            string temp;
           stringstream ss(line);
            while(getline(ss, temp, ':')){
                p.push_back(temp);
            }

            if(players.find(p[0])==players.end()){
            players.insert({p[0],stoi(p[1])});
            }
            else{
                players.at(p[0]) += stoi(p[1]);
            }

        }
        for ( auto data_pair : players ) {
                cout << data_pair.first << ": "
                     << data_pair.second << endl;
            }

        file_object.close();
        return EXIT_SUCCESS;
    }
    else{    

        cout << "Error! The file " << inputFile <<" cannot be opened." << endl;
        return EXIT_FAILURE;

    }
}
