class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *temp=list1,*h1,*tail;
        for(int i=1;i<a;i++){
            temp=temp->next;
            b--;
        }
        h1=temp;
        for(int i=0;i<b;i++)
            temp=temp->next;
        h1->next=list2;
        tail=temp;
        temp=list2;
        while(temp->next)
            temp=temp->next;
        temp->next=tail->next;
        tail->next=NULL;
        return list1;
    }
};