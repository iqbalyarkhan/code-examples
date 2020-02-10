//
//  main.cpp
//  HashTable
//
//  Created by Iqbal Khan on 2/9/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "HashTable.h"

int main(int argc, const char * argv[]) {
    HashTable<int> h;
    cout << "Empty table: " << endl;
    h.PrintTable();
    h.Insert(5);
    h.Insert(6);
    h.Insert(7);
    h.Insert(15);
    h.Insert(25);
    h.Insert(10);
    h.Insert(11);
    h.Insert(12);
    cout << "New table: " << endl;
    h.PrintTable();
    return 0;
}
