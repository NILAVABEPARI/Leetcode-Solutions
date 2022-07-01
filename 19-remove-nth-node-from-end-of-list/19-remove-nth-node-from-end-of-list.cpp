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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start=new ListNode();
        start->next=head;
        ListNode *slow=start,*fast=start;
        int cnt=1;
        while(cnt<=n){
            fast=fast->next;
            cnt++;
        }  
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        ListNode *ptr=slow->next;
        slow->next=slow->next->next;
        delete(ptr);
        return start->next;
    }
    
    
    //brute force
    // ListNode* removeNthFromEnd(ListNode* head, int n){
    //     ListNode *temp=head;
    //     int cnt=0,i=1;
    //     while(temp){
    //         cnt++;
    //         temp=temp->next;
    //     }
    //     temp=head;
    //     if(cnt==n){
    //         head=head->next;
    //         delete(temp);
    //         return head;
    //     }
    //     cnt=cnt-n;
    //     while(i<cnt){
    //         temp=temp->next;
    //         i++;
    //     }
    //     ListNode *ptr=temp->next;
    //     temp->next=temp->next->next;
    //     delete(ptr);
    //     return head;
    // }
};