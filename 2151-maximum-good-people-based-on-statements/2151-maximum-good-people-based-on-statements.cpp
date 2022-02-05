class Solution {
public:
    int maximumGood(vector<vector<int>>& statements) {
        int max_val = 0;
        bitset<16> visit;
        // vector<bool> visit(statements.size(), false);
        get_all_subsets(0, visit, max_val, statements);
        return max_val;
    }
    
    void get_all_subsets(int i, bitset<16> visit, int &max_val, vector<vector<int>>& statements) {
        if(i == statements.size()) {
            max_val = max(max_val, get_valid(visit, statements, max_val));
            return;
        }
        get_all_subsets(i+1, visit, max_val, statements);
        visit[i] = 1;
        get_all_subsets(i+1, visit, max_val, statements);
    }
    
    int get_valid(bitset<16> &visit, vector<vector<int>>& statements, int max_val) {
        int count_friends = visit.count();
        if(count_friends <= max_val)
            return 0;
        int n = statements.size();

        for(int i = 0; i < n; i++) {
            if(visit[i]) {
                for(int j = 0; j < n; j++) {
                    if(statements[i][j] != 2 && visit[j] != statements[i][j])
                        return 0;
                }
            }
        }
        return count_friends;
    }
    
};