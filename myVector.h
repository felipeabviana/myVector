#include<iostream>
#include<initializer_list>

//#################################
//######### Declarations ##########
//#################################
template<typename T>
class myVector {
//Private elements
private:
    T* elem;
    int internalSize;
    int cap;
//Public interface
public:
    //Constructors
    myVector();
    myVector(const myVector& x);
    myVector(int n, const T& val);
    myVector(std::initializer_list<T> list);
    //Destructor
    ~myVector();

    //Operator =
    //copy
    myVector& operator=(const myVector& x);
    //move
    myVector& operator=(myVector&& x);
    //initializer list
    myVector& operator=(std::initializer_list<T> list);

    //Iterators

    //Capacity
    int size();

    //Element access
    T& operator[](int idx);
    T& at(int idx);
    T& front();
    T& back();
    T* data();

    //Modifiers
    void push_back(const T& val);
};

//################################
//######### Definitions ##########
//################################

//Constructors
template <typename T>
myVector<T>::myVector(){
    internalSize = 0;
    cap = 8;
    elem = new T[cap];
}

template <typename T>
myVector<T>::myVector(const myVector& x){
    internalSize = x.internalSize;
    cap = x.cap;
    elem = new T[cap];
    for(auto i=0;i<internalSize;i++){
        elem[i] = x.elem[i];
    }
}

template <typename T>
myVector<T>::myVector(int n, const T& val){
    internalSize = n;
    cap = n;
    elem = new T[cap];
    for(auto i=0;i<internalSize;i++){
        elem[i] = val;
    }
}

template <typename T>
myVector<T>::myVector(std::initializer_list<T> list){
    internalSize = 0;
    cap = list.size();
    elem = new T[cap];
    for(auto x : list){
        this->push_back(x);
    }
}

//Destructor
template <typename T>
myVector<T>::~myVector(){
    delete elem;
}

//Operator =
//Copy
template <typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& x){
    internalSize = x.internalSize;
    cap = x.cap;
    delete elem;
    elem = new T[cap];
    for(auto i=0;i<internalSize;i++){
        elem[i] = x.elem[i];
    }
    return *this;
}
//move
template <typename T>
myVector<T>& myVector<T>::operator=(myVector&& x){
    internalSize = x.internalSize;
    cap = x.cap;
    delete elem;
    elem = x.elem;
    x.elem = nullptr;
    x.internalSize = 0;
    x.cap = 0;
    return *this;
}
//initializer list
template <typename T>
myVector<T>& myVector<T>::operator=(std::initializer_list<T> list){
    internalSize = 0;
    for(auto x : list){
        this->push_back(x);
    }
}

//Iterators

//Capacity
template <typename T>
int myVector<T>::size(){
    return internalSize;
}

// Element access
template <typename T>
T& myVector<T>::operator[](int idx){
    return elem[idx];
}

template<typename T>
T& myVector<T>::at(int idx){
    return elem[idx];
}

template<typename T>
T& myVector<T>::front(){
    return elem[0];
}

template<typename T>
T& myVector<T>::back(){
    return elem[internalSize-1];
}

template<typename T>
T* myVector<T>::data(){
    return elem;
}

// Modifiers
template <typename T>
void myVector<T>::push_back(const T& val){
    if(internalSize >= cap){
        cap *= 2;
        T* oldElem = elem;
        T* newElem = new T[cap];
        for(auto i=0;i<internalSize;i++){
            newElem[i] = oldElem[i];
        }
        elem = newElem;
        delete oldElem;
    }
    elem[internalSize] = val;
    internalSize++;
}