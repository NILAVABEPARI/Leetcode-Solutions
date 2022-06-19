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
    //recursive solution 
//     bool recur(TreeNode *left, TreeNode *right){
//         if(!left || !right)
//             return (left==right);
//         if(left->val != right->val)
//             return false;        
//         return recur(left->left,right->right) && 
//             recur(left->right,right->left);
//     }    
//     bool isSymmetric(TreeNode* root) {
//         if(!root) return true;
//         return recur(root->left,root->right);
//     }
        
        
    //iterative solution 
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        TreeNode *left,*right;
        queue<TreeNode*> q1,q2;
        q1.push(root->left);
        q2.push(root->right);        
        while(!q1.empty() && !q2.empty()){
            left=q1.front(); q1.pop();
            right=q2.front(); q2.pop();            
            if (NULL == left && NULL == right) continue;
            if (NULL == left || NULL == right) return false;
            if(left->val != right->val) return false;
            q1.push(left->left); q2.push(right->right);
            q1.push(left->right); q2.push(right->left);
        }
        return true;
    }
};