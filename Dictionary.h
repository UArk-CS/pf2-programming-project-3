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
const int NUM_OF_RANKS = 1000;

class Dictionary {
public:
    Dictionary();
    ~Dictionary();

    void ReadFile(string &name_);
    void WriteFile(string &fileName_);
    void MakeLowercase(string &word_);

    bool IsCapital(char &singleChar_);
    bool IsTop1000Word(string &word);

    int BinarySearch(string &value_, int low_, int high_);
    int Lookup(string value_);

    static void Test();

private:
    int count;
    string word[NUM_OF_WORDS];
    int ranking[NUM_OF_RANKS];
};


#endif //PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H
