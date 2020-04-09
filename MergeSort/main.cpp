#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int>&, int lo, int mid, int hi);

void recMergeSort(vector<int>&,int lo, int hi);

int main(){
    vector<int> a = {9,8,7,6,5};
    int hi = int(a.size()) - 1;
    recMergeSort(a, 0, hi);
    cout << "Finally: " <<endl;
    for (auto i : a){
        cout << i << " ";
    }
    cout << endl;
}

void recMergeSort(vector<int>& arr,int lo, int hi){
    if (hi == lo)
        return;
    int mid = (lo + (hi - lo)/2);
    recMergeSort(arr, lo, mid);
    recMergeSort(arr, mid+1, hi);
    merge(arr,lo,mid,hi);
}

void merge(vector<int>& originalArr,int lo, int mid, int hi){
    vector<int> temp(originalArr);
    int i = lo;
    int j = mid + 1;
    int k = lo;
    
    for (; k <= hi; k++){
        if ((i <= mid) && temp[i] < temp[j]){
            originalArr[k] = temp[i];
            i++;
        } else if ((j <= hi) && temp[j] < temp[i]){
            originalArr[k] = temp[j];
            j++;
        } else if (j > hi){
            originalArr[k] = temp[i];
            i++;
        } else {
            originalArr[k] = temp[j];
            j++;
        }
    }
    
    cout << "Returning from merge: " << endl;
    for (auto i : originalArr)
        cout << i << " ";
    cout << endl;
    cout << endl;
}
