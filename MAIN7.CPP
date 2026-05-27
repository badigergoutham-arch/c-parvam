#include <iostream>
#include <string>

// 1. Basic Function Declaration (Prototype)
void greetUser(std::string name);

// 2. Function with return type and default parameter
double calculateArea(double length, double width = 5.0);

// 3. Function overloading (same name, different parameters)
int add(int a, int b);
double add(double a, double b);

// 4. Pass-by-value vs Pass-by-reference
void incrementByValue(int x);     // Local copy is modified
void incrementByReference(int &a); // Original variable is modified

int main() {
    // 1. Basic Function
    greetUser("Alice");

    // 2. Default Parameters
    std::cout << "Area (length 10, default width 5): " << calculateArea(10.0) << std::endl;
    std::cout << "Area (length 10, width 10): " << calculateArea(10.0, 10.0) << std::endl;

    // 3. Function Overloading
    std::cout << "Int add: " << add(5, 10) << std::endl;
    std::cout << "Double add: " << add(5.5, 10.5) << std::endl;

    // 4. Pass-by-value vs Reference
    int num = 10;
    
    incrementByValue(num);
    std::cout << "After incrementByValue: " << num << " (No change)" << std::endl;

    incrementByReference(num);
    std::cout << "After incrementByReference: " << num << " (Value changed)" << std::endl;

    return 0;
}

// --- Function Definitions ---

void greetUser(std::string name) {
    std::cout << "Hello, " << name << "!" << std::endl;
}

double calculateArea(double length, double width) {
    return length * width;
}

int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

void incrementByValue(int x) {
    x++; // Only changes the local copy
}

void incrementByReference(int &a) {
    a++; // Changes the actual variable in main
}
