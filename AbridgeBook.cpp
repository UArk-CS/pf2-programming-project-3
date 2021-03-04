//
// Created by Ben Worthington on 2/22/21.
//

#include "AbridgeBook.h"

AbridgeBook::AbridgeBook() {
    // Initialize word array
    count = 0;
    for (int i = 0; i < NUM_OF_WORDS; i++)
        word[i] = "";
}

AbridgeBook::~AbridgeBook() {
}


void AbridgeBook::ReadFile(string &name_) {
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

void AbridgeBook::WriteFile(string &outputFileName_, string &value_, int &numOfWords_) {

    ofstream dout;
    dout.open(outputFileName_, ofstream::app);
    if (dout.fail()) {
        return;
    }

    if (dout.is_open()) {
        dout << value_ << " ";

        if (numOfWords_ == 10) {
            dout << "\n";
            numOfWords_ = 0;
        }

        dout.close();
    }

}

void AbridgeBook::CreateAbriged(string &bookName_, string &abridgedBookName_) {

    string printStr;
    string lookupStr;
    int numOfWords = 0;

    ifstream din;
    din.open(bookName_);
    if (din.fail()) {
        return;
    }

    if (din.is_open()) {

        din >> printStr;
        lookupStr = printStr;
        while (!din.eof()) {

            //remove punc
            RemovePunctuation(lookupStr, printStr);

            //check if capital
            //if it is, make lookupStr lowercase
            if (IsCapital(lookupStr)) {
                WriteFile(abridgedBookName_, printStr, numOfWords);
                numOfWords++;
            } else if (Lookup(lookupStr) != -1) {
                WriteFile(abridgedBookName_, printStr, numOfWords);
                numOfWords++;
            }

            //get next word
            din >> printStr;
            lookupStr = printStr;

        }

        din.close();

    }

}

void AbridgeBook::MakeLowercase(string &lookupStr_) {
    transform(lookupStr_.begin(), lookupStr_.end(), lookupStr_.begin(), ::tolower);
}

bool AbridgeBook::IsCapital(string &lookupStr_) {

    if (isupper(lookupStr_[0])) {
        return true;
    } else {
        return false;
    }

}

void AbridgeBook::RemovePunctuation(string &lookupStr_, string &printStr_) {

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

int AbridgeBook::BinarySearch(string &value_, int low_, int high_) {

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

int AbridgeBook::Lookup(string value_) {

    return BinarySearch(value_, 0, count - 1);

}