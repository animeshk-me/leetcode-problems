class Trie {
public:
    Trie *children[26];
    bool is_end;
    Trie() {
        for(int i = 0; i < 26; i++) children[i] = nullptr;
        is_end = false;
    }
    
    void insert(string word) {
        Trie * temp = this;
        for(char c : word) {
            if(temp->children[c-'a'] == nullptr)
                temp->children[c-'a'] = new Trie();
            temp = temp->children[c-'a'];
        }
        temp->is_end = true;
    }
    
    bool search(string word) {
        Trie * temp = this;
        for(char c : word) {
            if(temp->children[c-'a'] == nullptr)
                return false;
            temp = temp->children[c-'a'];
        }
        return temp->is_end;
    }
    
    bool startsWith(string prefix) {
        Trie * temp = this;
        for(char c : prefix) {
            if(temp->children[c-'a'] == nullptr)
                return false;
            temp = temp->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */