#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

void recMergeSort(vector<int>&, int low, int high);

void mergeArrs(vector<int>& A, int low, int mid, int high);

int main(){
    vector<int> input = {9,8,7,6,5,4,3,2,1};
    recMergeSort(input, 0, int(input.size()));
}

void recMergeSort(vector<int>& arr, int low, int high){
    if (high <= low)
        return;
    int mid = low + (high - low)/2;
    recMergeSort(arr, low, mid);
    recMergeSort(arr, mid+1, high);
    mergeArrs(arr,low,mid,high);
    
}

void mergeArrs(vector<int>& A, int low, int mid,int high){
    vector<int> aux(high,-1);
    for (int i = low; i <= high; i++){
        aux[i] = A[i];
    }
    cout << endl;
    cout << "************** Arr received in mergeArrs is: ****************" << endl;
    for (auto j : aux)
        cout << j << " ";
    cout << "*********** done ************ " << endl;
    cout << endl;

}
