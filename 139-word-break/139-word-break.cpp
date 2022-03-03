class Node {
  public:
    Node* children[26];
    bool is_end;
    Node() {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
        is_end = false;
    }
    
    void insert(string s) {
        Node* temp = this;
        for(char c : s) {
            if(temp->children[c-'a'] == nullptr)
                temp->children[c-'a'] = new Node();
            temp = temp->children[c-'a'];
        }
        temp->is_end = true;
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Node* trie = new Node();
        vector<int> Memo(s.size(), -1);
        for(auto& word : wordDict)
            trie->insert(word);
        return is_valid_break(0, s, trie, Memo);
    }
    
    bool is_valid_break(int idx, string& s, Node* trie, vector<int>& Memo) {
        if(idx >= s.size())
            return true;

        if(Memo[idx] == -1) {            
            Node* temp = trie;
            for(int i = idx; i <= s.size(); i++) {
                if(temp->is_end && is_valid_break(i, s, trie, Memo))
                    return true;
                if(i == s.size())
                    break;
                if(temp == nullptr || temp->children[s[i]-'a'] == nullptr)
                    break;
                temp = temp->children[s[i]-'a'];
            }
            Memo[idx] = false;
        }
        return Memo[idx];
    }
};