class WordDictionary {
public:
    WordDictionary * children[26];
    bool is_word;
    WordDictionary() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        is_word = false;
    }
    
    void addWord(string word) {
        WordDictionary * temp = this;
        for(char x : word) {
            if(temp->children[x-'a'] == nullptr)
                temp->children[x-'a'] = new WordDictionary();
            temp = temp->children[x-'a'];
        }
        temp->is_word = true;
    }
    
    bool search(string word) {
        return search2(0, word);
    }
    
    bool search2(int id, string &word) {
        if(id == word.size())
            return this->is_word;
        if(word[id] == '.') {
            for(int i = 0; i < 26; i++) {
                if(this->children[i] != nullptr && this->children[i]->search2(id+1, word))
                    return true;
            }
            return false;
        }
        if(this->children[word[id] - 'a'] == nullptr)
            return false;
        return this->children[word[id] - 'a']->search2(id+1, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */