class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = INT_MIN;
        int sum = 0;        
        for(auto& a : nums) {
            if(sum < 0)
                sum = 0;
            sum += a;
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};