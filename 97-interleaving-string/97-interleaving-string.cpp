class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        int m = s1.size(), n = s2.size();
        vector<vector<int>> Cache(m + 1, vector<int>(n + 1, 0));
        Cache[m][n] = 1;
        for(int i = m; i >= 0; i--) {
            for(int j = n; j >= 0; j--) {
                if(i+j == m+n)
                    continue;
                if(i < m && s1[i] == s3[i+j])
                    Cache[i][j] |= Cache[i+1][j];
                if(j < n && s2[j] == s3[i+j])
                    Cache[i][j] |= Cache[i][j+1];
            }
        }
        return Cache[0][0];
    }
};