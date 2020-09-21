#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

void read_integers(std::vector< int >& ints, int count)
{
    int new_integer = 0;
    for(int i = 0; i < count; ++i)
    {
        std::cin >> new_integer;
        // TODO: Implement your solution here
        ints.push_back(new_integer);
    }
}

// TODO: Implement your solution here
bool same_values(std::vector<int>& ints){

    if(std::adjacent_find(ints.begin(),ints.end(),std::not_equal_to<int>() )==ints.end())
        return true;
    else
        return false;
}

bool is_ordered_non_strict_ascending(std::vector<int>& ints){
    std::vector<int>::size_type length = ints.size();
    for(unsigned int i=0; i<length-1; i++){
        if(ints[i] > ints[i+1]){
            return false;
        }
    }
    return true;
}

bool is_arithmetic_series(std::vector<int>& ints){

    std::vector<int>::size_type length = ints.size();
    //int result[length];
    //std::adjacent_difference(ints.begin(),ints.end(),result);
    int d = ints[1] - ints[0];
    for(unsigned int i=2; i<length; i++){
        if(ints[i]-ints[i-1] != d){
            return false;
        }
    }
    return true;
}

bool is_geometric_series(std::vector<int>& ints){

    std::vector<int>::size_type length = ints.size();
    if(ints[0]==0 && ints[1]==0)
        return false;
    int ratio = ints[1]/(ints[0]);
    for(unsigned int i=1; i<length; i++){
        if( (ints[i]/(ints[i-1])) != ratio )
            return false;
    }
    return true;
}

int main()
{
    std::cout << "How many integers are there? ";
    int how_many = 0;
    std::cin >> how_many;

    std::cout << "Enter the integers: ";
    std::vector<int> integers;
    read_integers(integers, how_many);

    if(same_values(integers))
        std::cout << "All the integers are the same" << std::endl;
    else
        std::cout << "All the integers are not the same" << std::endl;

    if(is_ordered_non_strict_ascending(integers))
        std::cout << "The integers are in a non-strict ascending order" << std::endl;
    else
        std::cout << "The integers are not in a non-strict ascending order" << std::endl;

    if(is_arithmetic_series(integers))
        std::cout << "The integers form an arithmetic series" << std::endl;
    else
        std::cout << "The integers do not form an arithmetic series" << std::endl;

    if(is_geometric_series(integers))
        std::cout << "The integers form a geometric series" << std::endl;
    else
        std::cout << "The integers do not form a geometric series" << std::endl;

    return EXIT_SUCCESS;
}
