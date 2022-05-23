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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode *c1=head,*c2=head->next,*temp=head->next;
        while(c1 && c2 && c2->next){
            c1->next=c2->next;
            c2->next=c2->next->next;       
            c1=c1->next;
            c2=c2->next;
            if(!c2 || !c2->next) c1->next=temp;         
        }
        return head;    
    }
};