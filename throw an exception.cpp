#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    int p, q;
    cout << "Enter two numbers (p and q): ";
    cin >> p >> q;

    try {
        if (q == 0)
            throw runtime_error("Division by zero!");
        cout << "Result: " << p / q << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
