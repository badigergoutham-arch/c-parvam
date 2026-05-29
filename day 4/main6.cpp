//1.Constructors and destructors


//Constructors :
//Three types of constructors: ( default, parameterized, copy )

//defualt constructor :
#include <iostream>
using namespace std;
class defualt {
    public:
        defualt() {
            cout << "Default constructor called!" << endl;
        }
};
int main ()
{
    defualt obj1; // This will call the default constructor
    return 0;
}
