class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> vec;
        int i = 0;
        int j = s.size();
        for(char& c : s) {
            if(c == 'D')
                vec.push_back(j--);
            else
                vec.push_back(i++);
        }
        vec.push_back(i);
        return vec;
    }
};