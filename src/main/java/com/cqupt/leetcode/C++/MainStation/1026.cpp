#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int dfs(TreeNode* root, int maxVal, int minVal) {
        if (!root) return maxVal - minVal;
        maxVal = max(maxVal, root->val);
        minVal = min(minVal, root->val);
        return max(dfs(root->left, maxVal, minVal), dfs(root->right, maxVal, minVal));
    }

    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};