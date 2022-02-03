class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int size = matrix.size(); size > 1; size -= 2)
            rot(size, matrix);
    }
    
    void rot(int x, vector<vector<int>>& matrix) {
        int i = (matrix.size() - x) / 2;
        for(int j = 1; j < x; j++)
            swap(matrix[i][i+j], matrix[i+x-1-j][i]);
        for(int j = 1; j < x; j++)
            swap(matrix[i+x-1-j][i], matrix[i+x-1][i+x-1-j]);
        for(int j = 1; j < x; j++)
            swap(matrix[i+x-1][i+x-1-j], matrix[i+j][i+x-1]);
    }
};