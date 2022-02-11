/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<TreeNode*,int> dist;
        int min_d = INT_MAX;
        int max_d = INT_MIN;
        get_dist(root, 0, dist, min_d, max_d);
        // for(auto it : dist) {
        //     cout << it.first << ": " << it.second << endl;
        // }
        return level_order_bfs(root, dist, min_d, max_d);
    }
    
    vector<vector<int>> level_order_bfs(TreeNode* root, unordered_map<TreeNode*,int> &dist, int min_d, int max_d) {
        vector<vector<int>> fin_vec(max_d - min_d + 1, vector<int>());
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            int size = Q.size();
            unordered_map<int, vector<int>> bucket;
            while(size--) {
                TreeNode* temp = Q.front();
                Q.pop();
                if(temp->left)
                    Q.push(temp->left);
                if(temp->right)
                    Q.push(temp->right);
                int d = dist[temp];
                auto it = bucket.find(d);
                if(it != bucket.end())
                    it->second.push_back(temp->val);
                else 
                    bucket[d] = {temp->val};
            }
            for(auto &it : bucket) {
                int idx = it.first - min_d;
                sort(it.second.begin(), it.second.end());
                fin_vec[idx].insert(fin_vec[idx].end(), it.second.begin(), it.second.end());
            }
        }
        return fin_vec;
    }
    
    void get_dist(TreeNode*root, int d, unordered_map<TreeNode*,int> &dist, int &min_d, int &max_d) {
        if(root == nullptr)
            return;
        dist[root] = d;
        min_d = min(min_d, d);
        max_d = max(max_d, d);
        get_dist(root->left, d-1, dist, min_d, max_d);
        get_dist(root->right, d+1, dist, min_d, max_d);
    }

};