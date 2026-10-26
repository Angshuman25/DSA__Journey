class LRUCache {
public:
    class Node {
        public:
            int key;
            int val;
            Node* prev;
            Node* next;

            Node(int k , int v) {
                key = k;
                val = v;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1 , -1);
    Node* tail = new Node(-1 , -1);
    
    unordered_map<int , Node*>m;
    int limit;

    void addNode(Node* newNode) {  // O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->next = oldNext;
        newNode->prev = head;
    }

    void deleteNode(Node* oldNode) {  // O(1)
        Node* oldPrev = oldNode->prev;
        Node* oldNext = oldNode->next;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {   // O(1)
        if(m.find(key) == m.end()) {
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        deleteNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int val) {  // O(1)

        // If key already exists
        if(m.find(key) != m.end()) {
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        // If Cache's Capacity already reached
        if(m.size() == limit) {
            // Delete LRU Data
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        
        // Insert New Key 
        Node* newNode = new Node(key , val);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */