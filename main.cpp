#include<vector>
#include<iostream>
#include"myVector.h"

using namespace std;
using namespace myClasses;

//printDebug Function
template <typename T>
void printVector(myVector<T>& toPrint){
    for(auto i=0;i<toPrint.size();i++){
        cout << toPrint[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void printVector(vector<T>& toPrint){
    for(auto i=0;i<toPrint.size();i++){
        cout << toPrint[i] << " ";
    }
    cout << "\n";
}

//Compare debug function
template<typename T>
string compareVector(const vector<T>& expected, const myVector<T>& obtained){
    if(expected.size() != obtained.size()){return "FAIL";}
    for(auto i=0;i<expected.size();i++){
        if(expected[i] != obtained[i]){return "FAIL";}
    }
    return "PASS";
}

int main(){
    vector<int> A;
    myVector<int> B;
    int* C;
    int* D;

    //Test performing same operation in vector and myvector
    for(auto i=0;i<25;i++){
        A.push_back(i);
        B.push_back(i);
    }
    A[9] = 999;
    B[9] = 999;
    A.at(2) = 777;
    B.at(2) = 777;
    A.front() = 111;
    B.front() = 111;
    A.back() = 0;
    B.back() = 0;
    cout << compareVector(A, B) << "\n";

    myVector<int> E;
    E = B;
    myVector<int> F = B;
    cout << compareVector(A, E) << "\n";
    cout << compareVector(A, F) << "\n";

    myVector<int> G;
    G = {1,3,4,9};
    myVector<int> H(10,5);
    myVector<int> I {1,2,3};
    vector<int> Ge;
    Ge = {1,3,4,9};
    vector<int> He(10,5);
    vector<int> Ie {1,2,3};
    cout << compareVector(Ge, G) << "\n";
    cout << compareVector(He, H) << "\n";
    cout << compareVector(Ie, I) << "\n";

    I.pop_back();
    Ie.pop_back();
    cout << compareVector(Ie, I) << "\n";

    G.resize(9);
    Ge.resize(9);
    cout << compareVector(Ge, G) << "\n";
    G.resize(2);
    Ge.resize(2);
    cout << compareVector(Ge, G) << "\n";
    G.reserve(128);
    Ge.reserve(128);
    if(G.capacity()==Ge.capacity()){cout<<"PASS\n";}
    else{cout<<"FAIL\n";}
    G.shrink_to_fit();
    Ge.shrink_to_fit();
    if(G.capacity()==Ge.capacity()){cout<<"PASS\n";}
    else{cout<<"FAIL\n";}

    //Test data access
    int* Data = I.data();
    if(Data[1]==2){cout << "PASS\n";}
    else{cout << "FAIL\n";}

    //Test access out of range
    try{
        cout << I.at(6);
    }
    catch (const std::out_of_range& oor) {
        cout << "Out of Range error: " << oor.what() << '\n';
    }

    //Test getting myVector info
    cout << I.max_size() << "\n";
    myVector<int> Empty;
    if(Empty.empty()==true){cout << "PASS\n";}
    else{cout << "FAIL\n";}

    //Test functions


    //__shrink_to_fit_aux


    return 0;
}