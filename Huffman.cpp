using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include "BinaryTree.h"

vector<string> readInFile(){
    vector<string> vectorToRetun;
    fstream MyFile("FileToReadIn.txt");

    string readFromFile;
    for (int i = 0; i < 3; i++) {
        getline(MyFile, readFromFile);
        vectorToRetun.push_back(readFromFile);
    }

    //Closing file
    MyFile.close();


    return vectorToRetun;

}

int main() {
    //Call read in file function
    vector<string> vectorToPrint = readInFile();
    //Print out the vector
    for (int i = 0; i < vectorToPrint.size(); i++) {
        cout << vectorToPrint[i] << endl;
    }
}



int frequency() {
	//finding the frequency of each letter
}

string huffman() {
	//creating the tree of nodes for the original huffman algorithm

}

string letterPair() {
	//creating the tree of nodes for the letter pair algorithm

}