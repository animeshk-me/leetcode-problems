class Solution {
public:
    vector<vector<int>> shortest_len;
    vector<vector<int>> Grid;
    vector<int> src;
    int low;
    int high;
    int m;
    int n;
    
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        Grid = grid;  src = start;
        low = pricing[0];  high = pricing[1];
        m = Grid.size(); n = Grid[0].size();
        shortest_len = vector<vector<int>>(m, vector<int>(n, -1));
        find_shortest_lens();
        vector<pair<int,int>> pairs;
        pairs = get_pairs();
        // for(auto p : pairs)
        //     cout << "("<<p[0]<<","<<p[1]<<"),"; 
        
        sort(pairs.begin(), pairs.end(), [this](pair<int,int> l, pair<int,int> r) {return comparator(l, r); });
        // return pairs;
        vector<vector<int>> fin_pairs;
        for(int i = 0; i < k && i < pairs.size(); i++)
            fin_pairs.push_back(vector<int>{pairs[i].first, pairs[i].second});
        return fin_pairs;
        // return pairs.size() <= k ? pairs : vector<vector<int>>(pairs.begin(), pairs.begin() + k);
    }
    
    
    bool comparator(const pair<int,int> &p1, const pair<int,int> &p2) {
        int i1 = p1.first;
        int j1 = p1.second;
        int i2 = p2.first;
        int j2 = p2.second;
        if(shortest_len[i1][j1] > shortest_len[i2][j2])
            return false;
        if(shortest_len[i1][j1] == shortest_len[i2][j2]) {
            if(Grid[i1][j1] > Grid[i2][j2])
                return false;
            if(Grid[i1][j1] == Grid[i2][j2]) {
                if(i1 > i2) 
                    return false;
                if(i1 == i2) 
                    return j1 < j2;
                else //i1 < i2
                    return true;
            }
            else  // grid1 < grid2
                return true;
        }
        else  // len1 < len2
            return true;
    }
    
    vector<pair<int,int>> get_pairs() {
        vector<pair<int,int>> pairs;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // cout << shortest_len[i][j] << ", ";
                if(Grid[i][j] >= low && Grid[i][j] <= high && shortest_len[i][j] != -1)
                    pairs.push_back({i, j});
            }
            // cout << endl;
        }
        return pairs;
    }
    
    void find_shortest_lens() {
        queue<pair<int,int>> Q;
        shortest_len[src[0]][src[1]] = INT_MAX;
        Q.push({src[0], src[1]});
        int num = 0;
        while(!Q.empty()) {
            int size = Q.size();
            // cout << num << ", " << size << endl;
            while(size--) {
                int x = Q.front().first;  int y = Q.front().second; Q.pop();
                if(Grid[x][y] == 0) 
                    continue;
                shortest_len[x][y] = num;
                if(x < m - 1 && shortest_len[x+1][y] == -1) {
                    shortest_len[x+1][y] = INT_MAX;
                    Q.push({x+1, y});
                }
                if(y < n - 1 && shortest_len[x][y+1] == -1) {
                    shortest_len[x][y+1] = INT_MAX;
                    Q.push({x, y+1});
                }
                if(x > 0 && shortest_len[x-1][y] == -1) {
                    shortest_len[x-1][y] = INT_MAX;
                    Q.push({x-1, y});
                }
                if(y > 0 && shortest_len[x][y-1] == -1) {
                    shortest_len[x][y-1] = INT_MAX;
                    Q.push({x, y-1});
                }
            }
            num++;
        }
        // cout << "hello\n";
    }
    
};