#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
using namespace std;

class Vector
{
    private:
        long long int size; //cardinality of the vector
        float* arr; //pointers to the values in the vector

    public:
        Vector(long long int, float*); //Forms a vector of the its cardinality and the values it contains, given as parameters
        Vector(const Vector &obj); //Forms a vector iby deep-copying another vector given as a parameter
        Vector(long long int); //Forms a Zero-vector of its cardinality given as a parameter
        ~Vector(); //Destructor for the vector

        long long int get_size(); //gives the cardinality of the vector
        float get_value_at(long long int); //gives the value of the ith element of the vector
        float get_max(); //gives the maximum numeric value of all the different components in the vector
        void set_size(long long int); // sets the cardinality of the vector, if there is a size increase the new elements are all 0s
        void set_value_at(long long int, float); //sets the value of the ith component of the vector
        void divide_by(float); //scalar division of the vector

        Vector operator = (const Vector &obj) //forms a vector by deepcopying another vector
        {
            size = obj.size;
            float *arr = new float[size];
            for(int i = 0; i < size; i++)
            {
                arr[i] = obj.arr[i];
            }
            this->arr = arr;
        }

        friend ostream &operator << (ostream &stream, const Vector &obj) //prints out the vector as a part of its different components
        {
            cout << "{ ";
            for(int i = 0; i < obj.size; i++)
            {
                cout << obj.arr[i];
                if(i != obj.size -1)
                {
                    cout << ", ";
                }
            }
            cout << " }";
            cout << endl;
        }


};

#endif