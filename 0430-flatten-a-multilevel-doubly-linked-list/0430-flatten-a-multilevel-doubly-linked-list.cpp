/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
Node* func(Node* head) {
    if(!head) return head;
    // cout<<"*"<<head->val<<"* ";
    // if(!head->next) return head;
    while(head!=NULL) {
        cout<<head->val<<" ";
        if(head->child) {
            auto c = head->next;
            head->next = head->child;
            head->child->prev = head;
            
            auto x = func(head->child);
            if(x==NULL) {
                cout<<"b";
            }
            head->child = NULL;
            cout<<"-"<<x->val<<"-";
            if(c!=NULL) x->next = c;
            if(c!=NULL) c->prev = x;
            // head=head->next;
        }
        if(head->next!=NULL)head=head->next;
        else break;
    }
        //head=head->next;
        return head;
    
}
class Solution {
public:
    Node* flatten(Node* head) {
        Node* temp = head;
        func(temp);
        return head;
    }
};