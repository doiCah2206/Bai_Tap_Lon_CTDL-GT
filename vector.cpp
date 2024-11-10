#include <iostream>
#include "reverse_iterator.cpp"
using namespace std;
#ifndef __vector__cpp__
#define __vector__cpp__

template <class T>
class vector
{
    long num, cap;
    T *vec;

public:
    vector()
    {
        num = cap = 0;
        vec = nullptr;
    }
    vector(long c)
    {
        num = 0;
        cap = c;
        vec = new T[c];
    }
    vector(long c, int x)
    {
        num = c;
        cap = c;
        //
        if (vec)
            delete vec;
        vec = new T[cap];
        for (int i = 0; i < c; i++)
        {
            vec[i] = x;
        }
    }
    ~vector()
    {
        if (vec)
            delete[] vec;
    }
    long capacity() { return cap; }
    long size() { return num; }
    bool empty() { return num == 0; }
    void pop_back()
    {
        if (num == 0)
            return;
        num--;
    }
    void pop_front()
    {
        if (num == 0)
        {
            return;
        }

        for (int i = 0; i < num - 1; i++)
        {
            vec[i] = vec[i + 1];
        }
        num--;
    }
    void extend()
    {
        cap = cap * 2 + 5;
        T *newvec = new T[cap];
        for (int i = 0; i < num; i++)
        {
            newvec[i] = vec[i];
        }
        delete[] vec;
        vec = newvec;
    }
    void push_back(T x)
    {
        if (num == cap)
        {
            extend();
        }
        vec[num] = x;
        num++;
    }
    void insert(int p, T x)
    {
        if (p > num)
        {
            return;
        }
        if (num == cap)
        {
            extend();
        }
        for (int i = num; i > p; i--)
        {
            vec[i] = vec[i - 1];
        }
        vec[p] = x;
        num++;
    }
    T &operator[](int k)
    {
        return vec[k];
    }
    vector<T> &operator=(const vector<T> &c)
    {
        if (this == &c)
            return *this;
        delete[] vec;
        this->num = c.num;
        this->cap = c.cap;
        vec = new T[cap];
        for (int i = 0; i < num; i++)
        {
            vec[i] = c.vec[i];
        }
        return *this;
    }
    typedef vector_reverse_iterator<T> reverse_iterator;
    reverse_iterator rbegin() { return reverse_iterator(vec + num - 1); }
    reverse_iterator rend() { return reverse_iterator(vec - 1); }
    typedef T *iterator;
    iterator begin() { return vec; }
    iterator end() { return vec + num; }
};
#endif
