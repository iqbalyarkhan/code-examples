//
//  main.cpp
//  BubbleSort
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
    vector<int> a = {5,4,3,2,1};
    for (int out = int(a.size() - 1); out >= 0; out--){
        for (int in = 0; in < out; in++){
            if (a[in] > a[in + 1]){
                int temp = a[in + 1];
                a[in + 1] = a[in];
                a[in] = temp;
            }
            
            cout << "Array so far: " << endl;
            for (int i = 0; i < a.size(); i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
