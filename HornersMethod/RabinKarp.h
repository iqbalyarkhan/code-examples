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
    long HashFunction(string key, int m);
    int GetIndex(string,string);
    
};

int RK::GetIndex(string text, string pat){
    long patternHash = HashFunction(pat, int(pat.size()));
    
    //Iterating over text to grab substrings that're equal
    //in length to the pattern string.
    int index = -1;
    for (int i = 0; i < text.size(); i++){
        string curr = string();
        int end = i + int(pat.size());
        if (end <= text.size()){
            int j = i;
            while (j < end){
                curr+= text[j];
                j++;
            }
            long textHash = HashFunction(curr, int(pat.size()));
            if (textHash == patternHash){
                index = i;
                return index;
            }
        }
    }
    
    return index;
}

long RK::HashFunction(string key, int m){
    long h = 1;
    for (int i = 0; i < m; i++){
        char c = key[i];
        int key = int(c);
        h = (26 * h + key) % 997;
    }
    
    return h;
}

#endif /* RabinKarp_h */
