class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = i;
        int max_len = 0;
        vector<bool> visit(126, false);
        while(j < s.size()) {
            while(j < s.size() && !visit[s[j] - ' ']) 
                visit[s[j++] - ' '] = true;
            max_len = max(max_len, j - i);
            if(j >= s.size())
                break;
            while(s[i] != s[j]) 
                visit[s[i++] - ' '] = false;
            visit[s[i++] - ' '] = false;
        }
        return max_len;
    }
};