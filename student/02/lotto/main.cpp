#include <iostream>

using namespace std;
unsigned long int factorial(unsigned long int n);
unsigned long int combinations(unsigned long int l, unsigned long d);

int main()
{
   unsigned long int lottery_balls=0;
   unsigned long int drawn_balls=0;

   cout << "Enter the total number of lottery balls: ";
   cin >> lottery_balls;
   cout << "Enter the number of drawn balls: ";
   cin >> drawn_balls;

   if(lottery_balls >=0 && drawn_balls >=0){
       if(drawn_balls > lottery_balls){
                  cout << "The maximum number of drawn balls is the total amount of balls.";
              }
              else{
                  unsigned long int result= 1/combinations(lottery_balls,drawn_balls);

                  cout <<"The probability of guessing all " << drawn_balls <<" balls correctly is " << result;
              }
   }
   else{
        cout << "The number of balls must be a positive number.";
   }

}

unsigned long int factorial(unsigned long int n){
    int fact =1;
    for(unsigned long int i=1; i<=n; i++){
        fact = fact*i;
    }
    return fact;
}

unsigned long int combinations(unsigned long int l, unsigned long d){
    unsigned long int r = l-d;
    unsigned long int a = factorial(l);
    unsigned long int b = factorial(r) * factorial(d);
    return a/b;
}
