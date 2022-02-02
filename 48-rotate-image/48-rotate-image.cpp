class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<int> clip(matrix.size(), 0);
        for(int size = matrix.size(); size > 1; size -= 2)
            rot(size, matrix, clip);
    }
    
    void rot(int x, vector<vector<int>>& matrix, vector<int>& clip) {
        int i = (clip.size() - x) / 2;
        for(int j = 1; j < x; j++)
            clip[j] = matrix[i][i+j];
        for(int j = 1; j < x; j++)
            matrix[i][i+j] = matrix[i+x-1-j][i];
        for(int j = 1; j < x; j++)
            matrix[i+x-1-j][i] = matrix[i+x-1][i+x-1-j];
        for(int j = 1; j < x; j++)
            matrix[i+x-1][i+x-1-j] = matrix[i+j][i+x-1];
        for(int j = 1; j < x; j++)
            matrix[i+j][i+x-1] = clip[j];
    }
};