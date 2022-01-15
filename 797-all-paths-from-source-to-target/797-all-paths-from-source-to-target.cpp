class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths = find_all_paths(0, graph);
        for(auto &path: paths)
            reverse(path.begin(), path.end());
        return paths;
    }
    
    vector<vector<int>> find_all_paths(int source, vector<vector<int>> & graph) {
        vector<vector<int>> paths, rec_paths;
        if(source == graph.size() - 1) 
            paths.push_back(vector<int>(1, source));
        else {
            for(int v : graph[source]) {
                rec_paths = find_all_paths(v, graph);
                for(auto &path : rec_paths)
                    path.push_back(source);
                paths.insert(paths.end(), rec_paths.begin(), rec_paths.end());
            }
        }
        return paths;
    }
};