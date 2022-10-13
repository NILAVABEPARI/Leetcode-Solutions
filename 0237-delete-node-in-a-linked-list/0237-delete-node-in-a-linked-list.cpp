/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //brute force
        // while(node->next){
        //     node->val=node->next->val;
        //     if(!node->next->next)
        //         node->next=NULL;                
        //     else node=node->next;
        // }
        
        
        //best approach
        node->val=node->next->val;
        node->next=node->next->next;
    }
};