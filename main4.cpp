#include <iostream>
#include <string>

class Menu {
public:
    std::string item;
    int price;

    void display() {
        std::cout << item << " costs *rs" << price << "/-." << std::endl;
    }
};
int main()
{
    Menu price1;
    price1.item = " 1. IDILI";
    price1.price = 50;

    Menu price2;
    price2.item = " 2. DOSA";
    price2.price = 70;

    Menu price3;
    price3.item = " 3.VADA";
    price3.price = 40;
    

    price1.display();
    price2.display();
    price3.display();

    return 0;
}