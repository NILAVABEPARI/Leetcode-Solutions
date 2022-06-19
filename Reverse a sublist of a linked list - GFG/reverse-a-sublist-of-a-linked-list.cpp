// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution{
    public:
    Node* reverseBetween(Node* head, int m, int n){
        //code here
        if(!head) return NULL;
        Node *curr=head,*prev=NULL,*rev_tail=NULL,*tail=NULL,*nxt=NULL;
        int ind=1;
        while(ind<m){
            prev=curr;
            curr=curr->next;
            ind++;
        }
        tail=prev;
        rev_tail=curr;
        while(ind<=n){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
            ind++;
        }
        if(m!=1) tail->next=prev;
        rev_tail->next=curr;
        if(m==1) return prev;
        return head;
    }
};

// { Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends