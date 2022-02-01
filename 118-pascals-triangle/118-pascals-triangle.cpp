class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> fin_vec(numRows, vector<int>());
        fin_vec[0] = vector<int>{1};
        for(int i = 1; i <= numRows-1; i++) {
            fin_vec[i].push_back(1);
            for(int j = 0; j < fin_vec[i-1].size()-1; j++)
                fin_vec[i].push_back(fin_vec[i-1][j] + fin_vec[i-1][j+1]);
            fin_vec[i].push_back(1);
        }
        return fin_vec;
    }
};