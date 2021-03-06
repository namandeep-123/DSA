First you have to Insert all strings in reverse order, then search for each string , whether it forms a palindorme or not in Trie.


class Solution
{
public:
    // Trie Class
    class TrieNode
    {
    public:
        char data;
        TrieNode **children;
        int index;
        TrieNode(int data)
        {
            this->data = data;
            children = new TrieNode *[26];
            for (int i = 0; i < 26; i++)
            {
                children[i] = NULL;
            }
            index = -1;
        }
    };
    TrieNode *root;
    // Solution constructor to create root for Trie Class;
    Solution()
    {
        root = new TrieNode(' ');
    }
    void insertWord(TrieNode *root, string word, int i)
    {
        // base call
        if (word.size() == 0)
        {
            root->index = i;
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
        insertWord(child, word.substr(1), i);
    }

    void insertWord(string word, int i)
    {
        insertWord(root, word, i);
    }

    // find Function
    void find(TrieNode *root, vector<int> &palindromes, string s = "")
    {
        // base condition, if formed string is a palindrome or not.
        if (root->index != -1)
        {
            int i = 0, j = s.length() - 1;
            // cout<<s<<endl;
            bool flag = true;
            while (i <= j)
            {
                if (s[i] != s[j])
                {
                    flag = false;
                    break;
                }
                i++;
                j--;
            }
            if (flag)
                palindromes.push_back(root->index);
        }
        for (int i = 0; i < 26; i++)
        {
            if (root->children[i])
            {
                char c = 'a' + i;
                s.push_back(c);
                find(root->children[i], palindromes, s);
                s.pop_back();
            }
        }
        return;
    }
    // Search Function
    vector<int> search(TrieNode *root, string s)
    {
        vector<int> palindromes;
        TrieNode *ptr = root;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            int index = c - 'a';
            // If any strings ends here, then check if out left out string is palindrome or not.
            if (ptr->index != -1)
            {
                int j = i, k = s.length() - 1;
                bool flag = true;
                while (j <= k)
                {
                    if (s[j] != s[k])
                    {
                        flag = false;
                        break;
                    }
                    j++;
                    k--;
                }
                if (flag)
                    palindromes.push_back(ptr->index);
            }
            // If no characters ahead matching.
            if (!ptr->children[index])
            {
                return palindromes;
            }
            ptr = ptr->children[index];
        }
        find(ptr, palindromes);
        return palindromes;
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        int i = 0;
        for (string s : words)
        {
            reverse(s.begin(), s.end());
            insertWord(s, i++);
        }
        vector<vector<int>> answer;
        i = 0;
        for (string s : words)
        {
            // search for all palindromes.
            vector<int> palindromes = search(root, s);

            for (int a : palindromes)
            {
                if (i != a)
                {
                    answer.push_back({i, a});
                }
            }
            i++;
        }
        return answer;
    }
};