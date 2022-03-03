#include "TrieNode.h"
#include <string>
using namespace std;
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertWord(TrieNode *root, string word)
    {
        // base call
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        // small calculations
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertWord(root, word);
    }

    bool search(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal)
                return true;
            else
                return false;
        }

        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            return false;
        }
        return search(child, word.substr(1));
    }
    bool search(string word)
    {
        return search(root, word);
    }
    void removeWord(TrieNode *root, string word)
    {
        // base call
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }
        // small calculations
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            // word not found
            return;
        }
        // Recursive call
        removeWord(child, word.substr(1));

        // Remove child Node if it is useless
        if (child->isTerminal == false)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->children[i] != NULL)
                    return;
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeWord(string word)
    {
        removeWord(root, word);
    }
};