class Trie {
private:
    struct Node {
        Node* links[26];
        bool flag;  // Marks end of word
        
        Node() {
            flag = false;
            for(int i = 0; i < 26; i++)
                links[i] = nullptr;
        }
    };
    
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(char ch : word) {
            int index = ch - 'a';
            
            if(node->links[index] == nullptr)
                node->links[index] = new Node();
                
            node = node->links[index];
        }
        
        node->flag = true;  // mark end of word
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(char ch : word) {
            int index = ch - 'a';
            
            if(node->links[index] == nullptr)
                return false;
                
            node = node->links[index];
        }
        
        return node->flag;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(char ch : prefix) {
            int index = ch - 'a';
            
            if(node->links[index] == nullptr)
                return false;
                
            node = node->links[index];
        }
        
        return true;
    }
};