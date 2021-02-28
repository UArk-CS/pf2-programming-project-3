//
// Created by Ben Worthington on 2/22/21.
//

#include "Dictionary.h"
#include <iostream>
#include <algorithm>
using namespace std;

Dictionary::Dictionary() {
    // Initialize word array
    count = 0;
    for (int i = 0; i < NUM_OF_WORDS; i++)
        word[i] = "";
}

Dictionary::~Dictionary() {
}


void Dictionary::ReadFile(string name_) {
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

int Dictionary::BinarySearch(string &value_, int low_, int high_) {

    // Calculate midpoint index
    int midpoint = (low_ + high_) / 2;

    if (low_ > high_) {
        return -1;
    } else if (word[midpoint] == value_) {
        return midpoint;
    } else if (word[midpoint] > value_) {
        return BinarySearch(value_, low_, midpoint - 1);
    } else {
        return BinarySearch(value_, midpoint + 1, high_);
    }

//    return midpoint;

}

int Dictionary::Lookup(string value_) {

    return BinarySearch(value_, 0, count - 1);

}

void Dictionary::Test() {

    Dictionary test;
    string word;

    test.ReadFile("top1000.txt");

    cout << "Enter a word: > ";
    cin >> word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);

    cout << "Location in Dictionary: " << test.Lookup(word) << endl;

}