#include <iostream>
#include <string>
class Family {
public:
    std ::string member;
    std ::string name;
    int age;
    
    void intro()
    {
        std ::cout << "The" << member << "  " << name << "  " << age << std::endl;
    }
};
int main()
{
    Family Father;
    Father.member = " ABC";
    Father.name = " CBA";
    Father.age = 1989;

    Family Mother;
    Mother.member = " XYZ";
    Mother.name = " ZYX";
    Mother.age = 1992;
    Father.intro();
    Mother.intro();

    return 0;
}