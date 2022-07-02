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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map < int, map < int, multiset < int >>> mp; // vertical level values
        queue < pair < TreeNode * , pair < int, int >>> q;  // node vertical level
        q.push({root,{0,0}}); //root vertical and level
        while (!q.empty()) {
            auto p = q.front();  q.pop();
            //p->{node, {vertical, level}}
            TreeNode * node = p.first;
            int vertical = p.second.first, level = p.second.second;
            mp[vertical][level].insert(node -> val); //inserting to multiset
            if (node -> left) 
                q.push({node -> left,{vertical - 1,level + 1}});
            if (node -> right) 
                q.push({node -> right,{vertical + 1,level + 1}});
        }
        vector < vector < int >> ans;
        for (auto &p: mp) {
            //p->{vertical, {level, values}}
            vector < int > col; //store values in each vertical
            for (auto &vertical: p.second) 
                //vertical->{level, values}
                //there can be multiple values on the same level
                col.insert(col.end(), vertical.second.begin(), vertical.second.end());
            ans.push_back(col);
        }
        return ans;
    }
};