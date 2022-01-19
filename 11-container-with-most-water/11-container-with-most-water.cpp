class Solution {
public:
    int maxArea(vector<int>& height) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int i = 0;
        int j = height.size() - 1;
        int max_ar = 0;
        while(i < j) {
            max_ar = max(max_ar, (j-i) * min(height[i], height[j]));
            if(height[i] < height[j])
                i++;
            else 
                j--;
        }
        return max_ar;
    }
};