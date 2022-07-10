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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(isLeaf(root) && targetSum==root->val) return true;        
        bool l=hasPathSum(root->left,targetSum-root->val);
        if(l) return true;  
        bool r=hasPathSum(root->right,targetSum-root->val);
        if(r) return true;
        return l or r;
    }
};