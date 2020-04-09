//
//  main.cpp
//  QuickSort
//
//  Created by Iqbal Khan on 4/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int partition(vector<int>&, int lo, int hi);
void quickSort(vector<int>&, int,int);

int main(int argc, const char * argv[]) {
    
//    vector<int> A = {7,5,3,2,1,6,4,8};
    vector<int> A = {1,2,3,4,5,6,7,8};
    
//    for (auto i : A)
//        cout << i << " ";
//    cout << endl;
    int ans = partition(A,0,7);
    cout << "ans is: " << ans << endl;
//    quickSort(A, 0,7);
//    for (auto i : A)
//        cout << i << " ";
//    cout << endl;
//    cout << "ans: " << partition(A,1,7) << endl;
//    cout << "AND FINALLY: " << endl;
    for(auto i : A)
        cout << i << " ";
//    return 0;
}

void quickSort(vector<int>& A, int lo, int hi){
    if (hi <= lo)
        return;
    int p = partition(A, lo,hi);
    quickSort(A, lo,p-1);
    quickSort(A, p+1,hi);
}

int partition(vector<int>& A, int i, int j){
    cout << "Arr recieved: " << endl;
    for (auto i : A)
        cout << i << " ";
    cout << endl;
    int m = i + (j-i)/2;
    int pivot = -1;
    cout << A[i] << " " << A[j] << " " << A[m] << endl;
    if (A[i] > A[m] && A[i] > A[j])
        pivot = A[m] < A[j] ? j : m;
    else if (A[j] > A[m] && A[j] > A[i])
        pivot = A[m] < A[i] ? i : m;
    else
        pivot = A[j] < A[i] ? i : j;
    cout << "Pivot index: " << pivot << endl;
    cout << "Pivot chosen: " << A[pivot] << endl;
    int temp = A[i];
    A[i] = A[pivot];
    A[pivot] = temp;
    pivot = 0;
    i++;
    
    while (true){
        while (A[i] < A[pivot] && i <= j)
            i++;
        
        while (A[j] > A[pivot] && j >= i)
            j--;
        
        if (i >= j){
            int temp = A[pivot];
            A[pivot] = A[j];
            A[j] = temp;
            break;
        }
        
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
        j--;
    }
    
    return j;
}
