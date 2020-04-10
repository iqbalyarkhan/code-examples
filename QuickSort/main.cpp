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

int medianOfThree(vector<int>&,int i, int j);

int main(int argc, const char * argv[]) {
    vector<int> A = {9,13,4,21,2,11};
//    cout << "ans: " << ans << endl;
    quickSort(A, 0,int(A.size() - 1));
    for(auto i : A)
        cout << i << " ";

}

void quickSort(vector<int>& A, int lo, int hi){
    if (hi <= lo)
        return;
    int p = partition(A, lo,hi);
    quickSort(A, lo, p-1);
    quickSort(A, p+1,hi);
}

int partition(vector<int>& A, int i, int j){
    //Median of three pivot calculation
    int pivot = medianOfThree(A, i, j);
    int temp = A[i];
    A[i] = A[pivot];
    A[pivot] = temp;
    pivot = i;
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

//Function to calculate median of three
int medianOfThree(vector<int>& A,int i, int j){
    int m = i + (j-i)/2;
    int pivot = -1;
    if (A[i] > A[m] && A[i] > A[j])
        pivot = A[m] < A[j] ? j : m;
    else if (A[j] > A[m] && A[j] > A[i])
        pivot = A[m] < A[i] ? i : m;
    else
        pivot = A[j] < A[i] ? i : j;
    return pivot;
}
