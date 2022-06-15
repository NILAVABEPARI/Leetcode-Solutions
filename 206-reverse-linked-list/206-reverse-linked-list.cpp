/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head, *prev_ptr=NULL;
        while(curr!=NULL){
            ListNode *next_ptr=curr->next;
            curr->next=prev_ptr;
            prev_ptr=curr;
            curr=next_ptr;
        }
        return prev_ptr;
    }
};