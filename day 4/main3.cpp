#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

// ==========================================
// OVERLOAD 1: For Arrays of Numbers
// ==========================================
void analyze(vector<int> nums) {
    if (nums.empty()) {
        cout << "The number array is empty!" << endl;
        return;
    }

    // 1. Find Smallest and Biggest
    int smallest = *min_element(nums.begin(), nums.end());
    int biggest = *max_element(nums.begin(), nums.end());

    // 2. Find Middle Number (Median)
    sort(nums.begin(), nums.end());
    double middle;
    int size = nums.size();
    
    if (size % 2 == 0) {
        middle = (nums[size / 2 - 1] + nums[size / 2]) / 2.0;
    } else {
        middle = nums[size / 2];
    }

    // Print results
    cout << "--- Number Analysis ---" << endl;
    cout << "Smallest number : " << smallest << endl;
    cout << "Biggest number  : " << biggest << endl;
    cout << "Middle number   : " << middle << endl << endl;
}

// ==========================================
// OVERLOAD 2: For Arrays of Words (Strings)
// ==========================================
void analyze(const vector<string>& words) {
    if (words.empty()) {
        cout << "The word array is empty!" << endl;
        return;
    }

    // 1. Count frequencies using a Hash Map
    unordered_map<string, int> wordCounts;
    for (const string& word : words) {
        wordCounts[word]++;
    }

    // 2. Find the most frequent word
    string mostFrequentWord = "";
    int maxRepetitions = 0;

    for (const auto& pair : wordCounts) {
        if (pair.second > maxRepetitions) {
            mostFrequentWord = pair.first;
            maxRepetitions = pair.second;
        }
    }

    // Print results
    cout << "--- Word Analysis ---" << endl;
    cout << "Most frequent word: '" << mostFrequentWord << "'" << endl;
    cout << "Times repeated    : " << maxRepetitions << endl << endl;
}

// ==========================================
// MAIN FUNCTION (Updated for User Input)
// ==========================================
int main() {
    int numCount;
    vector<int> myNumbers;
    
    // --- 1. Gather Number Input ---
    cout << "How many numbers do you want to enter? ";
    cin >> numCount;
    
    if (numCount > 0) {
        cout << "Enter " << numCount << " numbers (separated by spaces): ";
        for (int i = 0; i < numCount; i++) {
            int currentNum;
            cin >> currentNum;
            myNumbers.push_back(currentNum); // Add user input to the vector
        }
    }

    int wordCount;
    vector<string> myWords;
    
    // --- 2. Gather Word Input ---
    cout << "\nHow many words do you want to enter? ";
    cin >> wordCount;
    
    if (wordCount > 0) {
        cout << "Enter " << wordCount << " words (separated by spaces): ";
        for (int i = 0; i < wordCount; i++) {
            string currentWord;
            cin >> currentWord;
            myWords.push_back(currentWord); // Add user input to the vector
        }
    }

    cout << "\n===============================\n";
    cout << "          RESULTS\n";
    cout << "===============================\n\n";

    // --- 3. Call Overloaded Functions ---
    analyze(myNumbers); 
    analyze(myWords);   
    return 0;
}