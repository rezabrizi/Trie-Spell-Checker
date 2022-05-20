/*
 * Trie.cpp
 *
 *  Created on: Nov 21, 2021
 *      Author: rezatabrizi
 */

#include "Trie.h"
#include <iostream>
#include <cctype>
using namespace std;

	//Constructor making the root as a new TrieNode
Trie::Trie() {
	root = new TrieNode();

}


// Returns true if the trie is empty, false otherwise
// Checks if the root has any children
bool Trie::isEmpty(){
    if (root->hasChildren())
        return true;
    return false;
}

// Inserts the word into the trie, and returns the status
// (e.g. fail the operation if the word has any non-alphabetical
// letter)
// If the word has non alphabetical characters then it returns false
bool Trie::insert(string word){
    for (int i =0; i<word.length(); i++)
    {
        if (!isalpha(word[i]))
        {
           return false;
        }
    }

    TrieNode* temp = root;
    int index;
    for (int i = 0; i < word.length(); i++)
    {
        index = word[i] - 'a';
        if (temp->next[index] == nullptr)
        {
            temp->next[index] = new TrieNode;
        }
        temp = temp->next[index];
    }
    if (!temp->isLeaf())
        temp->setAsLeaf();
    return true;
}

// Removes the word from the trie, and returns the status
bool Trie::remove(string word){
    return RecRemove (root, word, 0);
}

bool Trie::RecRemove (TrieNode* temp, string str, int charIndex){
    if (charIndex == str.length())
    {
    if (temp -> isLeaf())
        {
            temp->setAsInteriorNode();
            return true;
        }
        return false;
    }
    int index = str[charIndex] - 'a';
    if (temp->next[index] == nullptr){
        return false;
    }
    TrieNode* child = temp->next[index];
    RecRemove (child, str, charIndex+1);
    if (!child->hasChildren())
    {
        delete child;
        temp->next[index] = nullptr;
    }
    return true;
}
// Returns true if the word is present in the trie, false otherwise
bool Trie::search(string word){
    TrieNode* temp = root;
    int index;
    for (int i =0; i<word.length(); i++)
    {
        index = word[i] - 'a';
        temp = temp->next[index];
        if (temp == nullptr)
            return false;
    }

    if(temp->isLeaf())
        return true;
    else
        return false;
}

// Displays all the words currently in the trie
void Trie::displayWordList(){
    char str [26];
    RecDisplay(root, str, 0);
}

void Trie::RecDisplay(TrieNode* root, char str[], int level){
    if (root->isLeaf())
    {
        str[level] = '\0';
        cout << str << endl;
    }

    int i;
    for (i = 0; i < 26; i++)
    {
        // if NON NULL child is found
        // add parent key to str and
        // call the display function recursively
        // for child node
        if (root->next[i])
        {
            str[level] = i + 'a';
            RecDisplay(root->next[i], str, level + 1);
        }
    }
}


