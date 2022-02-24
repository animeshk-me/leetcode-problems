class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        auto adj = get_adj_list(n, edges, succProb);
        // for(int i = 0; i < n; i++) {
        //     cout << i << ": ";
        //     for(auto x : adj[i])
        //         cout << "(" << x.first << "," << x.second << "), ";
        //     cout << endl;
        // }
        auto comp = [this](auto& a, auto& b) {return a.second < b.second;};
        priority_queue<pair<int,double>, vector<pair<int,double>>, decltype(comp)> pq(comp);
        vector<double> key(n, 0.0);
        key[start] = 1;
        pq.push({start, key[start]});
        
        int i = 0;
        while(!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            int u = node.first;
            double k = node.second;
            if(k != key[u])
                continue;
            for(auto v : adj[u]) {
                double val = (k * v.second) ;
                if(key[v.first] < val) {
                    key[v.first] = val;
                    pq.push({v.first, key[v.first]});
                } 
            }
            i++;
        }
        return key[end];
    }
    
    
    vector<vector<pair<int,double>>> get_adj_list(int n, vector<vector<int>>& edges, vector<double>& succProb) {
        vector<vector<pair<int,double>>> adj(n, vector<pair<int,double>>());
        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        return adj;
    }
};