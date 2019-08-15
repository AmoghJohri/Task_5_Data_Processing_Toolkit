#ifndef SQUARE_MATRIX_H_
#define SQUARE_MATRIX_H_

#include"Vector.h"
#include<iostream>
using namespace std;

class Square_matrix
{
    private:
        long long int size; //As it is a square matrix, specififying one of the dimensions (row or col) is enoughs
        float** mat; //pointers to the cells of the matrix

    public:
        Square_matrix(long long int, float**); //Forms a square matrix on being given the size of the row/col and the grid of values
        Square_matrix(long long int); //Forms a square matrix on being given the size of the row/col. The default values of each cell is set to 0
        Square_matrix(const Square_matrix&); //Forms a square matrix by deep copying another Square matrix given as a parameter
        ~Square_matrix(); //Destructor for the square matrix

        long long int get_size(); //gives the dimension of the matrix
        float get_cell(long long int, long long int); //gives the value in the specified cell of the matrix
        void set_cell(long long int, long long int, float); //sets the value in the specified cell of the matrix
        void power_iteration(long long int); //Power Iteration function; gives out eigen-vectors and corresponding eigen-values
        float* get_row(long long int); //gives out the specified row of the matrix in the form of a vector
        float* get_column(long long int); //gives out the specified col of the matrix in the form of a vectors

        Vector operator * (Vector &obj) // multiplies vector a matrix and outputs the obtained vector
        {
            float* arr2 = new float[size];
            for(int i = 0; i < size; i++)
            {
                arr2[i] = 0;
            }
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    arr2[i] = arr2[i] + mat[i][j]*obj.get_value_at(j);
                }
            }
            Vector output(size, arr2);
            return output;
        }

        friend ostream &operator << (ostream &stream, const Square_matrix &obj) //Prints out the matrix in a row into col format
        {
            for(int i = 0; i < obj.size; i++)
            {
                for(int j = 0; j < obj.size; j++)
                {
                    cout << obj.mat[i][j] << " ";
                }
                cout << endl;
            }
        }


};

#endif