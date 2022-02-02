class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int i = 1;
        int max_sum = sum;
        while(i < nums.size()) {
            sum = sum < 0 ? nums[i] : sum + nums[i];
            max_sum = max(max_sum, sum);
            i++;
        }
        return max_sum;
        
    }
};