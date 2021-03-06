#include<iostream>
#include<string>
#include<cctype>
#include <bits/stdc++.h>
using namespace std;

bool checkPangram(string str)
{
    // Create a hash table to mark the characters
    // present in the string
    vector<bool> mark(26, false);

    // For indexing in mark[]
    int index;

    // Traverse all characters
    for (unsigned int i = 0; i < str.length(); i++) {

        // If lowercase character, subtract 'a'
        // to find index.
        if ('a' <= str[i] && str[i] <= 'z')
            index = str[i] - 'a';

        // If this character is other than english
        // lowercase and uppercase characters.
        else
            continue;

        mark[index] = true;
    }

    // Return false if any character is unmarked
    for (int i = 0; i <= 25; i++)
        if (mark[i] == false)
            return (false);

    // If all characters were present
    return (true);
}

void encryption(string k, string s){

    string::size_type l1=0;
    l1 = k.length();

    for(unsigned int i=0; i<l1; i++){

            replace(s.begin(),s.end(),char(97+i),k[i]);
    }

    cout << "Encrypted text: " << s;
}
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

    for(unsigned int i=0; i<len;i++){
        char_array[i] = key[i];
        if(!islower(char_array[i])){
            cout << "Error! The encryption key must contain only lower case characters.";
            return EXIT_FAILURE;
        }
    }
    
    if(checkPangram(key)==false){
        cout << "Error! The encryption key must contain all alphabets a-z.";
        return EXIT_FAILURE;
    }

    string encrypt="";
    cout << "Enter the text to be encrypted: ";
    getline(cin,encrypt);
    string::size_type l=0;
    l = encrypt.length();

    for(unsigned int i=0; i<l; i++){
        char_array[i] = encrypt[i];
        if(!islower(char_array[i])){
            cout << "Error! The encryption key must contain only lower case characters.";
            return EXIT_FAILURE;
        }
    }

    encryption(key,encrypt);

}
