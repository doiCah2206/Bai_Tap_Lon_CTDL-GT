#include <iostream>
using namespace std;

template <class T>
class vector_reverse_iterator
{
    T *curr;

public:
    vector_reverse_iterator() { curr = nullptr; }
    vector_reverse_iterator(T *c = nullptr) { curr = c; }
    vector_reverse_iterator<T> &operator=(const vector_reverse_iterator<T> &t){
        this->curr = t.curr;
        return *this;
    }
    bool operator!=(const vector_reverse_iterator<T> &t){
        return this->curr != t.curr;
    }
    vector_reverse_iterator<T> &operator++(){
        curr = curr - 1;
        return *this;
    }
    vector_reverse_iterator<T> &operator++(int){
        vector_reverse_iterator<T> temp = *this;
        this->curr = this->curr - 1;
        return temp;
    }
    T &operator*() { return *curr; }
};
