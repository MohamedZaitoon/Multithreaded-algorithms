#include <iostream>
#include "matrix.h"
#include "matrix_threading_algorithm.h"
#include <pthread.h>
using namespace std;

matrix* matrix_multiplication(matrix*a, matrix*b) {

    matrix* c = new matrix;
    c->rows = a->rows;
    c->cols = b->cols;
    allocate_matrix(*c);
    for(size_t i = 0; i < c->rows; i++) {
        for(size_t j = 0; j < c->cols; j++) {
            c->mat[i][j] = 0;
        }

    }

    matrix_multiplication_args mma(c,a,b,0,0);

    multiply_matrix_based_row(&mma);
    // multiply_matrix_based_element(&mma);


    return c;

}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    matrix a,b;
    read_matrix(a);
    read_matrix(b);

    if(a.cols != b.rows) {
        cout<<"Number of Column of A and Number of Rows of B must be equal."<<endl;
        return 0;
    }

    matrix* c = matrix_multiplication(&a,&b);
    print_matrix(*c);

    free_matrix(a);
    free_matrix(b);
    free_matrix(*c);
    delete c;
    return 0;
}


