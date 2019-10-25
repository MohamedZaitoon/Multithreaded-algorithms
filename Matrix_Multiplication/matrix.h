#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <iostream>
struct matrix {
    size_t rows;
    size_t cols;
    int **mat;
};


void read_matrix(matrix& mat);
void free_matrix(matrix&mat);
void print_matrix(matrix& mat);
void allocate_matrix(matrix& mat);






#endif // MATRIX_H_INCLUDED
