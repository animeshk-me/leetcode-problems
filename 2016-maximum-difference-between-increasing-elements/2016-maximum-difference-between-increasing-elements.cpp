class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int max_val = -1;
        int i = 0;
        int n = nums.size();
        vector<bool> visit(n, false);
        while(i != n) {
            if(visit[i]) {
                i++;
                continue;
            }
            int min_v = nums[i];
            int max_v = min_v;
            visit[i] = true;
            for(int j = i; j < n; j++) {
                if(nums[j] >= max_v) {
                    max_v = nums[j];
                    visit[j] = true;
                }
            }
            max_val = max(max_val, max_v - min_v);
            i++;
        }
        return max_val > 0 ? max_val : -1;
    }
};