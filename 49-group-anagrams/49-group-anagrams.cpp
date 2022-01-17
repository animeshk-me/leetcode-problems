class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> fin_vec;
        map<string, int> string2i;
        for(string &s : strs) {
            string sorted_s = get_sorted(s);
            auto it = string2i.find(sorted_s);
            if(it != string2i.end()) 
                fin_vec[it->second].push_back(s);
            else {
                fin_vec.push_back(vector<string>(1, s));
                string2i[sorted_s] = fin_vec.size() - 1;
            }
        }
        return fin_vec;
    }
    
    string get_sorted(string s) {
        sort(s.begin(), s.end());
        return s;
    }
};