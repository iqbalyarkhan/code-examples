//
//  main.cpp
//  SelectionSort
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
    
    for (int out = 0; out < a.size(); out++){
        int min = out;
        for (int in = out + 1; in < a.size(); in++){
            if(a[in] < a[min])
                min = in;
        }
        
        cout << "a[" << min <<"] is the min: " << a[min] << endl;
        //swap
        int temp = a[out];
        a[out] = a[min];
        a[min] = temp;
        
        cout << "Array so far: " << endl;
                 for (int i = 0; i < a.size(); i++){
                     cout << a[i] << " ";
                 }
                 cout << endl;
    }
    
    return 0;
}
