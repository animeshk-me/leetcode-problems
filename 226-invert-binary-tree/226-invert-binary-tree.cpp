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
        TreeNode* temp, *swap;
        while(!st.empty()) {
            temp = st.top();
            st.pop();
            swap = temp->right;
            temp->right = temp->left;
            temp->left = swap;
            if(temp->left != NULL)
                st.push(temp->left);
            if(temp->right != NULL)
                st.push(temp->right);
        }
        return root;
    }
};