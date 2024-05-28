#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Creating and writing to the output file
    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Error: Unable to create output file." << endl;
        return 1;
    }

    // Writing information to the output file
    outFile << "Hello, world!" << endl;
    outFile << "This is a C++ program." << endl;
    outFile << "Writing to a file is fun." << endl;

    // Closing the output file
    outFile.close();

    // Reopening the file as an input file and reading the information
    ifstream inFile("output.txt");
    if (!inFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    cout << "Contents of the file:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    // Closing the input file
    inFile.close();

    return 0;
}

