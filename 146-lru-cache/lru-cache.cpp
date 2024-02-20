class Node{
    public:
    int val;
    int key;
    Node *next;
    Node *prev;
    Node(){
    }
    Node(int val,int key){
        this->val = val;
        this->key = key;
    }
};
class LRUCache {
    int capacity;
    unordered_map<int,Node*> mp;
    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *newnode){
        newnode->next = head->next;
        head->next->prev = newnode;
        head->next = newnode;
        newnode->prev = head;
    }

    void deleteNode(Node* delnode) {
        delnode->prev->next = delnode->next;
        delnode->next->prev = delnode->prev;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;

        Node *resNode = mp[key];
        int ans = resNode->val;
        deleteNode(resNode);
        addNode(resNode);
        return ans;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node *curr = mp[key];
            mp.erase(key);
            deleteNode(curr);
        }
        if(mp.size()==capacity) {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(value,key));
        mp[key] = head->next;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */