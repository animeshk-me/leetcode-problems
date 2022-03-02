class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        auto adj_list = get_adj_list(edges, n);
        // for(int u = 0; u < n; u++) {
        //     cout << u << ": " ;
        //     for(auto x : adj_list[u])
        //         cout << "{" << x.first << "," << x.second << "}, ";
        //     cout << endl;
        // }
        auto all_pair_path = get_all_pair_shortest(adj_list, n);
        
        int min_count = INT_MAX;
        int min_city = -1;
        for(int i = 0; i < n; i++) {
            int curr_count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && all_pair_path[i][j] <= distanceThreshold)
                    curr_count++;
            }
            if(min_count >= curr_count) {
                min_count = curr_count;
                min_city = i;
            }
        }
        return min_city;
    }
    
    vector<vector<pair<int,int>>> get_adj_list(vector<vector<int>>& edges, int n) {
        vector<vector<pair<int,int>>> adj_list(n, vector<pair<int,int>>());
        for(auto& e : edges) {
            adj_list[e[0]].push_back({e[1], e[2]});
            adj_list[e[1]].push_back({e[0], e[2]});
        }
        return adj_list;
    }
    
    vector<vector<long long>> get_all_pair_shortest(vector<vector<pair<int,int>>>& adj_list, int n) {
        vector<vector<long long>> M(n, vector<long long>(n, INT_MAX));
        for(int i = 0; i < n; i++) {
            M[i][i] = 0;
            for(auto& j : adj_list[i])
                M[i][j.first] = j.second;
        }
        
        for(int i = 0; i < n; i++) {
            vector<vector<long long>> temp = M;
            for(int x = 0; x < n; x++) {
                if(x == i)
                    continue;
                for(int y = 0; y < n; y++) {
                    if(y == i)
                        continue;
                    if(M[x][y] > M[x][i] + M[i][y])
                        temp[x][y] = M[x][i] + M[i][y];
                }
            }
            M = temp;
        }
        return M;
    }
};