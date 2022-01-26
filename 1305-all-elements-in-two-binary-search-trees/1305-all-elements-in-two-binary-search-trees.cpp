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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> vec;
        get_final_vec(root1, vec);
        get_final_vec(root2, vec);
        sort(vec.begin(), vec.end());
        return vec;
    }
    
    
    
    
    void get_final_vec(TreeNode* root, vector<int>& vec) {
        stack<TreeNode*> st;
        push_to_stack(st, root);
        while(!st.empty()) {
            TreeNode* temp = st.top();
            st.pop();
            vec.push_back(temp->val);
            push_to_stack(st, temp->right);
        }
    }
    
    void push_to_stack(stack<TreeNode*> &st, TreeNode* node) {
        TreeNode* temp = node;
        while(temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }
    }
    
};