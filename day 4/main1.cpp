// calculator
#include <iostream>

using namespace std;

// Function to add two numbers
int add(int num1, int num2)
{
    return num1 + num2;
}

// Function to subtract two numbers
int subtract(int num1, int num2)
{
    return num1 - num2;
}

// Function to multiply two numbers
int multiply(int num1, int  num2)
{
    return num1 * num2;
}

// Function to divide two numbers
int divide(int num1, int num2)
{
    if (num2 != 0)
    {
        return num1 / num2;
    } else
    {
        cout << "Error: Division by zero is undefined." << endl;
        return 0; // Return 0 or you could choose to return a special value or throw an exception
    }
}

int main() {
    int number1, number2;
    int choice; // Changed from 'char' to 'int' for numbered choices

    // Get user input for the numbers
    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    // Display a numbered menu for the user
    cout << "\n--- Operation Menu ---" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    cout << "\n--- Result ---" << endl;

    // The switch statement now checks for numbers (1, 2, 3, 4) instead of symbols
    switch (choice) {
        case 1:
            cout << number1 << " + " << number2 << " = " << add(number1, number2) << endl;
            break;
        case 2:
            cout << number1 << " - " << number2 << " = " << subtract(number1, number2) << endl;
            break;
        case 3:
            cout << number1 << " * " << number2 << " = " << multiply(number1, number2) << endl;
            break;
        case 4:
            if (number2 != 0) {
                cout << number1 << " / " << number2 << " = " << divide(number1, number2) << endl;
            } else {
                divide(number1, number2); // This triggers your custom error message
            }
            break;
        default:
            // If the user types a number outside of 1-4
            cout << "Error: Invalid choice! Please run the program again and select 1, 2, 3, or 4." << endl;
            break;
    }

    return 0;
}