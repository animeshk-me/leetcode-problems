class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<int> indices(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) indices[i] = i;
        auto comp = [nums](auto& a, auto& b) { return nums[a] < nums[b]; };
        sort(indices.begin(), indices.end(), comp);
        
        int i = 0;
        int j = nums.size() - 1;
        while(i < j) {
            int diff = nums[indices[i]] + nums[indices[j]] - target;
            if(diff == 0) {
                ret = {indices[i], indices[j]};
                break;
            } else if(diff < 0)
                i++;
            else
                j--;
        }
        return ret;
    }
};