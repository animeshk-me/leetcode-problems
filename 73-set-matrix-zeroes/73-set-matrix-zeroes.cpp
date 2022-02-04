class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int var = 1;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    if(j == 0)
                        var = 0;
                    else 
                        matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1; i < m; i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0; j < n; j++)
                    matrix[i][j] = 0;
            }
        }
        int bef = matrix[0][0];
        
        for(int j = 0; j < n; j++) {
            int temp = j==0 ? var : matrix[0][j];
            if(temp == 0) {
                for(int i = 0; i < m; i++)
                    matrix[i][j] = 0;
            }
        }
        if(bef == 0) {
            for(int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }
        
    }
};