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
    int sumNumbers(TreeNode* root) {
        int fin_sum = 0;
        foo(root, 0, fin_sum);
        return fin_sum;
    }
    
    void foo(TreeNode* root, int sum, int& fin_sum) {
        if(root == nullptr)
            return;
        sum = sum*10 + root->val;
        if(root->left == nullptr && root->right == nullptr) {
            fin_sum += sum;
            return;
        }
        if(root->left != nullptr)
            foo(root->left, sum, fin_sum);
        if(root->right != nullptr)
            foo(root->right, sum, fin_sum);
    }
};