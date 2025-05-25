#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// (i) Recursive Binary Search
int binarySearchRecursive(const vector<int>& arr, int left, int right, int key) {
    if (left > right)
        return -1; // Not found

    int mid = left + (right - left) / 2;

    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearchRecursive(arr, left, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, right, key);
}

// (ii) Iterative Binary Search
int binarySearchIterative(const vector<int>& arr, int key) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1; // Not found
}

int main() {
    int n, key;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " sorted elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    // Recursive
    int resultRecursive = binarySearchRecursive(arr, 0, n - 1, key);
    if (resultRecursive != -1)
        cout << "Recursive: Element found at index " << resultRecursive << endl;
    else
        cout << "Recursive: Element not found.\n";

    // Iterative
    int resultIterative = binarySearchIterative(arr, key);
    if (resultIterative != -1)
        cout << "Iterative: Element found at index " << resultIterative << endl;
    else
        cout << "Iterative: Element not found.\n";

    return 0;
}
