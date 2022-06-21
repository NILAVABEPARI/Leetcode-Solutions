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
    void inorder(TreeNode* root,TreeNode *&fm, TreeNode *&sm, TreeNode *&pre) {
		if(root == NULL) return;
		inorder(root->left,fm,sm,pre);
		if(fm == NULL && root->val < pre->val) fm = pre;
		if(fm != NULL && root->val < pre->val) sm = root;
		pre = root;
		inorder(root->right,fm,sm,pre);
	}
	void recoverTree(TreeNode* root) {
        TreeNode *fm=NULL, *sm=NULL, *pre;
		pre = new TreeNode(INT_MIN);
		inorder(root,fm,sm,pre);
		swap(fm->val, sm->val);
	}	
};