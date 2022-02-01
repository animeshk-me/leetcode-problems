class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visit[i][j] || matrix[i][j] != 0)
                    continue;
                for(int x = 0; x < m; x++) 
                    visit[x][j] = matrix[x][j] != 0 ? true : false;
                for(int y = 0; y < n; y++) 
                    visit[i][y] = matrix[i][y] != 0 ? true : false;
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(visit[i][j])
                    matrix[i][j] = 0;
            }
        }
    }
};