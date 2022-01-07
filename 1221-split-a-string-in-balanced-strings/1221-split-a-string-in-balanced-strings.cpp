class Solution {
public:
    int balancedStringSplit(string s) {
        int count = 0;
        int i = 0;
        int c_l = 0;
        int c_r = 0;
        while(i < s.size()) {
            if(s[i] == 'L') 
                c_l++;
            else
                c_r++;
            i++;
            if(c_l == c_r) {
                c_l = 0;
                c_r = 0;
                count++;
            } 
        }
        return count;
    }
};