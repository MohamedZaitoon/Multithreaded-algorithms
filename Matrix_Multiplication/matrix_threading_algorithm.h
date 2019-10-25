#ifndef MATRIX_THREADING_ALGORITHM_H_INCLUDED
#define MATRIX_THREADING_ALGORITHM_H_INCLUDED




class matrix_multiplication_args {
public:
    matrix* c;
    matrix* a;
    matrix* b;
    size_t row;
    size_t col;
    matrix_multiplication_args(matrix *tc, matrix *ta, matrix *tb, size_t trow, size_t tcol) {
        c = tc;
        a = ta;
        b = tb;
        row = trow;
        col = tcol;
    }

};

void* multiply_element(void *args);

void* multiply_matrix_based_element(void * args);

void* multiply_row(void * args);
void* multiply_matrix_based_row(void * args);


#endif // MATRIX_THREADING_ALGORITHM_H_INCLUDED
