//
// Created by Yusuf Surmen on 15/10/2025.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main() {
    int rows = 4;
    int cols = 3;

    // Use a vector for safe memory management instead of raw new[]
    vector<float> matrix(rows * cols);

    int counter = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // row-major indexing: element (i,j) is at i*cols + j
            matrix[i * cols + j] = static_cast<float>(counter);
            counter++;
        }
    }

    // Example: value at row=2, col=1
    float position = matrix[2 * cols + 1];

    cout << "Position val is " << position << endl;
    cout << "Matrix [0][0] " << matrix[0 * cols + 0] << endl;
    // Matrix[2][2] is valid because cols == 3 (indices 0..2)
    cout << "Matrix [2][3] " << matrix[2 * cols + 3] << endl;
}