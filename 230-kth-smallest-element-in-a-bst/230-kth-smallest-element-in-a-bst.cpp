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
    //brute force 
    /*void recur(TreeNode *root, vector<int>&v){
        if(root){
            recur(root->left,v);
            v.push_back(root->val);
            recur(root->right,v);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int>v;
        //v.push_back(root->val);
        recur(root,v);
        sort(v.begin(),v.end());
        return v[k-1];
            
    }*/
    
    
    
    //iterative traversal (inorder)
    // int kthSmallest(TreeNode* root, int k) {
    //     stack<TreeNode*>st;
    //     TreeNode *temp=root;
    //     int cnt=0;
    //     while(true){
    //         if(temp){
    //             st.push(temp);
    //             temp=temp->left;
    //         }
    //         else{
    //             if(st.empty()) break;
    //             temp=st.top();
    //             st.pop();
    //             cnt++;
    //             if(cnt==k)
    //                 return temp->val;
    //             temp=temp->right;
    //         }
    //     }
    //     return -1;
    // } 
    
    
    //morris traversal
    int kthSmallest(TreeNode* root, int k) {
        TreeNode *curr=root;
        int cnt=0,ans;
        while(curr){
            if(!curr->left){
                cnt++; cout<<cnt<<" ";
                if(cnt==k) ans=curr->val;
                curr=curr->right;
            }else{                
                TreeNode *prev=curr->left;
                while(prev->right!=NULL && prev->right!=curr)
                    prev=prev->right;               
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    cnt++; cout<<cnt<<" ";
                    if(cnt==k) ans=curr->val;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};