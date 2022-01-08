class Solution {
public:
    int minOperations(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
        int c = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i-1]) {
                c += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1]+1;
            }
        }
        return c;
    }
};