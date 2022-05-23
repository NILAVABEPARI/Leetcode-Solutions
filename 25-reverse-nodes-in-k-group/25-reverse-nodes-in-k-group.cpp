class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *temp=head;
        int n=0;
        while(temp){
            ++n;
            temp=temp->next;
        }
        ListNode *prev=dummy,*curr,*nxt;
        while(n>=k){
            curr = prev->next;
            nxt = curr->next;
            for(int i=1;i<k;i++){
                curr->next=nxt->next;
                nxt->next=prev->next;
                prev->next=nxt;
                nxt=curr->next;
            }
            n-=k;
            prev=curr;
        }
        return dummy->next;
    }
};