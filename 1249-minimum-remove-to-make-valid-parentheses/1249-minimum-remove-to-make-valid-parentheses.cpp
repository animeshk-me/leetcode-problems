class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> S;
        vector<int> visit(s.size(), false);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                S.push(i);
                visit[i] = true;
            }
            else if(s[i] == ')') {
                if(S.empty())
                    visit[i] = true;
                else {
                    visit[S.top()] = false;
                    S.pop();
                }
            }
        }
        string s2 = "";
        for(int i = 0; i < s.size(); i++) {
            if(!visit[i])
                s2 += s[i];
        }
        return s2;
    }
};