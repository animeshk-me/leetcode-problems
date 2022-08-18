class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_val = nums[0];
        int max_diff = -1;
        for(int i = 1; i < nums.size(); i++) {
            if(min_val < nums[i]) 
                max_diff = max(max_diff, nums[i] - min_val);
            min_val = min(min_val, nums[i]);
        }
        return max_diff <= 0 ? -1 : max_diff;
    }
};