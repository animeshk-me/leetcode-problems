class Solution {
public:
    
    int cost(pair<int,int> edge, vector<vector<int>>& points) {
        return abs(points[edge.first][0] - points[edge.second][0]) + abs(points[edge.first][1] - points[edge.second][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> mst_set(n, false);
        vector<int> parent(n, -1);
        vector<int> key(n, INT_MAX);
        key[0] = 0;
        auto comp = [this, &points](auto& a, auto& b) {return a.second > b.second;};
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        pq.push({0, key[0]});
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int u = temp.first;
            if(mst_set[u])
                continue;
            mst_set[u] = true;
            for(int v = 0; v < n; v++) {
                int weight = cost({u,v}, points);
                if(!mst_set[v] && key[v] > weight) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({v, key[v]});
                }
            }
        }
        return get_min_cost(parent, points);
    }
    
    int get_min_cost(vector<int>& parent, vector<vector<int>>& points) {
        int min_cost = 0;
        for(int i = 0; i < parent.size(); i++) {
            if(parent[i] != -1)
                min_cost += cost({i, parent[i]}, points);
        }
        return min_cost;
    }
};