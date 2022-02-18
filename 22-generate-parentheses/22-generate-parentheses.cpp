class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string s = string(2*n, '-');
        vector<string> fin_vec;
        gen_strings(0, s, 0, n, fin_vec);
        return fin_vec;
    }
    
    void gen_strings(int idx, string s, int opened, int to_use, vector<string>& vec) {
        if(idx == s.size()) {
            vec.push_back(s);
            return;
        }
        if(opened > 0) {
            s[idx] = ')';
            gen_strings(idx+1, s, opened-1, to_use, vec);
        }
        if(to_use > 0) {
            s[idx] = '(';
            gen_strings(idx+1, s, opened+1, to_use-1, vec);
        }
    }
    
};