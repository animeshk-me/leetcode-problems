class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        auto adj = get_adj_list(n, edges);    
        vector<vector<int>> fin_vec(n, vector<int>());
        for(int i = 0; i < n; i++) {
            vector<bool> visit(n, false);    
            DFS(i, i, visit, fin_vec, adj);
        }
        return fin_vec;
    }
    
    
    void DFS(int u, int src, vector<bool>& visit, vector<vector<int>>& fin_vec, vector<vector<int>>& adj) {
        visit[u] = true;
        for(int v : adj[u]) {
            if(visit[v])
                continue;
            fin_vec[v].push_back(src);
            DFS(v, src, visit, fin_vec, adj);
        } 
    }
    
    
    vector<vector<int>> get_adj_list(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto& edge : edges)
            adj[edge[0]].push_back(edge[1]);
        return adj;
    }
};