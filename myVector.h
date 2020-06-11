#ifndef MYVECTOR
#define MYVECTOR

#include<iostream>
#include<algorithm>
#include<initializer_list>
#include<stdexcept>

// Todo:
// compile ASAN, UBSAN, TSAN
// create << operator (?)
// iterator: tirar num usar ponteiro (?)

//#################################
//######### Declarations ##########
//#################################
namespace myClasses{
    template<typename T>
    class myVector {
    //Private elements
    private:
        T* elem {nullptr};
        int internalSize {0};
        int cap {0};
    //Public interface
    public:
        //Iterator definition
        // member typedefs provided through inheriting from std::iterator
        class iterator: public std::iterator<
                            std::random_access_iterator_tag,   // iterator_category
                            T,                              // value_type
                            long,                              // difference_type
                            const T*,                       // pointer
                            T>                              // reference
        {
            //iterator member
            private:
                long num {0};   //store index of vector
                T* elemRef {nullptr}; //pointer to myvector elem
            //iterator functions
            public:
                explicit iterator(long _num, T* _elemRef){
                    num = _num;
                    elemRef = _elemRef;
                }
                iterator& operator++() {num = num + 1; return *this;}
                iterator operator++(int) {iterator retval(*this); ++(*this); return retval;}
                bool operator==(iterator other) const {
                    return (num == other.num)&&(elemRef==other.elemRef);
                    }
                bool operator!=(iterator other) const {return !(*this == other);}
                T operator*() {return elemRef[num];}
        };

        //Iterators
        iterator begin() {return iterator(0, elem);}
        const iterator begin() const{return iterator(0, elem);}
        iterator end() {return iterator(internalSize, elem);}
        const iterator end() const{return iterator(internalSize, elem);}
        
        //Constructors - OK
        myVector();
        myVector(const myVector& x);
        myVector(int n, const T& val);
        myVector(std::initializer_list<T> list);
        //Destructor - OK
        ~myVector(){delete[] elem;}

        //Operator = OK
        //copy
        myVector& operator=(const myVector& x);
        //move
        myVector& operator=(myVector&& x);
        //initializer list
        myVector& operator=(std::initializer_list<T> list);

        //Capacity
        int size()const noexcept{return internalSize;}

        //Element access - OK
        T& operator[](int idx){return elem[idx];}
        const T& operator[](int idx) const {return elem[idx];}
        T& at(int idx);
        const T& at(int idx) const;
        T& front(){return elem[0];}
        const T& front() const{return elem[0];}
        T& back(){return elem[internalSize-1];}
        const T& back() const{return elem[internalSize-1];}
        T* data(){return elem;}
        const T* data() const{return elem;}

        //Modifiers
        void push_back(const T& val);
        void pop_back();
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
        internalSize = list.size();
        cap = internalSize;
        elem = new T[cap];
        int i=0;
        for(auto x : list){
            elem[i] = x;
            i++;
        }
    }

    //Operator =
    //Copy
    template <typename T>
    myVector<T>& myVector<T>::operator=(const myVector<T>& x){
        internalSize = x.internalSize;
        cap = x.cap;
        delete[] elem;
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
        delete[] elem;
        elem = x.elem;
        x.elem = nullptr;
        x.internalSize = 0;
        x.cap = 0;
        return *this;
    }
    //initializer list
    template <typename T>
    myVector<T>& myVector<T>::operator=(std::initializer_list<T> list){
        internalSize = list.size();
        cap = internalSize;
        elem = new T[cap];
        int i=0;
        for(auto x : list){
            elem[i] = x;
            i++;
        }
    }

    //Element access
    template <typename T>
    T& myVector<T>::at(int idx){
        if(0 <= idx && idx < internalSize){
            return elem[idx];
        }
        else{
            throw std::out_of_range("My access error");
        }
    }

    template <typename T>
    const T& myVector<T>::at(int idx) const{
        if(0 <= idx && idx < internalSize){
            return elem[idx];
        }
        else{
            throw std::out_of_range("My access error");
        }
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
            delete[] oldElem;
        }
        elem[internalSize] = val;
        internalSize++;
    }

    template <typename T>
    void myVector<T>::pop_back(){
        if(internalSize > 0){
            internalSize--;
        }
    }
}
#endif