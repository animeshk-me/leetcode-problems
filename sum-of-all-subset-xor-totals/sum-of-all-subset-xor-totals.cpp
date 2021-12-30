class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        run_back_track(0, 0, sum, nums);
        return sum;
    }
    
    void run_back_track(int id, int xo, int &sum, vector<int> &nums) {
        if(id == nums.size()) {
            sum += xo;
            return;
        }
        run_back_track(id+1, xo, sum, nums);
        run_back_track(id+1, xo^nums[id], sum, nums);
    }
};