#include "matrix.h"
#include <iostream>

using namespace std;




void read_matrix(matrix& mat) {
    cin>>mat.rows>> mat.cols;
    allocate_matrix(mat);
    for(size_t i =0; i < mat.rows; i++) {
        for(size_t j = 0; j < mat.cols; j++) {
            cin>>mat.mat[i][j];
        }
    }



}
void allocate_matrix(matrix& mat) {
    mat.mat = new int*[mat.rows];
    for(size_t i = 0; i < mat.rows; i++) {
        mat.mat[i] = new int[mat.cols];
    }
}

void print_matrix(matrix& mat) {

    for(size_t i =0; i < mat.rows; i++) {
        for(size_t j = 0; j < mat.cols; j++) {
            cout<<mat.mat[i][j]<<" ";
        }
        cout<<endl;
    }
}


void free_matrix(matrix&mat) {

    for(size_t i = 0; i < mat.rows; i++) {
        delete[] mat.mat[i];
    }
    delete[] mat.mat;
}
