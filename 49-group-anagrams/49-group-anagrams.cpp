class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> fin_vec;
        unordered_map<string, int> string2i;
        for(string &s : strs) {
            string sorted_s = get_sorted(s);
            auto it = string2i.find(sorted_s);
            if(it != string2i.end()) 
                fin_vec[it->second].push_back(s);
            else {
                fin_vec.push_back(vector<string>(1, s));
                string2i[sorted_s] = fin_vec.size() - 1;
            }
        }
        return fin_vec;
    }
    
    string get_sorted(const string &s) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        string copy;
        for(int i = 0; i < 26; i++) {
            while(freq[i]--)
                copy += i+'a';
        }
        return copy;
    }
};