/*
 * @lc app=leetcode id=314 lang=cpp
 */
// @lc code=start
class Solution {
  public:
    vector<vector<int>> verticalOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }
        map<int, vector<int>> map;
        queue<pair<int, TreeNode *>> queue;
        queue.push(make_pair(5000, root));
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                auto tmp = queue.front();
                queue.pop();
                int col = tmp.first;
                map[col].push_back(tmp.second->val);
                if (tmp.second->left) {
                    queue.push(make_pair(col - 1, tmp.second->left));
                }
                if (tmp.second->right) {
                    queue.push(make_pair(col + 1, tmp.second->right));
                }
            }
        }
        for (auto const &m : map) {
            res.push_back(m.second);
        }
        return res;
    }
};
// @lc code=end
