class Solution {
public:
    int trap(vector<int>& height) {
        int left_sum = get_water_iterative(height);
        reverse(height.begin(), height.end());
        int right_sum = get_water_iterative(height);
        return left_sum + right_sum;
    }
    
    
    int get_water_iterative(vector<int>& height) {
        int area = 0;
        int idx = 0;
        int n = height.size();
        while(idx <= n - 2) {
            int min_boundary_height = height[idx];
            int i = idx + 1;
            while(i < n && height[i] < min_boundary_height) 
                i++;

            if(i == n) {
                idx = idx + 1;
                continue;
            }

            for(int j = idx + 1; j < i; j++) {
                area += min_boundary_height - height[j];
                height[j] = min_boundary_height;
            }
            
            idx = i;
        }
        return area;
    }
    
//     int get_water(int idx, vector<int>& height) {
//         if(idx > (int)(height.size() - 3))
//             return 0;
//         // cout << "hello\n";
//         int min_boundary_height = height[idx];
//         int i = idx + 1;
//         while(i < height.size() && height[i] < min_boundary_height) 
//             i++;
        
//         if(i == height.size())
//             return get_water(idx+1, height);
        
//         int temp_area = 0;
//         for(int j = idx + 1; j < i; j++) {
//             temp_area += min_boundary_height - height[j];
//             height[j] = min_boundary_height;
//         }
        
//         return temp_area + get_water(i, height);
//     } 
    // [23423,34534,34564,256,256,57235,4242,562,2422,4,24562,245,262,24244,2522]
};