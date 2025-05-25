#include <iostream>
#include <cctype> // for isalpha, tolower
using namespace std;

int main(int argc, char* argv[]) {
    int count[26] = {0};

    // Loop over each argument starting from index 1 (index 0 is program name)
    for (int i = 1; i < argc; i++) {
        char* p = argv[i];
        while (*p) {
            if (isalpha(*p)) {
                char ch = tolower(*p);
                count[ch - 'a']++;
            }
            p++;
        }
    }

    // Print the table
    cout << "Alphabet\tCount\n";
    for (int i = 0; i < 26; i++) {
        if (count[i] > 0)
            cout << char('a' + i) << "\t\t" << count[i] << endl;
    }

    return 0;
}
