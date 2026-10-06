
#include <iostream>
#include <new>

using namespace std;

int main() {
    int rows, cols;

    if (!(cin >> rows >> cols) || rows <= 0 || cols <= 0) {
        return 1;
    }

    // Выделение памяти под строки матрицы
    int** matrix = new (nothrow) int*[rows];

    if (matrix == nullptr) {
        return 2;
    }

    int allocated = 0;

    for (int i = 0; i < rows; i++) {
        matrix[i] = new (nothrow) int[cols];

        if (matrix[i] == nullptr) {
            for (int j = 0; j < allocated; j++) {
                delete[] matrix[j];
            }
            delete[] matrix;
            return 2;
        }

        allocated++;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(cin >> matrix[i][j])) {
                for (int k = 0; k < rows; k++) {
                    delete[] matrix[k];
                }
                delete[] matrix;
                return 1;
            }
        }
    }

    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            cout << matrix[i][j];

            if (i < rows - 1) {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
