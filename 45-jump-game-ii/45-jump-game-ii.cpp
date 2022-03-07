class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> Memo(nums.size(), -1);
        return foo(0, nums, Memo);
    }
    
    int foo(int i, vector<int>& nums, vector<int>& Memo) {
        if(i == nums.size() - 1)
            return 0;
        if(Memo[i] == -1) {
            int min_val = INT_MAX;
            for(int j = 1; j <= nums[i]; j++) {
                if(i + j >= nums.size())
                    break;
                min_val = min(min_val, foo(i+j, nums, Memo));
            }
            Memo[i] = min_val == INT_MAX ? min_val : min_val + 1;
        }
        return Memo[i];
    }
};