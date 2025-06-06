#include <iostream>
using namespace std;

int main() {
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Removing duplicates
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ) {
            if (arr[i] == arr[j]) {
                // Shift elements left to remove duplicate
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--; // reduce array size
            } else {
                j++;
            }
        }
    }

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
