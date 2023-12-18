//question 8 
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    // Create and write to input file
    ofstream createInputFile("input.txt");
    createInputFile << "This is a sample." << endl;
    createInputFile.close();

    // Input file
    ifstream inputFile("input.txt");

    // Output file
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }

    char ch;
    int charCount = 0;

    while (inputFile.get(ch)) {
        if (!isspace(ch)) {  // Exclude whitespace characters (newline, space, etc.)
            outputFile.put(ch);
            charCount++;
        }
    }

    // Close files
    inputFile.close();
    outputFile.close();

    cout << "Number of visible characters copied: " << charCount << endl;

    return 0;
}
