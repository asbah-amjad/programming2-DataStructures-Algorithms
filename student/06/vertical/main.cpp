#include <iostream>
#ifndef RECURSIVE_FUNC
#define RECURSIVE_FUNC
#endif

using namespace std;

void print_vertical(unsigned int num)
{
    RECURSIVE_FUNC
    // Do not remove RECURSIVE_FUNC declaration, it's necessary for automatic testing to work
    // ------------

               if (num/10 > 0) //no need have else blocks
               {
                   //for the correct order, make the recursive call first
                   print_vertical(num/10);
               }
               //print when you reach the most significant digit
               cout << num%10 << endl;
/*
    // Add your implementation here
    while(num > 0){

        digit = num%10;
        num /= 10;
        array[i] = digit;
        i++;
    }
    for(int j=i-1; j>=0; j--){
        cout << array[j] << endl;
    }*/
}

// Do not modify rest of the code, or the automated testing won't work.
#ifndef UNIT_TESTING
int main()
{
    unsigned int number = 0;
    cout << "Enter a number: ";
    cin >> number;
    cout << "The given number (" << number << ") written vertically:" << endl;
    print_vertical(number);
    return 0;
}
#endif
