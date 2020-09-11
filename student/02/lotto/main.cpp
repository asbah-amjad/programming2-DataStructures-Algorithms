#include <iostream>

using namespace std;
long int factorial(long int n);
long int combinations(long int l, long d);

int main()
{
   long int lottery_balls=0;
   long int drawn_balls=0;

   cout << "Enter the total number of lottery balls: ";
   cin >> lottery_balls;
   cout << "Enter the number of drawn balls: ";
   cin >> drawn_balls;
//number of balls must be a positive number
   if(lottery_balls >=0 && drawn_balls >=0){
       if(drawn_balls > lottery_balls){
                  cout << "The maximum number of drawn balls is the total amount of balls.";
              }
              else{
                  long int result= combinations(lottery_balls,drawn_balls);

                  cout <<"The probability of guessing all " << drawn_balls <<" balls correctly is " << result;
              }
   }
   else{
        cout << "The number of balls must be a positive number.";
   }

}

long int factorial(long int n){
    int fact =1;
    if(n==0 or n==1){
        return fact;
    }
    else{
    for(long int i=1; i<=n; i++){
        fact = fact*i;
    }
    return fact;
    }
}

long int combinations(long int l, long d){
     long int r = l-d;
     long int a = factorial(l);
     long int b = factorial(r) * factorial(d);
    return a/b;
}
