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
        //  basically i have to iterate over the list
        // step 1 create the copy of the list node
        unordered_map<Node*,Node*>mp;
        Node* curr=head;
        while(curr!=nullptr){
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
        // connect the next and the random
        curr=head;
        while(curr!=nullptr){
            mp[curr]->next=mp[curr->next];
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
        }
        return mp[head];
    }
};
