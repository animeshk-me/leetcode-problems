class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> S;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                S.push(i);
            }
            else if(s[i] == ')') {
                if(S.empty())
                    s[i] = '*';
                else 
                    S.pop();
            }
        }
        while(!S.empty()) {
            s[S.top()] = '*'; 
            S.pop();
        }
        s.erase(remove(s.begin(), s.end(), '*'), s.end());
        return s;
    }
};