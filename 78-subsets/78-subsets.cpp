class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> vec;
        get_all_subsets(1, vec, nums, subsets);
        vec.push_back(nums[0]);
        get_all_subsets(1, vec, nums, subsets);
        return subsets;
    }
    
    void get_all_subsets(int i, vector<int> vec, vector<int> & nums, vector<vector<int>>& subsets) {
        if(i == nums.size()) {
            subsets.push_back(vec);
            return;
        }
        get_all_subsets(i+1, vec, nums, subsets);
        vec.push_back(nums[i]);
        get_all_subsets(i+1, vec, nums, subsets);
    }
    
};