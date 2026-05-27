//flow control statements
// nested if statements
#include<iostream>
using namespace std;
int main()
{
    int age;
    cout << "Enter the age";
    cin >> age;
    if (age >18)
    {
        cout << "You are eligible for voting" << endl;
        if (age >= 21)
        {
            cout << "You are also eligible for driving";
        }
        else
        {
            cout << "You are not eligible for driving";
        }
    }
    else{
        cout << "You are not eligible for voting";
    }
    return 0;
}