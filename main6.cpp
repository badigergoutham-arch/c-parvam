#include <iostream>
#include <string>

using namespace std;

// Function 1: A void function that takes a name and prints a greeting
void greetCustomer(string name) {
    cout << "Hello, " << name << "! Welcome to our restaurant.\n";
}

// Function 2: A void function that just prints the menu to the screen
void showMenu() {
    cout << "\n--- Today's Menu ---\n";
    cout << "1. ROTTI PALYA - rs 200\n";
    cout << "2. CHAPATI PALYA  - rs 200\n";
    cout << "--------------------\n";
}

// Function 3: A function that does math and RETURNS an integer result
int calculateTotal(int price, int quantity) {
    int total = price * quantity;
    return total; 
}

int main() {
    greetCustomer("Alex");
    showMenu();
    int itemPrice = 5; // Price of a burger
    int amountOrdered = 3; 

    // 4. Call the math function and store the result in a new variable
    int finalBill = calculateTotal(itemPrice, amountOrdered);

    // Print the final result
    cout << "\nYou ordered " << amountOrdered << " Burgers.\n";
    cout << "Your total bill is: $" << finalBill << "\n";

    return 0;
}