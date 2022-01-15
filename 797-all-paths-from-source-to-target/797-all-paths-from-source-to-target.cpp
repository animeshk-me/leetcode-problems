class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> paths;
        find_all_paths(0, graph, path, paths);
        return paths;
    }
    
    void find_all_paths(int source, vector<vector<int>> & graph, vector<int> &path, vector<vector<int>> &paths) {
        path.push_back(source);
        if(source == graph.size() - 1) 
            paths.push_back(path);
        else {
            for(int v : graph[source]) 
                find_all_paths(v, graph, path, paths);
        }
        path.pop_back();
    }
};