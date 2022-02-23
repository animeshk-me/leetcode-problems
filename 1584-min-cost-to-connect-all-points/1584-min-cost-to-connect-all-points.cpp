class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    
    void make_set(int x) {
        parent[x] = x;
        rank[x] = 0;
    }
    
    void union_set(int u, int v) {
        link(find_set(u), find_set(v));
    } 
    
    void link(int a, int b)  {
        if(rank[a] > rank[b])
            parent[b] = a;
        else if(rank[a] < rank[b])
            parent[a] = b;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
    
    int find_set(int u) {
        if(parent[u] != u)
            parent[u] = find_set(parent[u]);
        return parent[u];
    }
    
    vector<pair<int,int>> get_edges(vector<vector<int>>& points) {
        vector<pair<int,int>> edges;
        for(int i = 0; i < points.size(); i++) {
            for(int j = i+1; j < points.size(); j++)
                edges.push_back({i, j});
        }
        return edges;
    }

    
    int cost(pair<int,int> edge, vector<vector<int>>& points) {
        return abs(points[edge.first][0] - points[edge.second][0]) + abs(points[edge.first][1] - points[edge.second][1]);
    }
    
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        parent = vector<int>(n, -1);
        rank = vector<int>(n, 0);
        for(int i = 0; i < n; i++)
            make_set(i);
        
        vector<pair<int,int>> edges = get_edges(points);
        // sort(edges.begin(), edges.end(), [](auto a, auto b) {return cost(a, points) < cost(b, points);});
        sort(edges.begin(), edges.end(), [this, &points](pair<int,int> a, pair<int,int> b) {return cost(a, points) < cost(b, points);});
        int i = 0;
        for(auto edge : edges) {
            if(i == n)
                break;
            int u = edge.first, v = edge.second;
            if(find_set(u) != find_set(v)) {
                union_set(u, v);
                i++;
                min_cost += cost(edge, points);
            }
        }
        return min_cost;
    }
};