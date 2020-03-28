//
//  main.cpp
//  MST
//
//  Created by Iqbal Khan on 3/23/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "MST.h"

int main(int argc, const char * argv[]) {
    MST mst(7);
    mst.Insert(0, 1, 4);
    mst.Insert(0, 2, 3);
    mst.Insert(1, 2, 1);
    mst.Insert(1, 3, 2);
    mst.Insert(2, 3, 3);
    mst.Insert(3, 4, 5);
    mst.Insert(3, 5, 7);
    mst.Insert(4, 5, 6);
    mst.Insert(4, 6, 1);
    mst.Insert(5, 6, 1);
    mst.createMST();
    return 0;
}
