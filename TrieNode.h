/*
 * Trie.h
 *
 *  Course CS 2337.501
 *  Term: Fall 2021
 *  Author: Reza Aghazadeh Tabrizi
 *  Net ID: RXA200026
 */


#ifndef _TRIENODE_H_
#define _TRIENODE_H_
#include <string>

using namespace std;

struct TrieNode
{
    const static int CHAR_SIZE = 27;

    TrieNode ();

    // Returns true if the TrieNode has any children
    // (i.e. any of the A-Z pointers are not null)
    bool hasChildren();

    // Set the '$' pointer to a valid non-null address
    void setAsLeaf();

    // Set the '$' pointer to null
    void setAsInteriorNode();

    // Returns true if the '$' pointer is not-null
    bool isLeaf();

    TrieNode *next[CHAR_SIZE];
};
#endif // _TRIENODE_H_
