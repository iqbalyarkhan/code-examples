//
//  main.cpp
//  BinaryTrees
//
//  Created by Iqbal Khan on 1/26/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    BinaryTree<int> bt;
    bt.Insert(10);
    bt.Insert(13);
    bt.Insert(11);
    bt.Insert(12);
//    bt.InOrderTraversal();
    bt.PreOrderTraversal();
    cout << endl;
    cout << "max: " << bt.FindMax() << endl;
    cout << "min: " << bt.FindMin() << endl;
    bt.Delete(13);
    cout << "After deletion: " << endl;
    bt.PreOrderTraversal();
    
    return 0;
}
