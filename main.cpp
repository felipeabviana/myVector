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

    for(auto i=0;i<25;i++){
        cout << A[i] << "\n";
    }

    B.print();

    return 0;
}