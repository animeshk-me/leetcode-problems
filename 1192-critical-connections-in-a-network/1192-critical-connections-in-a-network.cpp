class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj = get_adj(connections, n);
        vector<vector<int>> critical_edges;
        vector<int> discovery_time(n, -1);
        vector<int> parent(n, -1);
        vector<int> min_time(n, -1);
        int t = 0;
        DFS(0, discovery_time, min_time, t, adj, parent, critical_edges);
        // for(auto& x : discovery_time)   cout << x << " "; cout << endl;
        // for(auto& x : parent)   cout << x << " "; cout << endl;
        return critical_edges;
    }
    
    vector<vector<int>> get_adj(vector<vector<int>>& connections, int n) {
        vector<vector<int>> adj(n, vector<int>());
        for(auto& c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        return adj;
    }
    
    void DFS(int u, vector<int>& discovery_time, vector<int>& min_time, int& t, vector<vector<int>>& adj, vector<int>& parent, vector<vector<int>>& critical_edges) {
        discovery_time[u] = t;
        min_time[u] = t;
        t++;
        for(auto& v : adj[u]) {
            if(discovery_time[v] == -1) {
                parent[v] = u;
                DFS(v, discovery_time, min_time, t, adj, parent, critical_edges);
            }
        }
        if(u == 0)
            return;
        for(auto& v : adj[u]) {
            if(v != parent[u])
                min_time[u] = min(min_time[u], min_time[v]);
        }
        if(discovery_time[parent[u]] < min_time[u])
            critical_edges.push_back({parent[u], u});
        t++;
    }
    
    
};