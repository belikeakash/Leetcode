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
  

    Node* flatten(Node* head) {
        if(head==NULL) return head;
        Node* a = head;
        while(a) {
            if(a->child) {
                Node* child = flatten(a->child);
                Node* next = a->next;
                a->child = NULL;
                a->next = child;
                child->prev = a;
                Node* d = child;
                while(d->next) {
                    d=d->next;
                }
                d->next = next;
                if(next) next->prev = d;
            }
            a=a->next;
        }
        return head;
    }
};