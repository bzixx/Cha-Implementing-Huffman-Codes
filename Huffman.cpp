// Created by AuGust Ringelstetter & Jack Decker on April 26, 2025 around 11AM.
// This is a Pair challenege assignment for CS 354 at the University of Wisconsin - Stout.


//QUESTIONS FOR ALEXI
//What does the decoding key mean?

//PREDICTIONS
//Worst case scenario letter-pair is the same as huffman codes, best case scenario, its better.

//Standard Imports and Libraries
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

struct TreeNode
{
	char NodeChar;
	int NodeFrequency;
    string NodeCode;
	TreeNode *left, *right;
};

struct TreeNodeCompare
{
    bool operator()(TreeNode* l, TreeNode* r)
    {
        return l->NodeFrequency > r->NodeFrequency;
    }
};

TreeNode* newNode(int f, char c)
{
    TreeNode* node = new TreeNode();

    node->NodeChar = c;
    node->NodeFrequency = f;
    node->NodeCode = "";
    node->left = node->right = NULL;

    return node;
}

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
vector<pair<int, char>> letterFrequency(const string& str) {
    vector<int> buckets(26, 0);

    for (char ch : str) {
        if (isalpha(ch)) {
            buckets[tolower(ch) - 'a']++;
        }
    }

    vector<pair<int, char>> mapmap;
    int i = 0;

    for (int count : buckets) {
        mapmap.push_back(make_pair(count, 'a' + i));
        i++;
    }

    return mapmap; // Returning the count vector
}

void huffman() {
	//creating the tree of nodes for the original huffman algorithm
    string OGFileString = readInFile();
    vector<pair<int, char>> OGStringFrequency = letterFrequency(OGFileString);

    //create a priority queue
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeCompare> max_priority_queue;



    for (pair<int, char> n : OGStringFrequency) {
        max_priority_queue.push(newNode(n.first, n.second));
    }

    cout << "Queue Produced:" ;
    for (; !max_priority_queue.empty(); max_priority_queue.pop()){
        cout << max_priority_queue.top()->NodeFrequency << " " << max_priority_queue.top()->NodeChar << endl;
    }


//loop
    //iterate through the priority queue

    //make a node for each letter

    //take the two lowest frequency nodes and add them
    //then make that added value a new parent node

    //insert that parent node into the priority queue

    //eventually we will have only one item in the p. queue
//exit loop

    //weight each right edge with 1, and each left edge with 0

    //create a code using the path from the root to the letter we're encoding
}


int main() {
    // //Call read in file function
    // string stringToPrint = readInFile();
    // //Print out the vector
    // cout << stringToPrint << endl;

    // vector<int> counts = letterFrequency(stringToPrint);
    
    // // Print the counts
    // for (int i = 0; i < 26; ++i) {
    //     if (counts[i] > 0) {
    //         cout << static_cast<char>('a' + i) << ": " << counts[i] << endl;
    //     }
    // }

    huffman();
}


string letterPair() {
	//Same as huffman but encoding certain common letter-pairs as their own "letters"

}