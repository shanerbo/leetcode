/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * @lc app=leetcode id=545 lang=cpp
 *
 *
 */
class Solution {
  public:
    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        res.push_back(root->val);
        vector<int> lefts, rights, leaves;
        left(root->left, lefts);
        right(root->right, rights);
        leaf(root->left, leaves);
        leaf(root->right, leaves);
        reverse(rights.begin(), rights.end());
        for (int i = 0; i < lefts.size(); ++i) {
            res.push_back(lefts[i]);
        }
        for (int i = 0; i < leaves.size(); ++i) {
            res.push_back(leaves[i]);
        }
        for (int i = 0; i < rights.size(); ++i) {
            res.push_back(rights[i]);
        }
        return res;
    }

  private:
    void left(TreeNode *root, vector<int> &lefts) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        lefts.push_back(root->val);
        if (root->left) {
            left(root->left, lefts);
        } else
            left(root->right, lefts);
    }
    void right(TreeNode *root, vector<int> &rights) {
        if (!root || (!root->left && !root->right)) {
            return;
        }
        rights.push_back(root->val);
        cout << root->val << endl;
        if (root->right) {
            right(root->right, rights);
        } else {
            right(root->left, rights);
        }
    }
    void leaf(TreeNode *root, vector<int> &leaves) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {
            leaves.push_back(root->val);
        }
        leaf(root->left, leaves);
        leaf(root->right, leaves);
    }
};