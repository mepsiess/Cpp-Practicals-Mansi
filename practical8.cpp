#include <iostream>
using namespace std;

class Matrix {
    int mat[3][3];

public:
    void input() {
        cout << "Enter elements of matrix (seperated by space) (3x3):\n";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                cin >> mat[i][j];
    }

    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++)
                cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    Matrix operator+(Matrix m) {
        Matrix res;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                res.mat[i][j] = mat[i][j] + m.mat[i][j];
        return res;
    }

    Matrix operator*(Matrix m) {
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 3; k++)
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];
            }
        }
        return res;
    }

    Matrix transpose() {
        Matrix res;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                res.mat[i][j] = mat[j][i];
        return res;
    }
};

int main() {
    Matrix A, B, C;
    int choice;

    cout << "Input first matrix:\n";
    A.input();
    cout << "Input second matrix:\n";
    B.input();

    do {
        cout << "\nMenu:\n"
             << "1. Sum\n"
             << "2. Product\n"
             << "3. Transpose of first matrix\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                C = A + B;
                cout << "Sum of matrices:\n";
                C.display();
                break;
            case 2:
                C = A * B;
                cout << "Product of matrices:\n";
                C.display();
                break;
            case 3:
                C = A.transpose();
                cout << "Transpose of first matrix:\n";
                C.display();
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
