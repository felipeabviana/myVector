#include<vector>
#include<iostream>
#include"myVector.h"

using namespace std;

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

    for(auto i=0;i<25;i++){
        cout << A[i] << " " << B[i] << "\n";
    }

    cout << A.front() << " " << B.front() << "\n";
    cout << A.back() << " " << B.back() << "\n";

    C = A.data();
    D = B.data();
    cout << C[0] << " " << D[0] << "\n";

    myVector<int> E;
    E = B;
    myVector<int> F = B;

    for(auto i=0;i<25;i++){
        cout << E[i] << " " << F[i] << "\n";
    }

    return 0;
}