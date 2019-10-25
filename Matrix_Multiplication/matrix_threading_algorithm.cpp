#include <iostream>

#include <pthread.h>
#include "matrix.h"

#include "matrix_threading_algorithm.h"

using namespace std;


void* multiply_element(void *args) {

    matrix_multiplication_args* mma = (matrix_multiplication_args *)args;
    matrix *c = mma->c;
    matrix *a = mma->a;
    matrix *b = mma->b;
    size_t row = mma->row;
    size_t col = mma->col;
    for(size_t i = 0; i < mma->a->cols; i++) {
        c->mat[row][col]+=a->mat[row][i]*b->mat[i][col];
    }

    pthread_exit(0);
    return NULL;
}


void* multiply_matrix_based_element(void * args) {

    matrix_multiplication_args* mma = (matrix_multiplication_args *)args;
    matrix*c = mma->c;
    matrix*a = mma->a;
    matrix*b = mma->b;
    pthread_t thrds[c->rows][mma->c->cols];
    for(size_t i = 0; i < c->rows; i++) {
        for(size_t j = 0; j < c->cols; j++) {
            matrix_multiplication_args* mmas = (matrix_multiplication_args* ) malloc(sizeof(matrix_multiplication_args));
            mmas->a = a;
            mmas->b = b;
            mmas->c = c;
            mmas->row = i;
            mmas->col = j;
            pthread_create(&thrds[i][j], NULL, multiply_element, mmas);
        }
    }

    for(size_t i = 0; i < c->rows; i++) {
        for(size_t j = 0; j < c->cols; j++) {
            pthread_join(thrds[i][j], NULL);
        }
    }
    return NULL;

}

void* multiply_row(void * args) {

    matrix_multiplication_args* mma = (matrix_multiplication_args *)args;
    matrix*c = mma->c;
    matrix*a = mma->a;
    matrix*b = mma->b;
    size_t row = mma->row;
    for(size_t j = 0; j < c->cols; j++) {
        for(size_t k = 0; k < a->cols; k++) {
            c->mat[row][j] += a->mat[row][k] * b->mat[k][j];
        }
    }

    pthread_exit(0);
    return NULL;
}

void* multiply_matrix_based_row(void * args) {
    matrix_multiplication_args* mma = (matrix_multiplication_args *)args;
    matrix*c = mma->c;
    matrix*a = mma->a;
    matrix*b = mma->b;
    pthread_t thrds[c->rows];
    for(size_t i = 0; i < c->rows; i++) {
        matrix_multiplication_args* mmas = (matrix_multiplication_args* ) malloc(sizeof(matrix_multiplication_args));
        mmas->a = a;
        mmas->b = b;
        mmas->c = c;
        mmas->row = i;
        pthread_create(&thrds[i], NULL, multiply_row, mmas);
    }

    for(size_t i = 0; i < c->rows; i++) {
        if(pthread_join(thrds[i], NULL) != 0)cout<<"error on thread["<<i<<"]"<<endl;
    }

    return NULL;
}


