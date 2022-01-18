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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return inorder(root, k, count);
    }
    
    int inorder(const TreeNode* root, const int k, int &count) {
        if(root == nullptr)
            return -1;
        
        int found_left = inorder(root->left, k, count);
        if(found_left != -1)
            return found_left;
        
        if(count == k-1)
            return root->val;
        count++;
        
        int found_right = inorder(root->right, k, count);
        if(found_right != -1)
            return found_right;
        
        return -1;
    }
};