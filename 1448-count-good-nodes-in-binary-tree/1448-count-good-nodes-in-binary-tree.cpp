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
    void f(TreeNode *root, int &cnt, int maxi){
        if(!root) return;
        if(root->val>=maxi) cnt++;
        f(root->left,cnt,max(maxi,root->val));
        f(root->right,cnt,max(maxi,root->val));
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        f(root,cnt,INT_MIN);
        return cnt;
    }
};