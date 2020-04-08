//
//  KMP.h
//  Test_UVA
//
//  Created by Iqbal Khan on 4/7/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#ifndef KMP_h
#define KMP_h

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class KMP{
private:
    vector<int> prefixArr;
    void buildPrefixArr(string);
    int patternLength;
    
public:
    vector<int> GetIndex(string,string);
};

vector<int> KMP::GetIndex(string text, string pat){
    patternLength = int(pat.size());
    buildPrefixArr(pat);
    vector<int> ans;
    for (int i = 0; i < int(text.size()); i++){
        //pattern iterator
        int patItr = 0;
        int txtItr = i;
        if (text[i] == pat[patItr]){
            int numMatched = 0;
            while (text[txtItr] == pat[patItr]){
                txtItr++;
                patItr++;
                numMatched++;
            }
            
            if (numMatched == patternLength){
                //We've got a full match!
                ans.push_back(i);
                i += patternLength;
            } else{
                //Partial match, figure out how much to move
                i = numMatched - prefixArr[numMatched] + 1;
            }
        }
    }
    
    return ans;
}

void KMP::buildPrefixArr(string pat){
    prefixArr.resize(patternLength);
    int pre = 0;
    for (int i = 1; i < patternLength; i++){
        if (pat[i] == pat[pre])
            pre++;
        else
            pre = 0;
        prefixArr[i] = pre;
    }
}


#endif /* KMP_h */
