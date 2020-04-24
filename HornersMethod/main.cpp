//
//  main.cpp
//  HornersMethod
//
//  Created by Iqbal Khan on 4/5/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include "RabinKarp.h"

using namespace std;

/**
 - If $x_{i+1}$ is the next string to be tested against our pattern

 - $x_{i}$ is the current string we just tested

 - $t_{i}$ is the text we're removing

 - $R$ is the base of our number (or number of possible characters)

 - $M$ is the length of the pattern

     $
     x_{i+1} = (x_{i} - t_{i}R^{M-1})R + t_{i+M}
     $
 
 */

// d is the number of characters in the input alphabet
#define Radix 256

void search(string txt, string pat)
{
    int M = int(pat.size());
    int N = int(txt.size());
    int i = 0;
    int pHash = 0; // hash value for pattern
    int tHash = 0; // hash value for txt
    int Q = 1;//Radix^(M-1)
    int prime = 997;

    for (i = 0; i < M - 1; i++)
        Q = (Q * Radix) % prime;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        pHash = (Radix * pHash + pat[i]) % prime;
        tHash = (Radix * tHash + txt[i]) % prime;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( pHash == tHash )
        {
            cout<<"Pattern found at index "<< i<<endl;
        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            tHash = (Radix*(tHash - txt[i]*Q) + txt[i+M])%prime;

            // We might get negative value of t, converting it
            // to positive
            if (tHash < 0){
                tHash = (tHash + prime);
            }
        }
    }
}


int main(int argc, const char * argv[]) {
//
//    string test = "othersidehellofromthe";
//    string pat = "hello";
    
    search("hellofromtheotherstrside", "side");
    return 0;
}

