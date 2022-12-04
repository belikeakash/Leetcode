//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node* func(Node* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        Node* dummy = new Node(-5003);
        Node* temp1 = head;
        dummy->next = head;
        
        Node* t2 = head;
        Node* t3 = dummy;
        while(temp1) {
            t2 = temp1->next;
            temp1->next = t3;
            dummy->next = t2;
            t3 = temp1;
            temp1 = t2;
            // cout<<t3->val<<" ";
        }
        
        head = t3;
        Node* temp = head;
        if(temp->next==NULL) return NULL;
        while(temp->next->data!=-5003) {
            temp=temp->next;
        }
        // return head;
        temp->next = NULL;
        return head;
    }
    Node *compute(Node *head)
    {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        Node* dummy = new Node(-5003);
        Node* temp1 = head;
        dummy->next = head;
        
        Node* t2 = head;
        Node* t3 = dummy;
        while(temp1) {
            t2 = temp1->next;
            temp1->next = t3;
            dummy->next = t2;
            t3 = temp1;
            temp1 = t2;
            // cout<<t3->val<<" ";
        }
        
        head = t3;
        Node* temp = head;
        if(temp->next==NULL) return NULL;
        while(temp->next->data!=-5003) {
            temp=temp->next;
        }
        // return head;
        temp->next = NULL;
        //head
        
        int maxi = head->data;
        Node* tt1 = head;
        Node* tt2 = head->next; 
        while(tt2) {
            //cout<<maxi<<" ";
            if(tt2->data<maxi) {
                tt2=tt2->next;
            }
            else {
                maxi = max(maxi,tt2->data);
                tt1->next = tt2;
                tt1 = tt2;
                tt2 = tt2->next;
                
                
            }
        }
        //cout<<endl;
        tt1->next = tt2;
        head = func(head);
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends