#include <iostream>
#include <string>
#include <map>
#include <cctype> // for isalpha and tolower
using namespace std;

void countOccurrences(string str) {
    map<char, int> freq;

    for (char c : str) {
        if (isalpha(c)) { // Consider only alphabets
            freq[tolower(c)]++;
        }
    }

    cout << "Character Frequency Table:\n";
    cout << "Letter\tCount\n";
    for (auto pair : freq) {
        cout << pair.first << "\t" << pair.second << endl;
    }
}

int main(int argc, char* argv[]) {
    string input = "";

    // Combine all command line arguments into one string
    for (int i = 1; i < argc; ++i) {
        input += argv[i];
        input += " "; // Add space between words
    }

    countOccurrences(input);
    return 0;
}
