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
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            if(temp == NULL)
                continue;
            TreeNode* right = temp->right;
            TreeNode* left = temp->left;
            temp->left = right;
            temp->right = left;
            st.push(temp->left);
            st.push(temp->right);
        }
        return root;
    }
};