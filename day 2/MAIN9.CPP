#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

class Restaurant {
// Public access specifier: Accessible from outside the class
public:
    // Structure for a Menu Item
    struct MenuItem {
        int id;
        std::string name;
        double price;
    };

    // The menu is public and visible to everyone
    std::vector<MenuItem> menu = {
        {1, "Burger", 5.99},
        {2, "Pizza", 8.99},
        {3, "Fries", 2.49},
        {4, "Soda", 1.99}
    };

    // Public method to display the menu
    void displayMenu() const {
        std::cout << "\n========== RESTAURANT MENU ==========\n";
        std::cout << std::left << std::setw(5) << "ID" << std::setw(15) << "Item" << "Price\n";
        std::cout << "-------------------------------------\n";
        for (const auto& item : menu) {
            std::cout << std::left << std::setw(5) << item.id 
                      << std::setw(15) << item.name 
                      << "$" << item.price << "\n";
        }
        std::cout << "=====================================\n";
    }

    // Public method to interact with the private order system
    void addItemToOrder(int itemId) {
        for (const auto& item : menu) {
            if (item.id == itemId) {
                orderedItems.push_back(item);
                calculateBill(item.price); // Internally updates the private bill
                std::cout << item.name << " added to your order.\n";
                return;
            }
        }
        std::cout << "Invalid Item ID! Please try again.\n";
    }

    // Public method allowing the user to view their private bill
    void viewBill() const {
        if (orderedItems.empty()) {
            std::cout << "\nYour order is empty.\n";
            return;
        }

        std::cout << "\n========== YOUR RECEIPT ==========\n";
        for (const auto& item : orderedItems) {
            std::cout << std::left << std::setw(15) << item.name << "$" << item.price << "\n";
        }
        std::cout << "----------------------------------\n";
        std::cout << std::left << std::setw(15) << "Total Bill:" << "$" << totalBill << "\n";
        std::cout << "==================================\n";
    }

// Private access specifier: Hidden from direct outside access
private:
    std::vector<MenuItem> orderedItems; // Private order list
    double totalBill = 0.0;             // Private bill amount

    // Private method: Only the class itself can update the bill
    void calculateBill(double amount) {
        totalBill += amount;
    }
};

int main() {
    Restaurant myRestaurant;
    int choice;
    int itemId;

    std::cout << "Welcome to the Encapsulated Bistro!\n";

    do {
        std::cout << "\n1. View Menu (Public)\n";
        std::cout << "2. Add Item to Order\n";
        std::cout << "3. View My Bill (Private Data)\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                // Anyone can view the public menu
                myRestaurant.displayMenu();
                break;
            case 2:
                myRestaurant.displayMenu();
                std::cout << "Enter the Item ID you want to order: ";
                std::cin >> itemId;
                myRestaurant.addItemToOrder(itemId);
                break;
            case 3:
                // Securely fetches data through the public method
                myRestaurant.viewBill();
                break;
            case 4:
                std::cout << "Thank you for visiting! Goodbye.\n";
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}