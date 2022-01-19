class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        for(vector<int> &p : prerequisites) 
            adj[p[1]].push_back(p[0]);
        vector<int> color(numCourses, 0);
        for(int i = 0; i < color.size(); i++) {
            if(color[i] == 0) {
                color[i] = 1;
                if(has_cycle(i, adj, color))
                    return false;
                color[i] = 2;
            }
        }
        return true;
    }
    
    bool has_cycle(int u, const vector<vector<int>> &adj, vector<int> &color) {
        for(int v : adj[u]) {
            if(color[v] == 1)
                return true;
            if(color[v] == 2)
                continue;
            color[v] = 1;
            if(has_cycle(v, adj, color))
                return true;
        }
        color[u] = 2;
        return false;
    }
};