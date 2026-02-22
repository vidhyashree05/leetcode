class WordDictionary {
    
    struct TrieNode {
        TrieNode* children[26];
        bool isEnd;
        
        TrieNode() {
            isEnd = false;
            for(int i = 0; i < 26; i++)
                children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        
        for(char c : word) {
            int idx = c - 'a';
            if(node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        
        node->isEnd = true;
    }
    
    bool search(string word) {
        return helper(word, 0, root);
    }
    
private:
    bool helper(string &word, int pos, TrieNode* node) {
        if(node == nullptr) return false;
        
        if(pos == word.size())
            return node->isEnd;
        
        char c = word[pos];
        
        if(c == '.') {
            for(int i = 0; i < 26; i++) {
                if(helper(word, pos + 1, node->children[i]))
                    return true;
            }
            return false;
        }
        else {
            return helper(word, pos + 1, node->children[c - 'a']);
        }
    }
};