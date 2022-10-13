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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA) return NULL;
        if(!headB) return NULL;
        if(headA==headB) return headA;
        ListNode *curr1=headA, *curr2=headB;
        int cnt1=0,cnt2=0;
        while(curr1 || curr2){
            if(curr1){
                cnt1++;
                curr1=curr1->next;
            }
            if(curr2){
                cnt2++;
                curr2=curr2->next;
            }
        }
        curr1=headA, curr2=headB;
        if(cnt1>cnt2){
            cnt1=cnt1-cnt2;
            while(cnt1--) curr1=curr1->next;
        }
        else{
            cnt2=cnt2-cnt1;
            while(cnt2--) curr2=curr2->next;
        }        
        while(curr1 && curr2){
            if(curr1==curr2) return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};