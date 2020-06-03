#include<iostream>

template<typename T>
class myVector {
//Private elements
private:
    T* elem;
    int size;
    int cap;
//Public interface
public:
    //Constructors
    myVector();
    //myVector(const myVector& x);
    //myVector(int n, const T& val);

    //Modifiers
    void push_back(const T& val);

    //DEBUG
    void print();
};