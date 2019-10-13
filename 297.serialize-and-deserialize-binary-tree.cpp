/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (42.92%)
 * Likes:    1960
 * Dislikes: 95
 * Total Accepted:    224.4K
 * Total Submissions: 522.4K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 * 
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 * 
 * Example: 
 * 
 * 
 * You may serialize the following tree:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * as "[1,2,3,null,null,4,5]"
 * 
 * 
 * Clarification: The above format is the same as how LeetCode serializes a
 * binary tree. You do not necessarily need to follow this format, so please be
 * creative and come up with different approaches yourself.
 * 
 * Note: Do not use class member/global/static variables to store states. Your
 * serialize and deserialize algorithms should be stateless.
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  private:
    void anti(TreeNode *root, queue<string> &q) {

        root->val = stoi(q.front());
        q.pop();
        if (q.front() == "x") {
            q.pop();
        } else {
            TreeNode *tmpL = new TreeNode(0);
            root->left = tmpL;
            anti(root->left, q);
        }
        if (q.front() == "x") {
            q.pop();
        } else {
            TreeNode *tmpR = new TreeNode(0);
            root->right = tmpR;
            anti(root->right, q);
        }
    }
    void generateQ(queue<string> &q, string s) {
        if (s.size() == 0) {
            return;
        } else {
            int p = s.find(' ');
            q.push(s.substr(0, p));
            generateQ(q, s.substr(p + 1)); // make sure there is no leading space
        }
    }

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) {
            return "x ";
        } else {
            return to_string(root->val) + ' ' + serialize(root->left) + serialize(root->right);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        if (data.length() == 0 || data[0] == 'x') {
            return nullptr;
        } else {
            TreeNode *root = new TreeNode(0);
            root->val;
            queue<string> q;
            generateQ(q, data);
            anti(root, q); // 0 for left
            return root;
        }
    }
};