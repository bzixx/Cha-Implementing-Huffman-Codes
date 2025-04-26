using namespace std;
#include <iostream>
#include <vector>
#include <fstream>

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

// Function to count occurrences of each letter (ignoring case)
vector<int> countLettersIgnoreCase(const string& str) {
    vector<int> buckets(26, 0);

    for (char ch : str) {
        if (isalpha(ch)) {
            buckets[tolower(ch) - 'a']++;
        }
    }

    return buckets; // Returning the count vector
}

// vector<string> splitIntoWords(){
//     vector<string> vectorToRetun;
//     vector<string> linesVector = readInFile();
    
//     for (int i = 0; i < linesVector.size(); i++) {
//         lines

//     }

//     return vectorToRetun;
// }


int main() {
    //Call read in file function
    vector<string> vectorToPrint = readInFile();
    //Print out the vector
    for (int i = 0; i < vectorToPrint.size(); i++) {
        cout << vectorToPrint[i] << endl;
        vector<int> counts = countLettersIgnoreCase(vectorToPrint[i]);

            // Print the counts
        for (int i = 0; i < 26; ++i) {
            if (counts[i] > 0) {
                cout << static_cast<char>('a' + i) << ": " << counts[i] << endl;
            }
        }
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