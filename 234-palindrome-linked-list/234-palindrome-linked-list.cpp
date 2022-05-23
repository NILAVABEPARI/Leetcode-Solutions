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
    //brute force
    // bool isPalindrome(ListNode* head) {
    //     vector<int> temp;
    //     ListNode *curr=head;
    //     while(curr){
    //         temp.push_back(curr->val);
    //         curr=curr->next;
    //     }
    //     int l=0,h=temp.size()-1;
    //     while(l<h){
    //         if(temp[l++]!=temp[h--])
    //             return false;
    //     }
    //     return true;
    // }
    
    
    //optimized
    ListNode* reverse(ListNode* ptr) {
        ListNode *pre=NULL;
        ListNode* nxt=NULL;
        while(ptr!=NULL) {
            nxt = ptr->next;
            ptr->next = pre;
            pre=ptr;
            ptr=nxt;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head){
        if(!head || !head->next) return true;
        ListNode *slow=head,*fast = head;        
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }        
        slow->next = reverse(slow->next);
        slow=slow->next;
        fast=head;
        while(slow!=NULL) {
            if(fast->val != slow->val) 
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }    
};