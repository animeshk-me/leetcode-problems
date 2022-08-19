class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = i;
        int max_len = 0;
        unordered_set<char> visit;
        while(j < s.size()) {
            while(j < s.size() && visit.find(s[j]) == visit.end()) 
                visit.insert(s[j++]);
            max_len = max(max_len, j - i);
            while(s[i] != s[j]) 
                visit.erase(s[i++]);
            visit.erase(s[i++]);
        }
        return max_len;
    }
};