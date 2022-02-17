class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int glob_sum = sum;
        for(int i = 1; i < nums.size(); i++) {
            if(sum < 0)
                sum = nums[i];
            else 
                sum += nums[i];
            glob_sum = max(glob_sum, sum);
        }
        return glob_sum;
    }
};