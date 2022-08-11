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
#define inf 1e12 
class Solution {
public:
    bool check(TreeNode* root, long long int mini, long long int maxi){
        if(!root) return true;
        if(root->val <= mini || root->val >= maxi) return false;
        return check(root->left,mini,root->val) && check(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {  
        return check(root,-inf,inf);
    }
};


