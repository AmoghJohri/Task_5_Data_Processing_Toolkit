#include"Square_matrix.h"
#include<iostream>
using namespace std;

Square_matrix::Square_matrix(long long int s, float **m):size(s),mat(m){};

Square_matrix::Square_matrix(long long int s):size(s)
{
    float** mat = new float*[size];
    for(int i = 0; i < size; i++)
    {
        mat[i] = new float[size];
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat[i][j] = 0;
        }
    }
    this->mat = mat;
}

Square_matrix::Square_matrix(const Square_matrix& obj):size(obj.size)
{
    float** mat = new float*[size];
    for(int i = 0; i < size; i++)
    {
        mat[i] = new float[size];
    }
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            mat[i][j] = obj.mat[i][j];;
        }
    }
    this->mat = mat;
}

Square_matrix::~Square_matrix()
{
    delete[] mat; //As this points to the same memory locations as the vectors, freeing either one of them is sufficient
}

long long int Square_matrix::get_size()
{
    return size;
}

float Square_matrix::get_cell(long long int x, long long int y)
{
    return mat[x][y];
}

void Square_matrix::set_cell(long long int x, long long int y, float d)
{
    mat[x][y] = d;
}

float* Square_matrix::get_row(long long int x)
{
    float* arr = new float[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = mat[x][i];
    }
    return arr;
}

float* Square_matrix::get_column(long long int x)
{
    float* arr = new float[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = mat[i][x];
    }
    return arr;
}

void Square_matrix::power_iteration(long long int p)
{
    Square_matrix m(size, mat);

    Vector v_(size, get_column(0)); //This is our 0th (or first) guess as to the eigen vector; this corresponds to the first column of the matrix

    // The first iteration has been cancelled out as the output is largely random in this case

    Vector v = m * v_; //The 'guess' or the eigen-vector obtained on the last iteration is multiplied with the matrix in order to obtain vector v;
    v.divide_by(v.get_max()); //The maximum value(eigen-value corresponding to the eigen-vector) in the obtained vector is gotten and the entire vector is divided by that value;
    v_ = v; //The next eigen vector is set to the obtained eigen vector by multiplying the last eigen vector with the matrix

    /* As the first eigen vector which has been guessed above is just the first row of the matrix, this has not been included in the set of eigen-vectors and eigen-values that the function outputs*/

    for(int counter = 0; counter < p; counter++) //This above mentioned procedure is carried out 'p' number times
    {
        v = m * v_;
        cout << "Eigen vector obtained after iteration " << counter+1 << " : ";
        cout << v;
        cout << "Eigen value obtained after iteration " << counter+1 << " : ";
        cout << v.get_max();
        v.divide_by(v.get_max());
        cout << endl;
        v_ = v;
    }
}

