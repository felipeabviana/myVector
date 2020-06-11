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

int main(){
    vector<int> A;
    myVector<int> B;
    int* C;
    int* D;

    for(auto i=0;i<25;i++){
        A.push_back(i);
        B.push_back(i);
    }

    A[9] = 999;
    B[9] = 999;

    A.at(2) = 777;
    B.at(2) = 777;

    A.front() = 111;
    B.back() = 111;

    printVector(A);
    printVector(B);

    cout << A.front() << " " << B.front() << "\n";
    cout << A.back() << " " << B.back() << "\n";

    C = A.data();
    D = B.data();

    myVector<int> E;
    E = B;
    myVector<int> F = B;
    printVector(E);
    printVector(F);

    myVector<int> G;
    G = {1,3,4,9};
    printVector(G);

    myVector<int> H(10,5);
    printVector(H);

    myVector<int> I {1,2,3};
    cout << I.size() << "\n";
    printVector(I);
    I.pop_back();
    printVector(I);

    for(auto X : A){
        cout << X << ".";
    }
    cout << "\n";

    try{
        cout << I.at(6);
    }
    catch (const std::out_of_range& oor) {
        cout << "Out of Range error: " << oor.what() << '\n';
    }

    return 0;
}