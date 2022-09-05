/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>v;
        queue<Node*>q;
        if(!root) return v;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n=q.size();
            for(int i=1;i<=n;i++){            
                Node *curr=q.front(); q.pop();
                temp.push_back(curr->val);
                int len=curr->children.size();
                for(int i=0;i<len;i++){
                    if(curr->children[i])
                        q.push(curr->children[i]);
                }
            }
            v.push_back(temp);
        }        
        return v;
    }
};