/*
 * @lc app=leetcode id=269 lang=cpp
*/
class Solution {
  public:
    string alienOrder(vector<string> &words) {
        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> incoming;
        string res;
        if (words.empty()) {
            return res;
        }
        for (auto const &w : words) {
            for (auto const &c : w) {
                incoming[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; ++i) {
            if (words[i] == words[i + 1])
                continue;
            if (words[i][0] == words[i + 1][0]) {
                int p = 1;
                while (words[i][p] == words[i + 1][p]) {
                    p++;
                }
                if (words[i][p] != '\0' && words[i + 1][p] != '\0') {
                    graph[words[i][p]].emplace_back(words[i + 1][p]);
                    incoming[words[i + 1][p]]++;
                }
            } else {
                graph[words[i][0]].emplace_back(words[i + 1][0]);
                incoming[words[i + 1][0]]++;
            }
        }
        queue<char> q;
        for (auto const &v : incoming) {
            if (v.second == 0) {
                q.push(v.first);
                res += v.first;
            }
        }
        while (!q.empty()) {
            char top = q.front();
            q.pop();
            auto charList = graph[top];
            for (auto const &c : charList) {
                incoming[c]--;
                if (incoming[c] == 0) {
                    q.push(c);
                    res += c;
                }
            }
        }
        return res.length() == incoming.size() ? res : "";
    }
}; // @lc code=end