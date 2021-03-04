#include <iostream>
#include "AbridgeBook.h"

int main() {

    AbridgeBook shortBook;
    string dictionaryFile;
    string bookToRead;
    string outputFile;

    cout << "Welcome to Book Abridger! " << endl;
    cout << endl;

    cout << "Enter the name of the dictionary: > ";
    cin >> dictionaryFile;
    cout << endl;

    cout << "Enter the book to abridge: > ";
    cin >> bookToRead;
    cout << endl;

    cout << "Enter the name of the output file: > ";
    cin >> outputFile;
    cout << endl;

    cout << "Creating abridged book..." << endl;

    shortBook.ReadFile(dictionaryFile);
    shortBook.CreateAbriged(bookToRead, outputFile);

    cout << "Done! " << outputFile << " has been created!" << endl;

    return 0;

}
