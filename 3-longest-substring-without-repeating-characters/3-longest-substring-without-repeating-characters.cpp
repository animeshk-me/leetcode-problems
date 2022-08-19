class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = i;
        int max_len = 0;
        vector<bool> visit(195, false);
        while(j < s.size()) {
            while(j < s.size() && !visit[s[j] - ' ']) {
                // cout << "hi: " << s[j] - ' ' << endl;
                visit[s[j++] - ' '] = true;
            }
            max_len = max(max_len, j - i);
            if(j >= s.size())
                break;
            while(s[i] != s[j]) { 
                // cout << "hi2: " <<  s[i] - ' ' << endl;
                visit[s[i++] - ' '] = false;
            }
            // cout << "hi3: " << s[i] << ": " << i << ": " << j << ": "<< s[i] - ' ' << endl;
            visit[s[i++] - ' '] = false;
        }
        return max_len;
    }
// "abc;azq^%&*+(/*"
};