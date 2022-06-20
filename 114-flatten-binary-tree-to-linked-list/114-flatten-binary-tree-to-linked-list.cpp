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

//itereative using stack
// class Solution {
// public:    
//     void flatten(TreeNode* root) {
//         if(!root) return;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode *curr=st.top();
//             st.pop();
//             if(curr->right)
//                 st.push(curr->right);            
//             if(curr->left)
//                 st.push(curr->left); 
//             if(!st.empty())
//                 curr->right=st.top();
//             curr->left=NULL;            
//         }      
//     }
// };



//recursive
// class Solution {
// private:
//     TreeNode *prev=NULL;
// public:    
//     void flatten(TreeNode* root) {
//         if(!root) return;        
//         flatten(root->right);
//         flatten(root->left);        
//         root->right=prev;
//         root->left=NULL;
//         prev=root;
//     }
// };




//morris traversal
class Solution {
  TreeNode * prev = NULL;
  public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
		while (cur){
			if(cur->left){
				TreeNode* pre = cur->left;
				while(pre->right)
					pre = pre->right;				
				pre->right = cur->right;
				cur->right = cur->left;
				cur->left = NULL;
			}
			cur = cur->right;
		}
    }
};