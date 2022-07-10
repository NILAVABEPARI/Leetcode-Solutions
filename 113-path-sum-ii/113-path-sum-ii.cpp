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
    void f(TreeNode *root, int ts, vector<int>&ds, vector<vector<int>>&ans){
        if(!root) return;
        ds.push_back(root->val);
        if(isLeaf(root) && root->val==ts){
            ans.push_back(ds);
            ds.pop_back();
            return;
        }
        f(root->left,ts-root->val,ds,ans);
        f(root->right,ts-root->val,ds,ans);
        ds.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>ds;
        f(root,targetSum,ds,ans);
        return ans;
    }
};