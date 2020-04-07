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
private:
    long patHash;
    long RM;
    int Radix = 256;
    long prime = 997;

    void setRM(int);
    
public:
    long HashFunction(string key, int m);
    void PrintIndex(string,string);
    
};


void RK::setRM(int m){
    RM = 1;
    for (int i = 0; i < m; i++){
        RM = (Radix * RM) % prime;
    }
}

void RK::PrintIndex(string text, string pat){
    //Setting RM
    setRM(int(pat.size()));
    int m = int(pat.size());
    int n = int(text.size());
    long patHash = HashFunction(pat, m);
    string txt = string();
    for (int i = 0; i < m; i++){
        txt += text[i];
    }
    long textHash = HashFunction(txt, m);
    if (textHash == patHash)
        cout << "Found a match at index 0!" << endl;
    for (int i = m; i < n; i++){
        char c = text[i];
        char cNext = text[i + 1];
        int cInt = int(c);
        textHash = ((textHash - RM*cInt) * (Radix % prime) +
    }
    
    
}


long RK::HashFunction(string key, int m){
    long h = 1;
    for (int i = 0; i < m; i++){
        char c = key[i];
        int key = int(c);
        h = (Radix * h + key) % prime;
    }
    
    return h;
}

#endif /* RabinKarp_h */
