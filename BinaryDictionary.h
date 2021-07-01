//
// Author: Varick Erickson
// Date: 2/18/2021
//

#ifndef TREET_H
#define TREET_H

#include <string>
#include <fstream>
using namespace std;



class BinaryDictionary {
public:
    BinaryDictionary();
    ~BinaryDictionary();
    BinaryDictionary(const BinaryDictionary& otherDict);  // copy constructor

    void SaveDictionary(string filename);

    BinaryDictionary& operator=(const BinaryDictionary& otherDict);

    void Add(string binValue);    // Add value to the tree
    bool Contains(string value);  // Determines if value is in the tree

    int Size();     // Number of binary values

private:
    struct Node {
        Node* zero = nullptr;
        Node* one = nullptr;
        bool isNum = false;
    };

    Node* root;
    int numValues;

    // Used for de-constructor
    void DestroyHelper(Node* node);
    void CopyHelper(Node*& thisTree, Node* otherTree);
    void SaveDictionaryHelper(Node* node, string currPrefix, ofstream& outFile);

};

#endif //TREET_H
