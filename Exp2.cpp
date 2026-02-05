#include <iostream>
using namespace std;
int main() {
    int a[2][2], b[2][2];
    int choice;
    cout << "Enter elements of first 2x2 matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a[i][j];
        }
    }
    cout << "Enter elements of second 2x2 matrix:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> b[i][j];
        }
    }
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display matrices\n";
        cout << "2. Sum of matrices\n";
        cout << "3. Subtraction of matrices\n";
        cout << "4. Multiplication of matrices\n";
        cout << "5. Transpose of first matrix\n";
        cout << "6. Check identity matrix (first matrix)\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "\nFirst Matrix:\n";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
                cout << "\nSecond Matrix:\n";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << b[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            case 2:
                cout << "\nSum of matrices:\n";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << a[i][j] + b[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            case 3:
                cout << "\nSubtraction (A - B):\n";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << a[i][j] - b[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            case 4: {
                cout << "\nMultiplication:\n";
                int C[2][2] = {0};

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        for (int k = 0; k < 2; k++) {
                            c[i][j] += a[i][k] * b[k][j];
                        }
                        cout << a[i][j] << " ";
                    }
                    cout << endl;
                }
                break;
            }
            case 5:
                cout << "\nTranspose of First Matrix:\n";
                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        cout << a[j][i] << " ";
                    }
                    cout << endl;
                }
                break;
            case 6: {
                bool identity = true;

                for (int i = 0; i < 2; i++) {
                    for (int j = 0; j < 2; j++) {
                        if ((i == j && a[i][j] != 1) || (i != j && a[i][j] != 0)) {
                            identity = false;
                        }
                    }
                }
                if (identity)
                    cout << "First matrix is an Identity Matrix\n";
                else
                    cout << "First matrix is NOT an Identity Matrix\n";
                break;
            }
            case 7:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}