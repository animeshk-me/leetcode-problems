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
        stack<TreeNode*> st1, st2;
        push_to_stack(st1, root1);
        push_to_stack(st2, root2);
        while(!st1.empty() && !st2.empty()) {
            TreeNode* temp1 = st1.top();
            TreeNode* temp2 = st2.top();
            TreeNode* temp = (temp1->val < temp2->val) ? temp1 : temp2;
            vec.push_back(temp->val);
            if(temp == temp1){
                st1.pop();
                push_to_stack(st1, temp->right);
            } else {
                st2.pop();
                push_to_stack(st2, temp->right);
            }
        }
        st1 = !st2.empty() ? st2 : st1;
        while(!st1.empty()) {
            TreeNode* temp = st1.top(); st1.pop();
            vec.push_back(temp->val);
            push_to_stack(st1, temp->right);
        }
        return vec;
    }
    
    void push_to_stack(stack<TreeNode*> &st, TreeNode* node) {
        TreeNode* temp = node;
        while(temp != nullptr) {
            st.push(temp);
            temp = temp->left;
        }
    }
    
};