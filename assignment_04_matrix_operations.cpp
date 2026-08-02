// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
// Name: [Mark Junior Techie-Burns]
// Student ID: [22492537]
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
void transposeMatrix(int matrix[10][10], int rows, int cols) {
    cout << "Transposed Matrix:" << endl;
    for (int j = 0; j < cols; ++j) {
        for (int i = 0; i < rows; ++i) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}
void addMatrices(int matrixA[10][10], int matrixB[10][10], int rows, int cols) {
    cout << "Sum of Matrices:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << setw(5) << (matrixA[i][j] + matrixB[i][j]);
        }
        cout << endl;
    }
}
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int rowsA, int colsA, int colsB) {
    cout << "Product of Matrices:" << endl;
    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            int sum = 0;
            for (int k = 0; k < colsA; ++k) {
                sum += matrixA[i][k] * matrixB[k][j];
            }
            cout << setw(5) << sum;
        }
        cout << endl;
    }
}
int main() {
    int choice;
    cout << "Matrix Operations Menu:" << endl;
    cout << "1. Transpose Matrix" << endl;
    cout << "2. Add Matrices" << endl;
    cout << "3. Multiply Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1) {
        int matrix[10][10], rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrix[i][j];
            }
        }
        transposeMatrix(matrix, rows, cols);
    } else if (choice == 2) {
        int matrixA[10][10], matrixB[10][10], rows, cols;
        cout << "Enter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;
        cout << "Enter elements for Matrix A:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrixA[i][j];
            }
        }
        cout << "Enter elements for Matrix B:" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrixB[i][j];
            }
        }
        addMatrices(matrixA, matrixB, rows, cols);
    } else if (choice == 3) {
        int matrixA[10][10], matrixB[10][10], rowsA, colsA, colsB;
        cout << "Enter number of rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter number of columns for Matrix A: ";
        cin >> colsA;
        cout << "Enter elements for Matrix A:" << endl;
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsA; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrixA[i][j];
            }
        }
        cout << "Enter number of columns for Matrix B: ";
        cin >> colsB;
        cout << "Enter elements for Matrix B:" << endl;
        for (int i = 0; i < colsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                cout << "Enter element [" << i << "][" << j << "]: ";
                cin >> matrixB[i][j];
            }
        }
        multiplyMatrices(matrixA, matrixB, rowsA, colsA, colsB);
    }
    return 0;
}