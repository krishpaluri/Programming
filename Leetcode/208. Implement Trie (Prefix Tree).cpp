class Trie {
public:

    struct TrieNode
    {
      unordered_map<char,TrieNode*> children;
      bool isEndOfWord;
      TrieNode() : isEndOfWord(false) {}
    };

    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *cur = root,*temp;
        for(char c : word)
        {
            if(cur->children[c] == NULL)
            {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEndOfWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *cur = root;

        for(char c:word)
        {
            if(cur != NULL and cur->children[c] != NULL)
                cur = cur->children[c];
            else
                return false;
        }
        return cur->isEndOfWord;

    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
                TrieNode *cur = root;

        for(char c:prefix)
        {
            if(cur != NULL and cur->children[c] != NULL)
                cur = cur->children[c];
            else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
