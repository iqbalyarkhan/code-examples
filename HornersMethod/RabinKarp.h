//
//  RabinKarp.h
//  Test_UVA
//
//  Created by Iqbal Khan on 4/5/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef RabinKarp_h
#define RabinKarp_h
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

class RK{
public:
    int GetIndex(string,string);
};

int RK::GetIndex(string t, string p){
    if (p.size() > t.size())
        return -1;
    
    const int base = 26;
    int tHash = 0, pHash = 0;
    int power = 1;
    for (int i = 0; i < p.size(); i++){
        power = i ? power * base : 1;
        tHash = tHash * base + t[i];
        pHash = pHash * base + p[i];
    }

    //Match at the first index!
    if (pHash == tHash)
        return 0;
    
    for (int i = int(p.size()); i < int(t.size()); i++){
        if (tHash == pHash)
            return i;
        
        tHash = tHash - t[i] * power;
        tHash = tHash * base + t[i];
        
    }
    
    
    return 0;
}


#endif /* RabinKarp_h */
