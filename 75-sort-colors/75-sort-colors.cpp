class Solution {
public:
    void sortColors(vector<int>& nums) {
        QS(nums, 0, nums.size()-1);
        
        
    }
    
    void QS(vector<int> &nums, int x, int y) {
        if(x >= y)
            return;
        int p = partition(nums, x, y);
        QS(nums, x, p-1);
        QS(nums, p+1, y);
    }
    
    int partition(vector<int> &nums, int x, int y) {
        int l = x;
        int i = x;
        while(i != y) {
            if(nums[i] < nums[y]) {
                swap(nums[i], nums[l]);
                l++;
            }
            i++;
        }
        swap(nums[y], nums[l]);
        return l;
    }
    
};