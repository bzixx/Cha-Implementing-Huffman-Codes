using namespace std;
#include <iostream>
#include <vector>
#include <fstream>

string readInFile(){
    vector<string> vectorToRetun;
    string file_contents;
    fstream MyFile("FileToReadIn.txt");

    string readFromFile;
    for (int i = 0; i < 3; i++) {
        getline(MyFile, readFromFile);
        vectorToRetun.push_back(readFromFile);

        while (getline(MyFile, readFromFile)) {
            file_contents += readFromFile;
            file_contents.push_back('\n');
        }
    }

    //Closing file
    MyFile.close();

    return file_contents;
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
    string stringToPrint = readInFile();
    //Print out the vector
    for (int i = 0; i < stringToPrint.length(); i++) {
        cout << stringToPrint[i] << endl;
        vector<int> counts = countLettersIgnoreCase(stringToPrint);

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