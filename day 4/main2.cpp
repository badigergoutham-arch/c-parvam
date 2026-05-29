//taking input of 10 to 15 numbers and then calculate the smallest , 
//biggest number , 
//then find the middle number , 
//find the middle number , 
//find how many times a number is repeated and which numbers are repeated 
#include <iostream>
using namespace std;

int main() {
    int size;

    // 1. Ask the user how many numbers they want to enter
    cout << "How many numbers do you want to enter? (Choose between 10 and 15): ";
    cin >> size;

    if (size < 10 || size > 15) {
        cout << "Error: Please restart the program and enter a size between 10 and 15." << endl;
        return 0; 
    }

    // THIS IS THE ARRAY: We create a list that can hold up to 15 integers
    int numbers[15]; 

    // 2. Collect the numbers and STORE them in the array
    cout << "\nPlease enter your " << size << " numbers:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> numbers[i]; // Storing the input into the array at position 'i'
    }

    // --- NEW: Prove the array stored your numbers! ---
    cout << "\nAwesome! Here is the array you just built in memory: [ ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " "; // Print each item in the array
    }
    cout << "]\n" << endl;
    // -------------------------------------------------

    // 3. Sort the array from smallest to biggest
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                int temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    cout << "===============================" << endl;
    cout << "       ANALYSIS RESULTS        " << endl;
    cout << "===============================\n" << endl;

    // --- A. Smallest and Biggest Number ---
    cout << "1. Extremes:" << endl;
    cout << "   Smallest number: " << numbers[0] << endl;
    cout << "   Biggest number: " << numbers[size - 1] << endl;

    // --- B. Middle Number (Median) ---
    cout << "\n2. Middle number:" << endl;
    if (size % 2 != 0) {
        cout << "   " << numbers[size / 2] << endl;
    } else {
        double mid1 = numbers[(size / 2) - 1];
        double mid2 = numbers[size / 2];
        cout << "   " << (mid1 + mid2) / 2.0 << " (Average of the two middle numbers)" << endl;
    }

    // --- C. Repeated Numbers and Frequency ---
    cout << "\n3. Repeated numbers:" << endl;
    int count = 1;
    bool hasRepeats = false; 

    for (int i = 1; i < size; i++) {
        if (numbers[i] == numbers[i - 1]) {
            count++;
        } else {
            if (count > 1) {
                cout << "   -> The number " << numbers[i - 1] << " is repeated " << count << " times." << endl;
                hasRepeats = true;
            }
            count = 1; 
        }
    }
    
    if (count > 1) {
        cout << "   -> The number " << numbers[size - 1] << " is repeated " << count << " times." << endl;
        hasRepeats = true;
    }

    if (!hasRepeats) {
        cout << "   -> No numbers were repeated." << endl;
    }

    cout << "\n===============================" << endl;

    return 0;
}