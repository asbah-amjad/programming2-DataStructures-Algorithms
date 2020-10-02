#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string inputFile = "";
    string outputFile = "";

    cout << "Input file name: ";
    getline(cin,inputFile);
    cout << "Output file name: ";
    getline(cin,outputFile);

    ofstream output(outputFile);
    ifstream file_object(inputFile);
    if(file_object){
        cout << "Input file: " << inputFile << endl;
        cout << "Output file: " << outputFile << endl;

        string line;
        while(getline(file_object, line)){
            output << line;
        }
        output.close();
        file_object.close();
    }
    else{    
        cout << "Input file: " << inputFile << endl;
        cout << "Output file: " << outputFile << endl;
        cout << "Error! The file " << inputFile <<" cannot be opened." << endl;
        return EXIT_FAILURE;

    }
}
