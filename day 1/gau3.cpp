#include <iostream>
using namespace std;

int main() {
    // 1. Create boxes for our numbers and our math symbol
    double num1, num2;
    char mathSymbol;

    // 2. Ask the user to fill those boxes
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter a math symbol (+, -, *, /): ";
    cin >> mathSymbol;

    cout << "Enter the second number: ";
    cin >> num2;

    // 3. Ask simple Yes/No questions to decide what math to do
    if (mathSymbol == '+') {
        cout << "The answer is: " << num1 + num2;
    } 
    else if (mathSymbol == '-') {
        cout << "The answer is: " << num1 - num2;
    } 
    else if (mathSymbol == '*') {
        cout << "The answer is: " << num1 * num2;
    } 
    else if (mathSymbol == '/') {
        cout << "The answer is: " << num1 / num2;
    } 
    else {
        // If they typed a letter or a weird symbol, tell them!
        cout << "I don't recognize that symbol!";
    }

    return 0;
}