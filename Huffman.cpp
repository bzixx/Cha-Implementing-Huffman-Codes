// Created by AuGust Ringelstetter & Jack Decker on April 26, 2025 around 11AM.
// This is a Pair challenege assignment for CS 354 at the University of Wisconsin - Stout.


//Standard Imports and Libraries
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
#include <map>

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


void doOutput(map<char, string> EncodedList, string inputMessage) {
    ofstream outputFile;
    outputFile.open("EncodedOutput.txt");

    if (outputFile.is_open()) {
        
        outputFile << "Encoded Output" << endl;
        outputFile << "----------------" << endl;

        for(pair<char, string> curr : EncodedList) {
            //outputs each letter and its encoding
            outputFile << curr.first << ": " << curr.second << endl;
        }

        outputFile << "----------------" << endl;
        outputFile << "Full Encoded message:";
        for(char ch : inputMessage) {
            if (isalpha(ch)) {
                outputFile << EncodedList[ch];
            }
        }

    } else {
        cout << "Unable to open file";
    }

    outputFile.close();
}

void findEncoding(TreeNode* currentNode, string path, map<char, string>& EncodedList) {
    if (currentNode == NULL) {
        return;
    }

    //Checking if its a leaf node
    if (currentNode->left == NULL && currentNode->right == NULL) {
        EncodedList[currentNode->NodeChar] = path;
    }

    //recursively calling the function while adding the current code to the path variable for each letter
    findEncoding(currentNode->left, path + "1", EncodedList);
    findEncoding(currentNode->right, path + "0", EncodedList);
}

void buildTree(priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeCompare>& pqueue) {
    TreeNode* node1 = pqueue.top();
    pqueue.pop();

    TreeNode* node2 = pqueue.top();
    pqueue.pop();

    int totalVal = node1->NodeFrequency + node2->NodeFrequency;

    pqueue.push(newCombineNode(totalVal, node1, node2));
}


void huffman() {
	//creating the tree of nodes for the original huffman algorithm
    string OGFileString = readInFile();
    vector<pair<int, char>> OGStringFrequency = letterFrequency(OGFileString);
    map<char, string> EncodingList;    

    //create a priority queue
    priority_queue<TreeNode*, vector<TreeNode*>, TreeNodeCompare> max_priority_queue;


    for (pair<int, char> n : OGStringFrequency) {
        //If the letter has a frequency greater than zero,
        //add it to the priority queue
        if (n.first > 0) {
            max_priority_queue.push(newNode(n.first, n.second));
        }
    }

    while (max_priority_queue.size() > 1) {
        buildTree(max_priority_queue);
    }

    TreeNode* root = max_priority_queue.top();
    findEncoding(root, "", EncodingList);

    doOutput(EncodingList, OGFileString);

    //MEETING WITH ALEXI NOTES

    //Need to find a way to do tree traversal to get the encodings
    //Tree traversal can look at the left and right children of the node and keep a current variable that can be appended to and then once the actuial node 
    //is found, then have to store the encoding in the list. 
    //Finally print the encoding and then print the ecoded version and the key to the encoding.
    //Rewrite the orginal file in encoded format, and also print out the key to the encoding.
    //Key and the encoded file in the same file. 
    
    //MEETING WITH ALEXI NOTES
}

int main() {
    huffman();
}