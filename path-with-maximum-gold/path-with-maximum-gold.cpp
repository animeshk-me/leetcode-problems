class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        vector<vector<bool>> visit(grid.size(), vector<bool>(grid[0].size(), false));
        int max_val = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) 
                max_val = max(max_val, get_max_gold(i, j, grid, visit));
        }
        return max_val;
    }
    
    
    int get_max_gold(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visit) {
        if(grid[i][j] == 0)
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int max_val = 0;
        visit[i][j] = true;
        if((i+1 >= 0 && i+1 < m && j >= 0 && j < n) && !visit[i+1][j])
            max_val = max(max_val, get_max_gold(i+1, j, grid, visit));
        if((i >= 0 && i < m && j+1 >= 0 && j+1 < n) && !visit[i][j+1])
            max_val = max(max_val, get_max_gold(i, j+1, grid, visit));
        if((i-1 >= 0 && i-1 < m && j >= 0 && j < n) && !visit[i-1][j])
            max_val = max(max_val, get_max_gold(i-1, j, grid, visit));
        if((i >= 0 && i < m && j-1 >= 0 && j-1 < n) && !visit[i][j-1])
            max_val = max(max_val, get_max_gold(i, j-1, grid, visit));
        visit[i][j] = false;
        return max_val + grid[i][j];
    }
};