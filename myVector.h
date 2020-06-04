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
    //myVector(const myVector& x);
    //myVector(int n, const T& val);
    ~myVector();

    //Element access
    T& operator[](int idx);
    const T& operator[](int idx) const;
    T& at(int idx);
    const T& at(int idx) const;

    //Modifiers
    void push_back(const T& val);

    //DEBUG
    void print();
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

/*myVector::myVector(const myVector& x){

}

myVector::myVector(int n, const T& val){

}*/ 

// Element access
template <typename T>
T& myVector<T>::operator[](int idx){
    return elem[idx];
}

template <typename T>
const T& myVector<T>::operator[](int idx) const {
    return elem[idx];
}

template<typename T>
T& myVector<T>::at(int idx){
    return elem[idx];
}

template<typename T>
const T& myVector<T>::at(int idx) const {
    return elem[idx];
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

// DEBUG
template <typename T>
void myVector<T>::print(){
        for(auto i=0;i<size;i++){
            std::cout << elem[i] << "\n";
        }
    }
