//
//  main.cpp
//  UniquePointers
//
//  Created by Iqbal Khan on 4/25/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <memory>

using namespace std;

class Book{
private:
    string title;
public:
    Book(){
        cout << "Constructor called! " << endl;
    }

    void SetTitle(string t){
        title = t;
    }

    string GetTitle(){
        return title;
    }

    ~Book(){
        cout << "Destructor called! " << endl;
    }
};

int main(int argc, const char * argv[]) {
    cout << "About to enter scope" << endl;
    shared_ptr<Book> b2;
    {        
        shared_ptr<Book> b1 = make_shared<Book>();
        b1->SetTitle("Shared pointer book");
        cout << b1->GetTitle() << endl;
        b2 = b1;
        cout << "use count inside the scope: " <<b2.use_count() << endl;
    }
    
    cout << "Exited the scope" << endl;
    cout << b2->GetTitle() << endl;
    cout << "use count outside the scope: " <<b2.use_count() << endl;
    return 0;
}
