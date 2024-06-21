//Matrix.c to do functions on matrix like reading and finding the determinant
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include"matrix.h"

//Function to read the matrix from the file
matrix* ReadMatrix(FILE* fp) {
    int rows, columns;

    // Read the dimensions from the file
    fscanf(fp, "%d %d", &rows, &columns);

    // Allocate a matrix structure
    matrix *m = (matrix *)malloc(sizeof(matrix));

    // Set dimensions
    m->rows = rows;
    m->cols = columns;

    // Allocate a double array of length rows * cols
    m->data = (double *)malloc((rows * columns) * sizeof(double));

    // Read matrix elements from the file
    int i;
    for (i = 0; i < rows * columns; i++) {
        fscanf(fp, "%lf", &(m->data[i]));
    }

    return m;//returns the matrix
}

// Function to get the minor of a matrix by excluding a specified row and column
matrix get_minor(matrix mat, int row, int col) {//passing the matrix and the rowws and columns as arguments
    matrix minor;
    minor.rows = mat.rows - 1;
    minor.cols = mat.cols - 1;
    minor.data = (double *)malloc(minor.rows * minor.cols * sizeof(double));

    int dest_row = 0;
    for (int src_row = 0; src_row < mat.rows; ++src_row) {
        if (src_row == row) {
            continue; // Skip the specified row
        }

        int dest_col = 0;
        for (int src_col = 0; src_col < mat.cols; ++src_col) {
            if (src_col == col) {
                continue; // Skip the specified column
            }

            minor.data[dest_row * minor.cols + dest_col] = mat.data[src_row * mat.cols + src_col];
            ++dest_col;
        }

        ++dest_row;
    }

    return minor;//returns the minor matrix
}

// Recursive function to calculate the determinant of a matrix
double Determinant(matrix mat) {//passing the matrix as a parmeter

    if (mat.rows == 1) {
        return mat.data[0]; // Base case: determinant of a 1x1 matrix is its only element
    }

    if (mat.rows == 2) {
        // Base case: determinant of a 2x2 matrix is ad - bc
        return mat.data[0] * mat.data[3] - mat.data[1] * mat.data[2];
    }

    double det = 0.0;
    for (int col = 0; col < mat.cols; ++col) {
        // Calculate the cofactor and recursively compute the determinant
        matrix minor = get_minor(mat, 0, col);
        double cofactor = (col % 2 == 0 ? 1 : -1) * mat.data[col] * Determinant(minor);
        det += cofactor;

        // Free the memory allocated for the minor matrix
        free(minor.data);
    }

    return det;//returns the determinant
}

