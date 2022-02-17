class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = find_k(0, n - 1, nums);
        int clue = n - k;
        if(clue == n)
            return regular_bs(0, n - 1, target, nums);
        if(target >= nums[clue] && target <= nums[n-1])
            return regular_bs(clue, n - 1, target, nums);
        return regular_bs(0, clue - 1, target, nums);
    }
    
    int regular_bs(int l, int h, int target, vector<int>& a) {
        if(l > h)
            return -1;
        if(l == h)
            return a[l] == target ? l : -1;
        int mid = l + (h-l) / 2;
        if(a[mid] == target)
            return mid;
        if(a[mid] > target)
            return regular_bs(l, mid-1, target, a);
        return regular_bs(mid+1, h, target, a);
    }
    
    int find_k(int l, int h, vector<int>& a) {
        if(l == h)
            return l;
        if(l == h-1)
            return a[l] < a[h] ? 0 : a.size() - h;
        int mid = l + (h - l) / 2;
        if(a[mid-1] > a[mid])
            return a.size() - mid;
        if(a[mid] < a[l])
            return find_k(l, mid, a);
        return find_k(mid, h, a);
    }
};