/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isLeaf(TreeNode *root){
        return !root->left && !root->right;
    }
    int md(TreeNode *root){
        if(!root) return INT_MAX;
        if(isLeaf(root)) return 1;
        int lh=md(root->left);
        int rh=md(root->right);
        return 1+min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return md(root);
    }
};