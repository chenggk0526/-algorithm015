class Trie {
    struct TrieNode {
        map<char, TrieNode*> child_table;
        int end;
        TrieNode() : end(0) {}
    };
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        for (auto i : word) {
            if (curr->child_table.count(i) == 0) {
                curr->child_table[i] = new TrieNode();
            }
            curr = curr->child_table[i];
        }
        curr->end = 1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        return find(word, 1);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return find(prefix, 0);
    }
private:
    TrieNode* root;
    bool find(string s, int exact_match) {
        TrieNode* curr = root;
        for (auto i : s) {
            if (curr->child_table.count(i) == 0) return false;
            else curr = curr->child_table[i];
        }
        if (exact_match) return curr->end ? true : false;
        else return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */