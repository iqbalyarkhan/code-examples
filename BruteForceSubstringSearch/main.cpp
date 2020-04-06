//
//  main.cpp
//  BruteForceSubstringSearch
//
//  Created by Iqbal Khan on 4/5/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, const char * argv[]) {
    string pattern = "lazy";
    string text = "thequickbrownlazyfoxjumpsoverdog";
    int index = -1;
    bool found = true;
    for (int i = 0; i < text.size(); i++){
        if (text[i] == pattern[0]){
            index = i;
            int j = 0;
            for (; j < pattern.size(); j++){
                if (text[index] != pattern[j]){
                    found = false;
                    break;
                } else {
                    index++;
                }
            }
            if (found){
                break;
            }
        }
    }
    
    if (found){
        cout << "Found match at index: " << index << endl;
    } else {
        cout << pattern << " not in text " << endl;
    }
    
    return 0;
}
