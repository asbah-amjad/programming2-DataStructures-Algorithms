#include <iostream>
using namespace std;
// Write here a function counting the mean value

int main()
{
    int num = 0;
    double sum = 0;
    cout << "From how many integer numbers you want to count the mean value? ";
    cin >> num;
    if(num <= 0){
        cout << "Cannot count mean value from x numbers";
    }
    else{
    for(int i=1; i<=num; i++){
        double x=0;
        cout << "Input " << i << ". number: ";
        cin >> x;
        sum += x;
    }
    double mean = sum / num;
    cout << "Mean value of the given numbers is " << mean;
    }
}
