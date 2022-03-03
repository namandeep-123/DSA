#include <iostream>
#include "Trie.h"
using namespace std;

int main()
{
    Trie T;
    T.insertWord("abc");
    T.insertWord("and");
    T.insertWord("are");

    cout << T.search("abc") << endl;
    T.removeWord("abc");
    cout << T.search("abc");
}