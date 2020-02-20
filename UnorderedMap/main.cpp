//
//  main.cpp
//  UnorderedMap
//
//  Created by Iqbal Khan on 2/19/20.
//  Copyright © 2020 Iqbal Khan. All rights reserved.
//

#include <iostream>
#include <unordered_map>
#include <string>
#include <stdio.h>
#include <unordered_set>

using namespace std;

int main(int argc, const char * argv[]) {
    unordered_map<string, string> months;
    unordered_set<string> names;
    names.insert("James");
    names.insert("Bond");
    
    auto itr = names.find("Subul");
    if (itr != names.end()){
        cout << "Found it! " << *itr << endl;
    }
    
    //Adding elements to our map
    months["1"] = "January";
    months["2"] = "February";
    months["3"] = "March";
    months["4"] = "April";
    months["5"] = "May";
    //Looking to see if an element is in
    //the map:
    while (true){
        cout << "Enter string you're looking for or press q to quit: " << endl;
        string input;
        cin >> input;
        if (input == "q"){
            break;
        }
        //Initializing an iterator
        unordered_map<string, string>::iterator itr = months.find(input);
        //If itr is not at end of unordered_map
        if (itr != months.end()){
            //Means item found: print it
            cout << "Found: " << itr->first << " --> " << itr->second << endl;
        } else {
            cout << input << " key not found." << endl;
        }
    }
    //Iterating over all elements in the hash table.
    for (auto &m : months){
        cout <<"Month number " <<m.first << " is " << m.second << endl;
    }
    
    return 0;
}
