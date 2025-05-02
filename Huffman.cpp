// Created by AuGust Ringelstetter & Jack Decker on April 26, 2025 around 11AM.
// This is a Pair challenege assignment for CS 354 at the University of Wisconsin - Stout.


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

TreeNode* newCombineNode(int f, TreeNode* left, TreeNode* right)
{
    TreeNode* node = new TreeNode();

    node->NodeChar = NULL;
    node->NodeFrequency = f;
    node->NodeCode = "";
    node->left = left;
    node->right = right;

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


void doOutput(vector<pair<char, int>> EncodedList) {
    ofstream outputFile;
    outputFile.open("EncodedOutput.txt");

    if (outputFile.is_open()) {
        outputFile << "Encoded Output" << endl;
        outputFile << "----------------" << endl;

        for(pair<char, int> curr : EncodedList) {
            outputFile << curr.first << ": " << curr.second << endl;
        }
        // Write the encoded data here

    } else {
        cout << "Unable to open file";
    }

    outputFile.close();
}

int findEncoding(){
    //find the encoding for the letter
    //if the letter is in the left child, add a 0 to the encoding
    //if the letter is in the right child, add a 1 to the encoding
}

void buildTree(priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeCompare>& pqueue) {
    TreeNode* node1 = pqueue.top();

    TreeNode* node2 = pqueue.top();

    
}


void huffman() {
	//creating the tree of nodes for the original huffman algorithm
    string OGFileString = readInFile();
    vector<pair<int, char>> OGStringFrequency = letterFrequency(OGFileString);
    vector<pair<char, int>> EncodingList;

    EncodingList.push_back(make_pair('a', 0));

    //create a priority queue
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeCompare> max_priority_queue;



    for (pair<int, char> n : OGStringFrequency) {
        max_priority_queue.push(newNode(n.first, n.second));
    }

    cout << "Queue Produced:" ;
    for (; !max_priority_queue.empty(); max_priority_queue.pop()){
        cout << max_priority_queue.top()->NodeFrequency << " " << max_priority_queue.top()->NodeChar << endl;
    }


    doOutput(EncodingList);

    //MEETING WITH ALEXI NOTES

    //Need to generate a List to storew all the encodings. 
    //Need to find a way to do tree traversal to get the encodings
    //Tree traversal can look at the left and right children of the node and keep a current variable that can be appended to and then once the actuial node 
    //is found, then have to store the encoding in the list. 
    //Dont worry about the Two Character version at this point. 
    //Finally print the encoding and then print the ecoded version and the key to the encoding.
    //Rewrite the orginal file in encoded format, and also print out the key to the encoding.
    //Key and the encoded file in the same file. 
    
    //MEETING WITH ALEXI NOTES
}

int main() {
    huffman();
}