class Solution {
public:    
    ListNode* reverseBetween(ListNode* head, int l, int r){        
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *prev=dummy,*curr,*nxt;
        for(int i=1;i<l;i++){
            prev=prev->next;
            r--;
        }
        ListNode *last=prev;
        curr=prev->next;
        ListNode *last2=curr;
        
        for(int i=0;i<r;i++){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;            
        }
        last->next=prev;
        last2->next=curr;
        return dummy->next;
    }
};