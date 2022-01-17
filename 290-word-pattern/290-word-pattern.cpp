class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        int i = 0, j = 0;
        for(; i < pattern.size() && j < s.size(); i++, j++) {
            int st = j;
            while(j < s.size() && s[j] != ' ') j++;
            string word = s.substr(st, j - st);
            auto it1 = map1.find(pattern[i]);
            auto it2 = map2.find(word);
            if(it1 == map1.end() && it2 == map2.end()) {
                map1[pattern[i]] = word;
                map2[word] = pattern[i];
            } 
            else if(it1 != map1.end() && it2 != map2.end()) {
                if(map1[pattern[i]] != word || map2[word] != pattern[i])
                    return false;
            }
            else
                return false;
        }
        return (i >= pattern.size() && j >= s.size());
    }
};