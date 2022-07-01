class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode *c1=head,*c2=head->next,*temp=head->next;
        while(c2 && c2->next){
            c1->next=c2->next;
            c2->next=c2->next->next;     
            c1=c1->next;
            c2=c2->next;       
        }
        c1->next=temp;
        return head;    
    }
};