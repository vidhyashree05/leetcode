class LRUCache {
private:
    int capacity;

    // Doubly linked list node
    struct Node {
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = next = NULL;
        }
    };

    unordered_map<int, Node*> mp;

    Node* head; // dummy head
    Node* tail; // dummy tail

    // Add node right after head
    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // Remove node from list
    void deleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;

        head = new Node(-1, -1);  // dummy
        tail = new Node(-1, -1);  // dummy

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // Move to front (most recently used)
        deleteNode(node);
        addNode(node);

        return node->value;
    }

    void put(int key, int value) {

        if (mp.find(key) != mp.end()) {
            // Key exists → update value and move to front
            Node* node = mp[key];
            node->value = value;

            deleteNode(node);
            addNode(node);
        }
        else {
            // New key
            if (mp.size() == capacity) {
                // Remove least recently used (tail->prev)
                Node* lru = tail->prev;

                deleteNode(lru);
                mp.erase(lru->key);
            }

            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addNode(newNode);
        }
    }
};
