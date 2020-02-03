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
//    bt.Insert(10);
//    bt.Insert(4);
//    bt.Insert(11);
//    bt.Delete(10);
            bt.Insert(3);
            bt.Insert(8);
            bt.Insert(20);
            bt.Insert(15);
            bt.Insert(17);
            bt.Insert(25);
            bt.Insert(23);
    bt.PostOrderTraversal();
    cout << endl;
    //    cout << endl;
    //    cout << "After deleting 4: " << endl;
    //    bt.Delete(4);
    //        cout << endl;
    //        cout << "max: " << bt.FindMax() << endl;
    //        cout << "min: " << bt.FindMin() << endl;
    while (true){
        int deleteNode;
        cout << "Node to delete: " << endl;
        cin >> deleteNode;
        bt.Delete(deleteNode);
        cout << "After deletion: " << endl;
        bt.PostOrderTraversal();
        cout << endl;
    }
    
    
    //    bt.PostOrderTraversal();
    //    cout << endl;
    //
    //
    //
    //    cout << "After deleting 20: " << endl;
    //    bt.Delete(20);
    //    bt.PostOrderTraversal();
    //    cout << endl;
    //    bt.Delete(10);
    //    bt.PostOrderTraversal();
    //    cout << endl;
    
    return 0;
}
