#include<iostream>
#include<cmath>
using namespace std;

int main(){

      unsigned int num =0;
      cout << "Enter a number: ";
      cin >> num;
      int result = pow(num, 3);
      unsigned int cuberoot = cbrt(result);
      if(result > 0 && cuberoot==num){
      cout << "The cube of " << num << " is " << result;
      }
      else{
      cout << "Error! The cube of " << num << "is not " << result;
      }
}
