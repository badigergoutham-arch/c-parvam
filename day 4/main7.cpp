//Parameterized constructor :

#include <iostream>
using namespace std;
class parameterized
{
    parameterized(int x)
    {
        cout << "Parameterized constructor called with value: " << x << endl;
    }
};
int main ()
{
    parameterized obj2(5); // This will call the parameterized constructor
    return 0;
}
