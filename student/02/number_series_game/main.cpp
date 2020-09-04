#include <iostream>

using namespace std;
int main()
{
    int num = 0;
    cout << "How many numbers would you like to have? ";
    cin >> num;
    for(int i=1; i<=num; i++)
    {
        if(i%3==0)
        {
           cout << "zip" << endl;
        }
        else
        {
        cout << i << endl;
        }
    }
}
