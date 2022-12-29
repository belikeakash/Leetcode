//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    Node* divide(int n, Node *head){
        Node* odd_s = NULL;
        Node* odd_e = NULL;
        Node* even_s = NULL;
        Node* even_e = NULL;
        
        Node* curr = head;
        while(curr) {
            if(curr->data%2==0) {
                if(even_s==NULL) {
                    even_s = curr;
                    even_e = even_s;
                }
                else {
                    even_e->next = curr;
                    even_e = even_e->next;
                }
            }
            else {
                if(odd_s==NULL) {
                    odd_s = curr;
                    odd_e = odd_s;
                }
                else {
                    odd_e->next = curr;
                    odd_e = odd_e->next;
                }
            }
            curr=curr->next;
        }
        if(odd_s==NULL) {
            head = even_s;
        }
        else if(even_s==NULL) {
            head = odd_s;
        }
        else {
            even_e->next = odd_s;
            odd_e->next = NULL;
            head = even_s;
        }
        return head;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends