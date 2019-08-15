#include"Square_matrix.h"
#include"Vector.h"
#include <iostream>
using namespace std;

int main()
{
    long long int dimension; //dimension of the square matrix
    cin >> dimension;

    long long int p; //num of power iteration that are to be executed
    cin  >> p;

    // This block takes the input for the matrix
    float**arr = new float*[dimension];
    for(int i = 0; i < dimension; i++)
    {
        arr[i] = new float[dimension];
    }
    for(int i = 0; i < dimension; i++)
    {
        for(int j = 0; j < dimension; j++)
        {
            float var;
            cin >> var;
            arr[i][j] = var;
        }
    }


    // Initializing the square_matrix and running it through power-iteration
    Square_matrix sm(dimension, arr);
    sm.power_iteration(p);


    return 0;
}