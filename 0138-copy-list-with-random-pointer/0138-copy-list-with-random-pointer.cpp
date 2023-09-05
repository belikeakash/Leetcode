/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* dummyT = dummy;
        Node* temp = head;
        int u = 0;
        unordered_map<Node*, Node*>m;
        while(temp) {
            Node* c = new Node(temp->val);
            dummyT->next = c;
            m[temp] = c;
            temp=temp->next;
            dummyT=dummyT->next;
            u++;
        }
        dummyT = dummy->next;
        temp = head;
        u = 0;
        while(dummyT) {
            //cout<<dummyT->val<<" ";
            if(!temp->random) dummyT->random = NULL;
            else {cout<<temp->random->val<<" "; 
                dummyT->random = m[temp->random];
            }
            temp=temp->next;
            dummyT = dummyT->next;
            u++;
        }
        dummy = dummy->next;
        // while(dummy) {
        //     cout<<dummy->random->val<<" ";
        //     dummy=dummy->next;
        // }
        return dummy;
    }
};