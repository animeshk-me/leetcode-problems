class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int max_sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() / 2; i++) 
            max_sum = max(max_sum, nums[i] + nums[nums.size()-1 - i]);
        return max_sum;
    }
};