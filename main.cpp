#include<vector>
#include<iostream>
#include"myVector.h"

using namespace std;

int main(){
    vector<int> A;
    myVector<int> B;

    for(auto i=0;i<25;i++){
        A.push_back(i);
        B.push_back(i);
    }

    A[9] = 999;
    B[9] = 999;

    A.at(2) = 777;
    B.at(2) = 777;

    for(auto i=0;i<25;i++){
        cout << A[i] << " " << B[i] << "\n";
    }

    return 0;
}