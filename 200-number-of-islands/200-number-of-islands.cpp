class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    DFS(i, j, grid);
                    count++;
                }
            }
        }
        return count;
    }
    
    void DFS(int x, int y, vector<vector<char>>& grid) {
        if(grid[x][y] != '1')
            return;
        grid[x][y]++;
        if(x < grid.size()-1)
            DFS(x+1, y, grid);
        if(x > 0)
            DFS(x-1, y, grid);
        if(y < grid[0].size()-1)
            DFS(x, y+1, grid);
        if(y > 0)
            DFS(x, y-1, grid);
    }
    
};