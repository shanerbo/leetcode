#include <vector>

class Product {
  private:
    struct Node {
        vector<Node *> children;
        char c;
        bool endOfWord;
        Node() : endOfWord(false), children(26, nullptr){};
    };

  public:
    vector<vector<string>> RecommandProduct(int numOfProducts, vector<string> &repo, string query) {
        vector<vector<string>> res;
        if (numOfProducts == 0) {
            return res;
        }
        if (query.length() < 2) {
            return res;
        }
        Node *root = new Node();
        //create a root for trie
        for (auto const &p : repo) {
            Insert(root, p);
        }
        for (int i = 2; i < query.size(); ++i) {
            Node *tmp = root;
            string word = query.substr(0, i);
            vector<string> set;
            if (FindRoot(tmp, word)) {
                GetSuggestion(tmp, set, word);
                res.emplace_back(set);
            }
        }
        return res;
    }

  public:
    void Insert(Node *&root, string s) {
        Node *tmp = root;
        for (int i = 0; i < s.length(); ++i) {
            if (tmp->children[s[i] - 'a'] == nullptr) {
                Node *child = new Node();
                child->c = s[i];
                tmp->children[s[i] - 'a'] = child;
            }
            tmp = tmp->children[s[i] - 'a'];
        }
        tmp->endOfWord = true;
    }

    bool FindRoot(Node *&root, string query) {
        for (int i = 0; i < query.size(); ++i) {
            if (root->children[query[i] - 'a']) {
                root = root->children[query[i] - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }

    void GetSuggestion(Node *&root, vector<string> &res, string query) {
        Node *tmp = root;
        if (res.size() >= 3) {
            return;
        }
        for (int i = 0; i < 26; ++i) {
            if (root->children[i]) {
                if (root->children[i]->endOfWord) {
                    res.push_back(query + root->children[i]->c);
                    cout << query + root->children[i]->c << endl;
                }
                GetSuggestion(root->children[i], res, query + root->children[i]->c);
            }
        }
    }
};

int main() {
    Product p;
    vector<string> repo = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    auto res = p.RecommandProduct(10, repo, "mouse");
    for (auto const r : res) {
        for (auto const c : r) {
            cout << c << endl;
        }
    }
    return 0;
}