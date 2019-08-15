#include "Vector.h"
#include "float.h"
#include<iostream>
using namespace std;

Vector::Vector(long long int s, float* a):size(s),arr(a){};

Vector::Vector(const Vector &obj):size(obj.size)
{
    float *arr = new float[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
    this->arr = arr;
}

Vector::Vector(long long int s):size(s)
{
    float* arr = new float[size];
    for(int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
    this->arr = arr;
}

Vector::~Vector() {};

long long int Vector::get_size()
{
    return size;
}

float Vector::get_value_at(long long int x)
{
    return arr[x];
}

void Vector::set_size(long long new_size)
{
    float* arr2 = new float[size];
    int i = 0;
    for(i = 0; i < size; i++)
    {
        arr2[i] = arr[i];
    }
    for(;i < new_size; i++)
    {
        arr2[i] = 0;
    }
    size = new_size;
    this->arr = arr2;
}

void Vector::set_value_at(long long int x, float y)
{
    arr[x] = y;
}

float Vector::get_max()
{
    float max = -1*DBL_MAX;
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void Vector::divide_by(float d)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] =arr[i]/d;
    }
}


