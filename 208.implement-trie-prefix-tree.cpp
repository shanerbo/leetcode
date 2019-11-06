/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (41.54%)
 * Likes:    2008
 * Dislikes: 36
 * Total Accepted:    215.1K
 * Total Submissions: 515.5K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */

// @lc code=start
class Trie {
  private:
    struct TrieNode {
        vector<TrieNode *> child;
        char val;
        bool end;
        TrieNode() : end(false), child(26, nullptr){};
    };
    TrieNode *root;

  public:
    /** Initialize your data structure here. */
    Trie() {
        this->root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        auto *tmp = this->root;
        for (int i = 0; i < word.length(); i++) {
            if (tmp->child[word[i] - 'a'] == nullptr) {
                TrieNode *node = new TrieNode();
                node->val = word[i];
                tmp->child[word[i] - 'a'] = node;
            }
            tmp = tmp->child[word[i] - 'a'];
        }
        tmp->end = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto *tmp = this->root;
        for (int i = 0; i < word.length(); i++) {
            if (tmp->child[word[i] - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->child[word[i] - 'a'];
        }
        return tmp->end;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto *tmp = this->root;
        for (int i = 0; i < prefix.length(); i++) {
            if (tmp->child[prefix[i] - 'a'] == nullptr) {
                return false;
            }
            tmp = tmp->child[prefix[i] - 'a'];
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
// @lc code=end
