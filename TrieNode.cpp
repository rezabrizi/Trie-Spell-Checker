/*
 * TrieNode.cpp
 *
 *  Created on: Nov 21, 2021
 *      Author: rezatabrizi
 */
#include <string>
#include "TrieNode.h"
#include <iostream>
using namespace std;

	//Constructor of the TrieNode for the 26 letters of the alphabet
TrieNode::TrieNode() {
	for (int i = 0; i<27; i++){
		next[i] = nullptr;
	}
}

	// Checks whether the the TrieNode has children returning true or false
bool TrieNode::hasChildren(){
	bool hasC = false;
	for (int i = 0; i<27; i++){
		if (next[i]!= nullptr)
			hasC = true;
	}
	return hasC;
}

    // Set the '$' pointer to a valid non-null address
void TrieNode::setAsLeaf(){
	next[26] = new TrieNode;
}

    // Set the '$' pointer to null
void TrieNode::setAsInteriorNode(){
	delete next[26];
	next [26] = nullptr;
}

    // Returns true if the '$' pointer is not-null
bool TrieNode::isLeaf(){
	if (next[26] != nullptr)
		return true;
	return false;
}


