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
    bool isValid(TreeNode *root,int target){
        return (!root->left && !root->right && root->val==target);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        TreeNode *left=removeLeafNodes(root->left,target);
        if(!left) root->left=left;
        TreeNode *right=removeLeafNodes(root->right,target);
        if(!right) root->right=right;
        if(isValid(root,target)) return NULL;
        else return root;
    }
};