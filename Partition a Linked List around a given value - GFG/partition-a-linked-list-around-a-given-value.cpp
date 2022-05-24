// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node* partition(struct Node* head, int x);

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void) {
    int t;
    cin >> t;

    while (t--) {
        struct Node* head = NULL;
        struct Node* temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++) {
            int value;
            cin >> value;
            if (i == 0) {
                head = new Node(value);
                temp = head;
            } else {
                temp->next = new Node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        // Solution ob;

        head = partition(head, k);
        printList(head);
    }

    return (0);
}
// } Driver Code Ends


// User function Template for C++

/*struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};*/

struct Node* partition(struct Node* head, int x) {
    // code here
    vector<int>bef,num,af;
    Node *temp=head;
    while(temp){
        if(temp->data<x)
            bef.push_back(temp->data);
        else if(temp->data>x)
            af.push_back(temp->data);
        else num.push_back(temp->data);
        temp=temp->next;
    }
    temp=head;
    
    for(int i=0;i<bef.size();i++){
        temp->data=bef[i];
        temp=temp->next;
    }
    for(int i=0;i<num.size();i++){
        temp->data=num[i];
        temp=temp->next;
    }
    for(int i=0;i<af.size();i++){
        temp->data=af[i];
        temp=temp->next;
    }
    return head;
}