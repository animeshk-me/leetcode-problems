class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())
            return false;
        // vector<vector<int>> Memo(s1.size()+1, vector<int>(s2.size()+1, -1));
        return is_interleaved_iterative(s1, s2, s3);
    }
    
    bool is_interleaved_iterative(string& s1, string& s2, string& s3) {
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
    
    
    bool is_interleaved(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>> &Memo) {
        int k = i + j;
        if(k == s3.size())
            return i == s1.size() && j == s2.size();
        
        if(Memo[i][j] == -1) {
            Memo[i][j] = false;
            if(i < s1.size() && s1[i] == s3[k])
                Memo[i][j] |= is_interleaved(i+1, j, s1, s2, s3, Memo);
            if(Memo[i][j] == 1)
                return true;
            if(j < s2.size() && s2[j] == s3[k])
                Memo[i][j] |= is_interleaved(i, j+1, s1, s2, s3, Memo);
        }
        return Memo[i][j];
    }
};