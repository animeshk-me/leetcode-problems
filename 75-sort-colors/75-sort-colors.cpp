class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> arr(3, 0);
        for(int n: nums)
            arr[n]++;
        int i = 0;
        for(int j = 0; j < 3; j++) {
            for(int x = 0; x < arr[j]; x++)
                nums[i+x] = j;
            i += arr[j];
        }
    }
};