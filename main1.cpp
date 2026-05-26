#include <iostream>
#include <string>
class Car {
public:
    std ::string brand;
    std ::string color;
    int year;
    
    void startEngine() {
        std ::cout << "The" << color << "  " << brand << " 's engine is now running!" << std::endl;
    }
};
int main() {
    Car myCar;
    myCar.brand = " Toyota";
    myCar.color = " Red";
    myCar.year = 2026;

    Car friendsCar;
    friendsCar.brand = " Honda";
    friendsCar.color = " Blue";
    friendsCar.year = 2025;

    myCar.startEngine();
    friendsCar.startEngine();

    return 0;
}