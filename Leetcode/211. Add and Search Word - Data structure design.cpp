class WordDictionary {
public:
    struct TrieNode
    {
        map<char, TrieNode *> children;
        bool isWord;
        TrieNode() : isWord(false) {}
    };
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }

    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;

        for(char c: word)
        {
            if(cur->children[c] == NULL)
            {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isWord = true;
    }

    bool helper(string word, TrieNode *root)
    {
        if(root == NULL )
            return false;
        TrieNode *cur = root;
        for(int i=0;i<word.size();i++)
        {
            if(cur == NULL)
                return false;
            char c = word[i];
            if(word[i] == '.')
            {
                for(auto it = cur->children.begin();it!=cur->children.end();it++)
                {
                    string s = word.substr(i+1);
                    if(helper(s,it->second))
                        return true;
                }
                return false;
            }
            else
            {
              if(cur == NULL || cur->children[c] == NULL)
                  return false;
              cur = cur->children[c];
            }
        }
        return cur->isWord;
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return helper(word,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
