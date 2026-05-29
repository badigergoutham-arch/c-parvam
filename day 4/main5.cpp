// create a class of AIML 2ndsem 
// display name , friends name
#include <iostream>
#include <streambuf>

using namespace std;

class cityengincollege {
    public:
        string name;
        string friendsname;
        string course;
        string friendscourse;
        string year;
        string friendsyear;
        string section;
        string friendssection;

        void display() {
            cout << "My name is " << name << " and my friend's name is " << friendsname << "." << endl;
            cout << "I am perseuing " << course << " and my friend is persuing " << friendscourse << "." << endl;
            cout << "I am in year " << year << " and my friend is in year " << friendsyear << "." << endl;
            cout << "I am in section " << section << " and my friend is in section " << friendssection << "." << endl;
        }
};
int main()
{
    cityengincollege student1;
    student1.name = "Alice";
    student1.friendsname = "Bob";
    student1.course = "Computer Science";
    student1.friendscourse = "Information Technology";
    student1.year = "2nd Year";
    student1.friendsyear = "2nd Year";
    student1.section = "A";
    student1.friendssection = "B";
    student1.display();

    cityengincollege student2;
    student2.name = "Charlie";
    student2.friendsname = "David";
    student2.course = "Mechanical Engineering";
    student2.friendscourse = "Electrical Engineering";
    student2.year = "3rd Year";
    student2.friendsyear = "3rd Year";
    student2.section = "C";
    student2.friendssection = "D";
    student2.display();
    return 0;
}