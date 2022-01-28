class Solution {
public:
    bool halvesAreAlike(string s) {
        return get_num_vowels(s, 0, (s.size()>>1)-1) == get_num_vowels(s, s.size()>>1, s.size()-1);
    }
    
    int get_num_vowels(string &s, int st, int end) {
        int num = 0;
        for(int i = st; i <= end; i++) {
            if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' )
                num++;
        }
        return num;
    }
};