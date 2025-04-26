using namespace std;
#include <iostream>
#include <vector>
#include <fstream>

int main() {
	//Create and open the input file
	fstream MyFile("FileToReadIn.txt");

	//testing to see if we can read the file
	string readFromFile;
	getline(MyFile, readFromFile);

	//Closing file
	MyFile.close();

	cout << readFromFile;
	
	//call the huffman function

	//call the letterPair function
}

vector<string> readInFile(){
    vector<string> vectorToRetun;

    return vectorToRetun;

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