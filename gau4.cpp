#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2;

    // 1. Display the menu choices to the user
    cout << "--- Calculator Menu ---" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    
    // 2. Ask the user to enter their choice
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // 3. Ask for the numbers they want to calculate
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // 4. Figure out what to do based on their choice
    if (choice == 1) {
        cout << "The answer is: " << num1 + num2;
    } 
    else if (choice == 2) {
        cout << "The answer is: " << num1 - num2;
    } 
    else if (choice == 3) {
        cout << "The answer is: " << num1 * num2;
    } 
    else if (choice == 4) {
        // Checking for division by zero
        if (num2 != 0) {
            cout << "The answer is: " << num1 / num2;
        } else {
            cout << "Error! You cannot divide by zero.";
        }
    } 
    else {
        // If they type a number like 5 or 99
        cout << "Invalid choice! Please run the program again and select 1, 2, 3, or 4.";
    }

    return 0;
}