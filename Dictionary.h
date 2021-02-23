//
// Created by Ben Worthington on 2/22/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H
#define PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int NUM_OF_WORDS = 1000;

class Dictionary {
public:
    Dictionary();
    ~Dictionary();

    void ReadFile(string name_);
    int BinarySearch(string &value_, int low_, int high_);
    int Lookup(string value_);

private:
    int count;
    string word[NUM_OF_WORDS];
};


#endif //PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H
