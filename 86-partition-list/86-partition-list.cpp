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
    ListNode* partition(ListNode* head, int x) {
        ListNode* sh=new ListNode(-1);
        ListNode* lh=new ListNode(-1);
        ListNode *sp=sh,*lp=lh,*curr=head;        
        while(curr){
            if(curr->val<x){
                sp->next=curr;
                sp=curr;
            }
            else{
                lp->next=curr;
                lp=curr;
            }
            curr=curr->next;
        }
        lp->next=NULL;
        sp->next=lh->next;
        return sh->next;
    }
};