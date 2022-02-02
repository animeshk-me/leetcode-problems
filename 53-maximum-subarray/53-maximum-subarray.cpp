class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int i = 1;
        int s = 0;
        int S = s;
        int E = i;
        int max_sum = sum;
        while(i < nums.size()) {
            if(sum < 0) {
                s = i;
                sum = nums[i];
            }
            else
                sum += nums[i];
            if(sum > max_sum) {
                S = s;
                E = i;
                max_sum = sum;
            }
            i++;
        }
        cout << S << ", " << E << endl;
        return max_sum;
        
    }
};