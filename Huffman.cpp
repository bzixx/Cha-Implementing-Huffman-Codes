// Created by AuGust Ringelstetter & Jack Decker on April 26, 2025 around 11AM.
// This is a Pair challenege assignment for CS 354 at the University of Wisconsin - Stout.

//Standard Imports and Libraries
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>

//Function to read in a file and place everything in the file into a string
string readInFile(){
    //vector<string> vectorToRetun;
    string file_contents;
    fstream MyFile("FileToReadIn.txt");

    string readFromFile;
    while (getline(MyFile, readFromFile)) {
        file_contents += readFromFile;
        file_contents.push_back('\n');
    }

    //Closing file
    MyFile.close();

    return file_contents;
}

// Function to count occurrences of each letter (ignoring case)
vector<int> letterFrequency(const string& str) {
    vector<int> buckets(26, 0);

    for (char ch : str) {
        if (isalpha(ch)) {
            buckets[tolower(ch) - 'a']++;
        }
    }

    return buckets; // Returning the count vector
}


int main() {
    //Call read in file function
    string stringToPrint = readInFile();
    //Print out the vector
    cout << stringToPrint << endl;

    vector<int> counts = letterFrequency(stringToPrint);
    
    // Print the counts
    for (int i = 0; i < 26; ++i) {
        if (counts[i] > 0) {
            cout << static_cast<char>('a' + i) << ": " << counts[i] << endl;
        }
    }
}


string huffman() {
	//creating the tree of nodes for the original huffman algorithm

}

string letterPair() {
	//creating the tree of nodes for the letter pair algorithm

}