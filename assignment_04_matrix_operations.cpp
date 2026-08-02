// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
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

// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
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
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function.
// - Display each matrix in a neat, aligned grid using setw().
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Function to read a matrix
void readMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int matrix[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A - Transpose Matrix
void transposeMatrix(int matrix[10][10], int transpose[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// PART B - Add Two Matrices
void addMatrices(int matrix1[10][10], int matrix2[10][10], int sum[10][10], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            sum[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// PART C - Multiply Two Matrices
void multiplyMatrices(int matrixA[10][10], int matrixB[10][10], int product[10][10],
                      int rowsA, int colsA, int colsB)
{
    for (int i = 0; i < rowsA; i++)
    {
        for (int j = 0; j < colsB; j++)
        {
            product[i][j] = 0;

            for (int k = 0; k < colsA; k++)
            {
                product[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main()
{
    int matrix1[10][10], matrix2[10][10];
    int transpose[10][10], sum[10][10], product[10][10];

    // ============================
    // PART A - Transpose Matrix
    // ============================
    int rows, cols;

    cout << "PART A - Transpose Matrix" << endl;
    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "Enter the matrix elements:" << endl;
    readMatrix(matrix1, rows, cols);

    transposeMatrix(matrix1, transpose, rows, cols);

    cout << endl << "Original Matrix:" << endl;
    displayMatrix(matrix1, rows, cols);

    cout << endl << "Transposed Matrix:" << endl;
    displayMatrix(transpose, cols, rows);

    // ============================
    // PART B - Add Two Matrices
    // ============================
    cout << endl << "PART B - Add Two Matrices" << endl;

    cout << "Enter the first matrix:" << endl;
    readMatrix(matrix1, rows, cols);

    cout << "Enter the second matrix:" << endl;
    readMatrix(matrix2, rows, cols);

    addMatrices(matrix1, matrix2, sum, rows, cols);

    cout << endl << "Sum of the matrices:" << endl;
    displayMatrix(sum, rows, cols);

    // ============================
    // PART C - Multiply Two Matrices
    // ============================
    int rowsA, colsA, rowsB, colsB;

    cout << endl << "PART C - Multiply Two Matrices" << endl;

    cout << "Enter rows of Matrix A: ";
    cin >> rowsA;

    cout << "Enter columns of Matrix A: ";
    cin >> colsA;

    cout << "Enter rows of Matrix B: ";
    cin >> rowsB;

    cout << "Enter columns of Matrix B: ";
    cin >> colsB;

    if (colsA != rowsB)
    {
        cout << "Matrix multiplication is not possible." << endl;
        return 0;
    }

    cout << "Enter Matrix A:" << endl;
    readMatrix(matrix1, rowsA, colsA);

    cout << "Enter Matrix B:" << endl;
    readMatrix(matrix2, rowsB, colsB);

    multiplyMatrices(matrix1, matrix2, product, rowsA, colsA, colsB);;

    cout << endl << "Product of Matrix A and Matrix B:" << endl;
    displayMatrix(product, rowsA, colsB);

    return 0;
}