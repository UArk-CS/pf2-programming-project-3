//
// Created by Ben Worthington on 2/22/21.
//

#include "Dictionary.h"

Dictionary::Dictionary() {
    // Initialize word array
    count = 0;
    for (int i = 0; i < NUM_OF_WORDS; i++)
        word[i] = "";
}

Dictionary::~Dictionary() {
}


void Dictionary::ReadFile(string &name_) {
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

void Dictionary::WriteFile(string &outputFileName_, string &value_) {

    ofstream dout;
    dout.open(outputFileName_, ofstream::app);
    if (dout.fail()) {
        return;
    }

    if (dout.is_open()) {
        dout << value_;
        dout.close();
    }

}

void Dictionary::CreateAbriged(string &bookName_, string &abridgedBookName_) {

    string printStr;
    string lookupStr;

    ifstream din;
    din.open(bookName_);
    if (din.fail()) {
        return;
    }

    if (din.is_open()) {

        din >> printStr;
        while (!din.eof()) {


        }

        din.close();

    }

}

void Dictionary::MakeLowercase(string &word_) {
    transform(word_.begin(), word_.end(), word_.begin(), ::tolower);
}

bool Dictionary::IsCapital(string &word_) {

    if (isupper(word_[0])) {
        return true;
    } else {
        return false;
    }

}

void Dictionary::RemovePunctuation(string &lookupStr_, string &printStr_) {

    int strLength = lookupStr_.length();
    char lastChar = lookupStr_[strLength - 1];
    bool isCommonPunc = false;

    if (('A' <= lastChar && lastChar <= 'Z') || ('a' <= lastChar && lastChar <= 'z')) {
        return;
    } else {

        for (int i = 0; i < NUM_OF_PUNCTUATION; i++) {

            if (lastChar == COMMON_PUNCTUATION[i]) {
                isCommonPunc = true;
            }

        }

        if (isCommonPunc) {
            // delete punc from lookupStr_
            lookupStr_.erase(strLength - 1);
        } else {
            lookupStr_.erase(strLength - 1);
            printStr_.erase(strLength - 1);
        }

    }

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

}

int Dictionary::Lookup(string value_) {

    return BinarySearch(value_, 0, count - 1);

}

void Dictionary::Test() {

    Dictionary test;
    string word;
    string file = "top1000.txt";

    test.ReadFile(file);

//    cout << "Enter a word: > ";
//    cin >> word;
//    transform(word.begin(), word.end(), word.begin(), ::tolower);

//    cout << "Location in Dictionary: " << test.Lookup(word) << endl;

    string lookup = "hello.";
    string print = "hello.";

    test.RemovePunctuation(lookup, print);
    cout << "Lookup " << lookup << endl;
    cout << "Print " << print << endl;

}