#include"myVector.h"

//######## Constructors ############
template <typename T>
myVector<T>::myVector(){
    size = 0;
    cap = 8;
    elem = new T[cap];
}

/*myVector::myVector(const myVector& x){

}

myVector::myVector(int n, const T& val){

}*/ 

//########### Modifiers ############
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

template class myVector<int>;