#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(){

    string key = "";
    string::size_type len=0;
    char char_array[len+1];

    cout << "Enter the encryption key: ";
    getline(cin,key);
    len=key.length();

    if(len<26){
        cout << "Error! The encryption key must contain 26 characters.";
        return EXIT_FAILURE;
    }

    for(int i=0; i<len;i++){
        int ascii= int(key[i]);
        if(!(ascii>=97 && ascii<=122)){
            cout << "Error! The encryption key must contain all alphabets a-z.";
            return EXIT_FAILURE;
        }

    }

    for(int i=0; i<len;i++){
        char_array[i] = key[i];
        if(!islower(char_array[i])){
            cout << "Error! The encryption key must contain only lower case characters.";
            return EXIT_FAILURE;
        }
    }

    string encrypt="";
    cout << "Enter the text to be encrypted: ";
    getline(cin,encrypt);
    string::size_type l=0;
    l = encrypt.length();

    for(int i=0; i<l; i++){
        char_array[i] = encrypt[i];
        if(!islower(char_array[i])){
            cout << "Error! The encryption key must contain only lower case characters.";
            return EXIT_FAILURE;
        }
    }

}
