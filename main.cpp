#include<vector>
#include<iostream>
#include"myVector.h"

using namespace std;

int main(){
    vector<int> A {1, 2, 3};
    myVector T;

    cout << "\nTest:\n" << A[0] << "\n" << T.a << "\n";

    return 0;
}