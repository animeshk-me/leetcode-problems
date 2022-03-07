class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long sum = 0;
        long long j = 1;
        for(int i = 0; i < nums.size(); i++) {
            if(j > nums[i])
                continue;
            if(j == nums[i])
                j++;
            else {
                long long l = min((long long)nums[i] - j, (long long)k);
                k -= l;
                sum += l * (2*j + l - 1) * 0.5;
                if(k == 0)
                    break;
                j = nums[i] + 1;
            }
        }

        return k == 0 ? sum : sum + k * (2*j + k - 1) * 0.5;
        
    }
};