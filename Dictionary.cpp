//
// Created by Ben Worthington on 2/22/21.
//

#include "Dictionary.h"

Dictionary::Dictionary()
{
    // Initialize word array
    count = 0;
    for (int i = 0; i < NUM_OF_WORDS; i++)
        word[i] = "";
}

Dictionary::~Dictionary()
{
}


void Dictionary::ReadFile(string name_)
{
    // Open input file
    ifstream din;
    din.open(name_.c_str());
    if (din.fail())
        return;

    // Read strings into word array
    count = 0;
    int num;
    string str;
    din >> num >> str;
    while (!din.eof() && count < NUM_OF_WORDS)
    {
        word[count++] = str;
        din >> num >> str;
    }
    din.close();
}

bool Dictionary::Lookup(string searchParam_)
{
    // Search word array for string
    bool found = false;
    for (int i = 0; i < count; i++)
        if (word[i] == searchParam_)
            found = true;
    return found;
}