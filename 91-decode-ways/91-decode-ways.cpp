class Solution {
public:
    int numDecodings(string s) {
        vector<int> Memo(s.size(), -1);
        return get_num(s, 0, Memo);
    }
    
    int get_num(string &s, int id, vector<int> &Memo) {
        if(id >= s.size())
            return 1;
        if(s[id] == '0')
            return 0;
        if(Memo[id] == -1) {
            Memo[id] = get_num(s, id+1, Memo);
            if(id < s.size() - 1 && (s[id] == '1' || (s[id] == '2' && s[id+1] <= '6')))
                Memo[id] += get_num(s, id+2, Memo);
        }
        return Memo[id];
    }
};