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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> roots;
        if((n & 1) == 0)
            return roots;
        if(n == 1) {
            roots.push_back(new TreeNode(0));
            return roots;
        }
        vector<vector<TreeNode*>> child_roots((n-1)/2, vector<TreeNode*>());
        for(int i = 1; i <= n-1; i += 2) {
            if(child_roots[i/2].size() == 0)
                child_roots[i/2] = allPossibleFBT(i);
            if(child_roots[(n-1-i)/2].size() == 0)
                child_roots[(n-1-i)/2] = allPossibleFBT(n-1-i);
            for(TreeNode* left_root : child_roots[i/2]) {
                for(TreeNode* right_root : child_roots[(n-1-i)/2]) {
                    roots.push_back(new TreeNode(0, left_root, right_root));
                }
            }
        }
        return roots;
    }
};