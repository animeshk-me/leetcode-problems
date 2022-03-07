class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int count = 0;
        int n = nums.size();
        while(i < n - 1) {
            cout << i << endl;
            int m_j = i+1;
            int val = 0;
            int j;
            for(j = i+1; j < n && j <= i+nums[i]; j++) {
                if(val <= min(n-1, j + nums[j])) {
                    val = min(n-1, j + nums[j]);
                    m_j = j;
                }
            }
            count++;
            i = m_j;
        }
        return count;
    }
};