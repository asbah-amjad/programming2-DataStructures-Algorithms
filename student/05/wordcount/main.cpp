#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int line_number=0;
    int count = 0;
    map<string, string> words;
    string inputFile = "";
    cout << "Input file: ";
    getline(cin,inputFile);
    ifstream file_object(inputFile);

    if(file_object){

        string line = "";
        string word;
        while(getline(file_object, line, '\n')){
            line_number = 1;

            if(line.find(word) != string::npos){
                count++;
            }

            line_number++;
        }


        file_object.close();
        return EXIT_SUCCESS;
    }
    else{    

        cout << "Error! The file " << inputFile <<" cannot be opened." << endl;
        return EXIT_FAILURE;

    }
}
