class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int max_val = 1, max_id = 0;
        int temp_val = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i-1])
                temp_val++;
            else
                temp_val = 1;
            if(temp_val > max_val) {
                max_val = temp_val;
                max_id = i;
            }
            if(max_val > nums.size() / 2)
                return nums[max_id];
        }
        return nums[max_id];
    }
};