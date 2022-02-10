class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int major_el = 0;
        for(int n : nums) {
            if(count == 0) {
                count++;
                major_el = n;
                continue;
            }
            if(n == major_el)
                count++;
            else
                count--;
        }
        return major_el;
    }
};