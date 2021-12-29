class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n <= 1) return n;
        vector<int> nums(n+1, -1);
        nums[0] = 0;
        nums[1] = 1;
        int max_val = 0;
        for(int i = 2; i <= n; i++) {
            nums[i] = nums[i/2];
            if(i % 2 != 0)
                nums[i] += nums[i/2 + 1];
            max_val = max(max_val, nums[i]);
        }
        return max_val;
    }
};