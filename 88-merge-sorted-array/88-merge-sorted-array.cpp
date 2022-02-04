class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i = 0; i < n; i++) 
            nums1[m+i] = nums2[i];
        
        int i = 0, j = m;
        while(j < m+n && i < j) {
            if(nums1[i] > nums1[j]) {
                i_swap(j, i, nums1);
                j++;
            }
            i++;
        }
    }
    
    void i_swap(int j, int i, vector<int> &a) {
        for(int k = j; k > i; k--)
            swap(a[k], a[k-1]);
    }
};