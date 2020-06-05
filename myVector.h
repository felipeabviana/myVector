#include<iostream>

//#################################
//######### Declarations ##########
//#################################
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
    myVector(const myVector& x);
    //myVector(int n, const T& val);
    ~myVector();

    //Operator =
    //copy
    myVector& operator=(const myVector& x);
    //move
    myVector& operator=(myVector&& x);
    //initializer list
    //myVector& operator=(initializer_list list);

    //Element access
    T& operator[](int idx);
    T& at(int idx);
    T& front();
    T& back();
    T* data();

    //Modifiers
    void push_back(const T& val);

    //DEBUG
};

//################################
//######### Definitions ##########
//################################

//Constructors
template <typename T>
myVector<T>::myVector(){
    size = 0;
    cap = 8;
    elem = new T[cap];
}

template <typename T>
myVector<T>::~myVector(){
    delete elem;
}

template <typename T>
myVector<T>::myVector(const myVector& x){
    size = x.size;
    cap = x.cap;
    elem = new T[cap];
    for(auto i=0;i<size;i++){
        elem[i] = x.elem[i];
    }
}

/*myVector::myVector(int n, const T& val){

}*/ 

//Operator =
//Copy
template <typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& x){
    size = x.size;
    cap = x.cap;
    delete elem;
    elem = new T[cap];
    for(auto i=0;i<size;i++){
        elem[i] = x.elem[i];
    }
    return *this;
}
//move
template <typename T>
myVector<T>& myVector<T>::operator=(myVector&& x){
    size = x.size;
    cap = x.cap;
    delete elem;
    elem = x.elem;
    x.elem = nullptr;
    x.size = 0;
    x.cap = 0;
    return *this;
}
//initializer list

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
    return elem[size-1];
}

template<typename T>
T* myVector<T>::data(){
    return elem;
}

// Modifiers
template <typename T>
void myVector<T>::push_back(const T& val){
    if(size >= cap){
        cap *= 2;
        T* oldElem = elem;
        T* newElem = new T[cap];
        for(auto i=0;i<size;i++){
            newElem[i] = oldElem[i];
        }
        elem = newElem;
        delete oldElem;
    }
    elem[size] = val;
    size++;
}