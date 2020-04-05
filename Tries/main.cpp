//
//  main.cpp
//  Tries
//
//  Created by Iqbal Khan on 4/4/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "Trie.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    Trie t(26);
    t.Put("she", 40);
    t.Put("shell", 20);
    t.Find("share");
    t.Find("she");
//    char a = 'a';
//    int ia = int('z') - 97;
//    cout << ia << endl;
//    cout << "Heyo!" << endl;
    return 0;
}
