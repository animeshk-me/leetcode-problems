class Solution {
public:
    bool validPalindrome(string s) {
        bool got = false;
        int i = 0;
        int j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) 
                break;
            i++;
            j--;
        }
        
        if(check(s, i))
            return true;
        
        return check(s, j);
    }
    
    bool check(string s, int x) {
        int i = 0; 
        int j = s.size() - 1;
        while(i < j) {
            if(i == x) {
                i++;
                continue;
            } 
            if(j == x) {
                j--;
                continue;
            }
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};