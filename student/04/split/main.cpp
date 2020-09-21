#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// TODO: Implement split function here
// Do not change main function
std::vector< std::string > split(std::string line, char seperator,bool empty=false){
/*
    if(empty == true){
        //line.erase(remove(line.begin(),line.end(), ' '), line.end());
        for(int i=0;i<line.length();i++)
            if(line[i] == ' ') line[i]='\b';
    }
 */
    std::vector< std::string > result;
    std::stringstream ss(line);
    std::string item;
    while(std::getline(ss, item, seperator)){
        result.push_back(item);
    }
    return result;
}

int main()
{
    std::string line = "";
    std::cout << "Enter a string: ";
    getline(std::cin, line);
    std::cout << "Enter the separator character: ";
    char separator = getchar();

    std::vector< std::string > parts  = split(line, separator);
    std::cout << "Splitted string including empty parts: " << std::endl;
    for( auto part : parts ) {
        std::cout << part << std::endl;
    }

    std::vector< std::string > parts_no_empty  = split(line, separator, true);
    std::cout << "Splitted string ignoring empty parts: " << std::endl;
    for( auto part : parts_no_empty ) {
        std::cout << part << std::endl;
    }
}
