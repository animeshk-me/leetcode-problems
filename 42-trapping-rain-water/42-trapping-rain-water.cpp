class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> max_left(n, 0);
        vector<int> max_right(n, 0);
        
        max_left[0] = height[0];
        for(int i = 1; i < n; i++) 
            max_left[i] = max(max_left[i-1], height[i]);
        
        max_right[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--)
            max_right[i] = max(max_right[i+1], height[i]);
        
        int water_amount = 0;
        for(int i = 0; i < n; i++)
            water_amount += (min(max_left[i], max_right[i]) - height[i]);
        
        return water_amount;
    }
};