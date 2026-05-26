#include <iostream>
#include <string>

using namespace std;

// Defining the single greet function
void greet(string name) {
    cout << "Hello, " << name << "! Have a great day!\n";
}

int main() {
    // Calling the function with different names
    greet("Alice");
    greet("Bob");
    greet("Charlie");

    return 0;
}