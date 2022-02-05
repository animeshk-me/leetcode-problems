class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int max_val = 0;
        vector<bool> visit(statements.size(), false);
        get_all_subsets(0, visit, max_val, statements);
        return max_val;
    }
    
    void get_all_subsets(int i, vector<bool> visit, int &max_val, vector<vector<int>>& statements) {
        if(i == statements.size()) {
            max_val = max(max_val, get_valid(visit, statements));
            return;
        }
        get_all_subsets(i+1, visit, max_val, statements);
        visit[i] = true;
        get_all_subsets(i+1, visit, max_val, statements);
    }
    
    int get_valid(vector<bool> &visit, vector<vector<int>>& statements) {
        int count_friends = 0;
        int n = statements.size();
        for(int i = 0; i < n; i++) {
            if(visit[i]) {
                for(int j = 0; j < n; j++) {
                    if(statements[i][j] != 2 && visit[j] != statements[i][j])
                        return 0;
                }
                count_friends++;
            }
        }
        return count_friends;
    }
    
};