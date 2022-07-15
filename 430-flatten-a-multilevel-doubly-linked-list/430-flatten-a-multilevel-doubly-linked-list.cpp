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

class Solution {
public:
    Node* flatte(Node* head) {
        if(head==NULL) return NULL;
        Node* a = head;
        while(a!=NULL) {
            if(a->child) {
                auto x = flatte(a->child);
                Node* c = x;
                Node* next = a->next;
                a->child = NULL;
                while(c->next) {
                    c=c->next;
                }
                a->next = x;
                x->prev = a;
                c->next = next;
                if(next) next->prev = c;
            }
            a=a->next;
        }
        return head;
}
    Node* flatten(Node* head) {
        auto x = flatte(head);
        return x;
    }
};