class Solution {
public:
    bool wordPattern(string pattern, string s) {
        istringstream strcin(s);
        string str;
        vector<string> words;
        while(strcin >> str) words.push_back(str);
        if (pattern.size() != words.size()) 
            return false;
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        for(int i = 0; i < pattern.size(); i++) {
            auto it1 = map1.find(pattern[i]);
            auto it2 = map2.find(words[i]);
            if(it1 == map1.end() && it2 == map2.end()) {
                map1[pattern[i]] = words[i];
                map2[words[i]] = pattern[i];
            } 
            else if(it1 != map1.end() && it2 != map2.end()) {
                if(map1[pattern[i]] != words[i] || map2[words[i]] != pattern[i])
                    return false;
            }
            else
                return false;
        }
        return true;
    }
};