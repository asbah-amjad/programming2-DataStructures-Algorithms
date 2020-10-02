#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string inputFile = "";
    string outputFile = "";
    int i=1;
   // cout << "Input file: ";
    getline(cin,inputFile);
  //  cout << "Output file: ";
    getline(cin,outputFile);

    ofstream output(outputFile);
    ifstream file_object(inputFile);
    if(file_object){
        cout << "Input file: " << inputFile <<endl;
        cout << "Output file: " << outputFile << endl;

        string line;
        while(getline(file_object, line, '\n')){

            output << i << " " << line << endl;
            i++;
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
