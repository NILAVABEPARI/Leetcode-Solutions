/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    //brute force  -- wrong code
    // bool f(TreeNode *root,TreeNode *node, vector<TreeNode*>&ans){
    //     if(!root) return false;
    //     ans.push_back(root);
    //     if(root->val == node->val) return true;
    //     if(f(root->left,node,ans) || f(root->right,node,ans))
    //         return true;
    //     ans.pop_back();
    //     return false;
    // }
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    //     vector<TreeNode*>path1,path2;
    //     f(root,p,path1);
    //     f(root,q,path2);
    //     int i=0,j=0;
    //     while(i<path1.size() && j<path2.size()){
    //         if(path1[i]!=path2[j])
    //             break;
    //         i++;j++;
    //     }
    //     return path1[i];    
    // }    
    
    //optimal
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q)   
            return root;
        
        TreeNode *left=lowestCommonAncestor(root->left,p,q);
        TreeNode *right=lowestCommonAncestor(root->right,p,q);
        
        if(!left && !right) return NULL;
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
};