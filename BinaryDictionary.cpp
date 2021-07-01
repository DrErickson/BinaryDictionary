
#include "BinaryDictionary.h"



BinaryDictionary::BinaryDictionary() {
    root = new Node;
    numValues = 0;
}

BinaryDictionary::BinaryDictionary(const BinaryDictionary &otherDict) {
    root = new Node;
    numValues = 0;
}

BinaryDictionary::~BinaryDictionary() {
    DestroyHelper(root);
}

void BinaryDictionary::DestroyHelper(Node *node) {
    if (node == nullptr)
        return;

    DestroyHelper(node->zero);
    DestroyHelper(node->one);
    delete node;
}

// This saves all of the binary values in the dictionary into a file.
// This mainly serves as a wrapper for the SaveDictionaryHelper.
void BinaryDictionary::SaveDictionary(string filename) {
    ofstream dictFile;
    dictFile.open(filename);

    // Notice we start with the empty string as the prefix.
    SaveDictionaryHelper(root, "", dictFile);
}

void BinaryDictionary::SaveDictionaryHelper(Node *node, string currPrefix, ofstream& outFile) {
    if (node == nullptr)
        return;

    // If the path to this node is a number, then we write it
    // to the file.
    if (node->isNum) {
        outFile << currPrefix << endl;
    }

    // Notice how we add a digit to the currPrefix
    SaveDictionaryHelper(node->zero, currPrefix+"0", outFile);
    SaveDictionaryHelper(node->one, currPrefix+"1", outFile);
}


void BinaryDictionary::Add(string digits) {

    // Start at the root
    Node* curr = root;

    // For each digit in the binary string...
    for (int i = 0; i < digits.size(); i++) {

        // Pick which digit branch to go to.
        if (digits[i] == '0') {
            if (curr->zero == nullptr)
                curr->zero = new Node;
            curr = curr->zero;
        }
        else if (digits[i] == '1') {
            if (curr->one == nullptr)
                curr->one = new Node;
            curr = curr->one;
        }
        else{
            throw "Bad digit";
        }
    }
    curr->isNum = true;
    numValues++;
}


bool BinaryDictionary::Contains(string digits) {

    // Start at the root
    Node* curr = root;

    // For each digit in the binary string...
    for (int i = 0; i < digits.size(); i++) {

        // If we run into a null, then we know this
        // binary string doesn't exist in the dictionary
        if (curr == nullptr) {
            return false;
        }

        // Pick which digit branch to go to.
        if (digits[i] == '0') {
            curr = curr->zero;
        }
        else if (digits[i] == '1') {
            curr = curr->one;
        }
        else{
            throw "Bad digit";
        }
    }

    return curr->isNum;
}


int BinaryDictionary::Size() {
    return numValues;
}


BinaryDictionary& BinaryDictionary::operator=(const BinaryDictionary &otherDict) {

    CopyHelper(root, otherDict.root);
    numValues = otherDict.numValues;

    return *this;
}


void BinaryDictionary::CopyHelper(BinaryDictionary::Node*& thisDict, BinaryDictionary::Node *otherDict) {
    if (otherDict == nullptr) {
        thisDict = nullptr;
        return;
    }

    thisDict = new Node;
    thisDict->isNum = otherDict->isNum;
    CopyHelper(thisDict->zero, otherDict->zero);
    CopyHelper(thisDict->one, otherDict->one);
}








