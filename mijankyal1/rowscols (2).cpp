#include <iostream>
using namespace std;

const int MAX_ROWS = 10;
const int MAX_COLS = 10;

int main() {
    int mat[MAX_ROWS][MAX_COLS];
    int rows, cols;

    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0 || rows > MAX_ROWS || cols > MAX_COLS) {
        cout << "Invalid input for matrix size." << endl;
        return 1;
    }

    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Matrix with rows and columns swapped:" << endl;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}