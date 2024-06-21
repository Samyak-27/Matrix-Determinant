// h file to 
#ifndef MATRIX_H
#define MATRIX_H

typedef struct matrix_t{//defining a struct for a matrix
    int rows;
    int cols;
    double *data;
} matrix;

matrix* ReadMatrix(FILE* fp);//Function to read matrix
double Determinant(matrix mat);//Funtion to find the determinant

#endif