#include <iostream>
#include <string>

using namespace std;

class BankAccount {
// 1. PRIVATE: This data is hidden from the outside world.
private: 
    string accountHolder;
    double balance;
// 2. PUBLIC: These methods form the "interface" to interact with the hidden data safely.
public: 
    // Constructor: Sets up the account when it is first created
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        // Safety check during creation
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Error: Initial balance cannot be negative. Setting balance to $0.\n";
        }
    }
    // Method to deposit money securely
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: $" << amount << "\n";
        } else {
            cout << "Error: Deposit amount must be greater than zero.\n";
        }
    }
    // Method to withdraw money securely
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Withdrawal amount must be greater than zero.\n";
        } else if (amount > balance) {
            cout << "Error: Insufficient funds. You only have $" << balance << ".\n";
        } else {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << "\n";
        }
    }
    // "Getter" method: Allows the outside world to view the balance without changing it
    double getBalance() {
        return balance;
    }
    // "Getter" method: Allows the outside world to view the account holder's name
    string getAccountHolder() {
        return accountHolder;
    }
};
int main() {
    // 1. Ask the user for their name to create the account
    string name;
    cout << "Enter your name to open an account: ";
    getline(cin, name); // Using getline in case the name has spaces

    // Create the account with a starting balance of $100.00
    BankAccount myAccount(name, 100.00);
    
    cout << "\n=================================\n";
    cout << "Welcome, " << myAccount.getAccountHolder() << "!\n";
    cout << "Starting Balance: $" << myAccount.getBalance() << "\n";
    cout << "=================================\n";

    // 2. Get user input for a Deposit
    double depositAmount;
    cout << "\nEnter amount to deposit: $";
    cin >> depositAmount; 
    
    // Pass the user's input into the encapsulated method
    myAccount.deposit(depositAmount); 
    cout << "Current Balance: $" << myAccount.getBalance() << "\n";

    // 3. Get user input for a Withdrawal
    double withdrawAmount;
    cout << "\nEnter amount to withdraw: $";
    cin >> withdrawAmount;
    
    // Pass the user's input into the encapsulated method
    myAccount.withdraw(withdrawAmount);

    // 4. Show final balance
    cout << "\n=================================\n";
    cout << "Final Balance for " << myAccount.getAccountHolder() << ": $" << myAccount.getBalance() << "\n";
    cout << "Thank you for banking with us!\n";
    cout << "=================================\n";

    return 0;
}