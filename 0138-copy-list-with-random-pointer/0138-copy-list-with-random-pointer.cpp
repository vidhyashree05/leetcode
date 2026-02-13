class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;

        unordered_map<Node*, Node*> mp;

        // Create copy of each node
        Node* curr = head;
        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        // Assign next and random pointers
        curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];       // copy next
            mp[curr]->random = mp[curr->random];   // copy random
            curr = curr->next;
        }

        return mp[head];
    }
};
