// create an array of 10 to 15 numbers, sort it, and analyze it (smallest, biggest, middle)
#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int size;
    cout << "How many numbers do you want to enter? (Choose between 10 and 15): ";
    cin >> size;
    if (size >= 10 && size <=15)
    {
        vector<int> nums(size);
        cout << "Please enter your " << size << " numbers:" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Number " << (i + 1) << ": ";
            cin >> nums[i];
        }

        // Sort the numbers from smallest to biggest
        sort(nums.begin (), nums.end());
        // Find the smallest and biggest numbers
        int smallest = nums[0];
        int biggest = nums[size - 1];
        // Find the middle number
        int middle;
        if (size % 2 == 0)
        {
            middle = (nums[size / 2 - 1] + nums[size / 2]) / 2;
        }
        else
        {
            middle = nums[size / 2];
        }
        // Display the results
        cout << "Smallest number: " << smallest << endl;
        cout << "Biggest number: " << biggest << endl;
        cout << "Middle number: " << middle << endl;
    }
    else
    {
        cout << "Invalid input. Please enter a number between 10 and 15." << endl;
    }
    return 0;
}