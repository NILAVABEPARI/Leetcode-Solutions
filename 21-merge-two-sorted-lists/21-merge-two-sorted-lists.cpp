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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //brute force with extra space - O(m+n)
        ListNode *dummy = new ListNode(-1);
        ListNode *l1 = list1, *l2 = list2, *ptr = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                ListNode *curr = new ListNode(l1->val);
                ptr->next = l1;
                l1 = l1->next;
            }
            else {
                ListNode *curr = new ListNode(l2->val);
                ptr->next = l2;
                l2 = l2->next;
            }
            ptr = ptr->next;
        }
        if (l1) ptr->next = l1;
        if (l2) ptr->next = l2;
        return dummy->next;
        
        
        // ListNode *head=NULL, *ptr=NULL;
        // if(!list1) return list2;
        // if(!list2) return list1;
        // while(list1 && list2){
        //     if(list1->val < list2->val){
        //         if(head==NULL){
        //             head=list1;
        //             ptr=head;
        //         }
        //         else{
        //             ptr->next=list1;
        //             ptr=ptr->next;
        //         }
        //         list1=list1->next;
        //     }
        //     else{
        //         if(head==NULL){
        //             head=list2;
        //             ptr=head;
        //         }
        //         else{
        //             ptr->next=list2;
        //             ptr=ptr->next;
        //         }
        //         list2=list2->next;
        //     }
        // }        
        // if(list1!=NULL) ptr->next=list1;
        // if(list2!=NULL) ptr->next=list2;
        // return head;
    }
};