//
//  main.cpp
//  MergeSort
//
//  Created by Iqbal Khan on 1/25/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> mergeVecs(vector<int>&, vector<int>&);
void mergeInPlace(vector<int>&, int lo, int mid, int hi);
void sort(vector<int>& A, int lo, int hi);
void mergeSort(vector<int>&);

int main(int argc, const char * argv[]) {
    vector<int> A = {1,2,8};
    vector<int> B = {5,7,9,10};
    vector<int> ans = mergeVecs(A,B);
//    vector<int> A = {1,2,8,5,7,9,10};
//    sort(A,0,int(A.size() - 1));
//    mergeInPlace(A, 0, 2, 6);
    for (auto curr : ans){
        cout << curr << " ";
    }
    
    cout << endl;
    
    return 0;
}

//void mergeSort(vector<int>& A){
//    if (A.size() == 1)
//        return;
//    int mid = 
//}

vector<int> mergeVecs(vector<int>& A, vector<int>& B){
    vector<int> ans;
    int a = 0;
    int b = 0;

    while (true){
        if (A[a] < B[b] && a < A.size()){
            ans.push_back(A[a]);
            a++;
        } else if (B[b] < A[a] && b < B.size()){
            ans.push_back(B[b]);
            b++;
        } else if (a == A.size()){
            while (b != B.size()){
                ans.push_back(B[b]);
                b++;
            }
            break;
        } else {
            while (a != A.size()){
                ans.push_back(A[a]);
                a++;
            }
            break;
        }
    }

    return ans;
}

void sort(vector<int>& A, int lo, int hi){
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo)/2;
    sort(A,lo,mid);
    sort(A,mid+1,hi);
    mergeInPlace(A,lo,mid,hi);
}

void mergeInPlace(vector<int>& A, int lo, int mid, int hi){
    vector<int> aux;
    //copy to aux
    for (auto curr : A){
        aux.push_back(curr);
    }
    int i = 0;
    int j = lo;
    int k = mid + 1;
    
    while (j < mid + 1 &&  k <= hi){
        if (aux[j] < aux[k]){
            A[i] = aux[j];
            j++;
            i++;
        } else{
            A[i] = aux[k];
            k++;
            i++;
        }
    }
    
    if (j == mid + 1){
        //copy over all from right half:
        while (k <= hi){
            A[i] = aux[k];
            i++;
            k++;
        }
    } else{
        //copy over all from left half:
        while (j < mid + 1){
            A[i] = aux[j];
            i++;
            j++;
        }
    }
}
