//
// Created by Ben Worthington on 2/22/21.
//

#ifndef PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H
#define PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H

#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
using namespace std;

const int NUM_OF_WORDS = 1000;
const char COMMON_PUNCTUATION[5] = {'.', ',', ';', '?', '!'};

class Dictionary {
public:
    Dictionary();
    ~Dictionary();

    void ReadFile(string &name_);
    void WriteFile(string &outputFileName_, string &value_);
    void CreateAbriged();
    void MakeLowercase(string &word_);
    bool IsCapital(string &word_);
    bool HasPunctuation(string &word_);
    int BinarySearch(string &value_, int low_, int high_);
    int Lookup(string value_);

    static void Test();

private:
    int count;
    string word[NUM_OF_WORDS];
};


#endif //PF2_PROGRAMMING_PROJECT_3_DICTIONARY_H
