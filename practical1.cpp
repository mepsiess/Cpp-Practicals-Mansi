# Sum of the first n terms

#include <iostream>
#include <cmath>  // for pow()
#include <cstdlib> // for atoi()
using namespace std;

int main(int argc, char* argv[]) {
    int n;

    // If user passed n as command line argument
    if (argc > 1) {
        n = atoi(argv[1]); // convert argument to int
    } else {
        // Prompt user to enter n
        cout << "Enter the number of terms (n): ";
        cin >> n;
    }

    double sum = 0.0;

    for (int i = 1; i <= n; i++) {
        sum += 1.0 / pow(i, i); // i^i
    }

    cout << "Sum of the series is: " << sum << endl;

    return 0;
}
