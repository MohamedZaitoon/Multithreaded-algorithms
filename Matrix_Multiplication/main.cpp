#include <iostream>
#include <pthread.h>
using namespace std;

struct matrix{
    size_t rows;
    size_t cols;
    int **mat;
};
struct submatrix{

    matrix& mat;
    size_t row1;size_t col1;
    size_t rown;size_t coln;
    int get(size_t i, size_t j){
        return mat.mat[i][j];
    }

}

void read_matrix(matrix& mat);
void free_matrix(matrix&mat);
void print_matrix(matrix& mat);
void allocate_matrix(matrix& mat);



matrix* matrix_multiplication(matrix&a, matrix&b){

    matrix* c = new matrix;
    c->rows = a.rows;
    c->cols = b.cols;
    allocate_matrix(*c);
    submatrix sc ={*c, 0,0,c->rows-1,c->cols-1};
    submatrix sa ={a, 0,0,c.rows-1,a.cols-1};
    submatrix sb ={b, 0,0,b.rows-1,b.cols-1};
    multiply()

    return c;

}

void* multiply(submatrix& c,submatrix& a, submatrix& b){
    if(){

    }else{
        submatrix c11,c12,c21,c22;
        submatrix a11,a12,a21,a22;
        submatrix b11,b12,b21,b22;
        c11 = {c,c.row1,c.col1,c.rown/2,c.coln/2};
        a11 = {a,a.row1,a.col1,a.rown/2,a.coln/2};
        b11 = {b,b.row1,b.col1,b.rown/2,b.coln/2};
        c12 = {c,c.row1,c.coln/2+1,c.rown/2,c.coln};
        a12 = {a,a.row1,a.coln/2+1,a.rown/2,a.coln};
        b12 = {b,b.row1,b.coln/2,b.rown/2,b.coln};
        c21 = {c,c.rown/2,c.col1,c.rown/2,c.coln/2};
        a21 = {a,a.rown/2,a.col1,a.rown/2,a.coln/2};
        b21 = {b,b.rown/2,b.col1,b.rown/2,b.coln/2};
        c22 = {c,c.rown/2+1,c.coln/2+1,c.rown,c.coln};
        a22 = {a,a.rown/2+1,a.coln/2+1,a.rown,a.coln};
        b22 = {b,b.rown/2+1,b.coln/2+1,b.rown,b.coln};
        multiply(c11, a11,);
        multiply(, ,);
        multiply(, ,);
        multiply(, ,);



    }



}



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    matrix a,b;
    read_matrix(a);
    read_matrix(b);

    if(a.cols != b.rows){
        cout<<"Number of Column of A and Number of Rows of B must be equal."<<endl;
        return 0;
    }
    matrix* c = matrix_multiplication(a,b);
    print_matrix(*c);

    free_matrix(a);
    free_matrix(b);


    return 0;
}


void read_matrix(matrix& mat){
    cin>>mat.rows>> mat.cols;
    allocate_matrix(mat);
    for(size_t i =0; i < mat.rows; i++){
        for(size_t j = 0; j < mat.cols; j++){
                cin>>mat.mat[i][j];
        }
    }



}
void allocate_matrix(matrix& mat){
    mat.mat = new int*[mat.rows];
    for(size_t i = 0; i < mat.rows; i++){
        mat.mat[i] = new int[mat.cols];
    }
}

void print_matrix(matrix& mat){

    for(size_t i =0; i < mat.rows; i++){
        for(size_t j = 0; j < mat.cols; j++){
                cout<<mat.mat[i][j]<<" ";
        }
        cout<<endl;
    }

}


void free_matrix(matrix&mat){

    for(size_t i = 0; i < mat.rows; i++){
        delete[] mat.mat[i];
    }
    delete[] mat.mat;


}
