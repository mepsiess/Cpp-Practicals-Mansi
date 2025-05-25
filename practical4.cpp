#include <iostream>
using namespace std;

void showAddress(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        cout << "Character: " << str[i] << " | Address: " << (void*)&str[i] << endl;
    }
}

void concatenate(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0') i++; // go to end of str1
    int j = 0;
    while (str2[j] != '\0') {
        str1[i++] = str2[j++];
    }
    str1[i] = '\0';
    cout << "Concatenated string: " << str1 << endl;
}

void compare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            cout << "Strings are not equal." << endl;
            return;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0')
        cout << "Strings are equal." << endl;
    else
        cout << "Strings are not equal." << endl;
}

void lengthWithPointers(char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    cout << "Length of the string: " << length << endl;
}

void toUppercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }
    cout << "Uppercase string: " << str << endl;
}

void reverseString(char str[]) {
    int len = 0;
    while (str[len] != '\0') len++;
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}

int main() {
    char str1[100], str2[100];
    int choice;

    cout << "Enter string 1: ";
    cin.getline(str1, 100);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Show address of each character\n";
        cout << "2. Concatenate with another string\n";
        cout << "3. Compare with another string\n";
        cout << "4. Length of the string (using pointers)\n";
        cout << "5. Convert to uppercase\n";
        cout << "6. Reverse the string\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from buffer

        switch (choice) {
            case 1:
                showAddress(str1);
                break;
            case 2:
                cout << "Enter string 2: ";
                cin.getline(str2, 100);
                concatenate(str1, str2);
                break;
            case 3:
                cout << "Enter string 2: ";
                cin.getline(str2, 100);
                compare(str1, str2);
                break;
            case 4:
                lengthWithPointers(str1);
                break;
            case 5:
                toUppercase(str1);
                break;
            case 6:
                reverseString(str1);
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
