class Solution {
public:
    string repeatLimitedString(string st, int repeatLimit) {
        string res = "";
        vector<int> vec(26, 0);
        for(char c : st)
            vec[c-'a']++;
        int b=25, s=25;
        get_pointers(b, s, vec);
        while(b != -1) {
            int x = 0;
            while(b >= 0 && vec[b] > 0 && x < repeatLimit) {
                res += b + 'a';
                vec[b]--;
                x++;
            }
            if(s == -1 && vec[b] > 0) 
                break;
            if(vec[b] != 0) {
                res += s + 'a';
                vec[s]--;
            }
            get_pointers(b, s, vec);
        }
        return res;
    }
    
    void get_pointers(int &b, int &s, vector<int>& vec) {
        while(b >= 0) {
            if(vec[b] > 0) 
                break;
            b--;
        }
        s = min(b-1, s);
        while(s >= 0) {
            if(vec[s] > 0) 
                break;
            s--;
        }
    }
};