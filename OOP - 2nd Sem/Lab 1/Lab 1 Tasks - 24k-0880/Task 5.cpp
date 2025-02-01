#include <iostream>
using namespace std;

int sumBorder(int matrix[3][3], int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                sum += matrix[i][j];
            }
        }
    }
    return sum;
}

int main() {
    int matrix[3][3] = {{1, 2, 3}, 
						{4, 5, 6}, 
						{7, 8, 9}};
    int rows = 3, cols = 3;

    cout << sumBorder(matrix, rows, cols);

    return 0;
}
