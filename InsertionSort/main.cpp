//
//  main.cpp
//  InsertionSort
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


int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3,4,5};
    
    for (int out = 0; out < int(a.size() - 1); out++){
        int in = out + 1;
        while (a[in] < a[out]){
            int temp = a[in];
            a[in] = a[out];
            a[out] = temp;
            out--;
            in--;
        }
        
        cout << "array as of now: " << endl;
        for (int i = 0; i < a.size(); i++){
            cout << a[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}
