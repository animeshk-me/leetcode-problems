class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        int prev_prev = 1;
        int prev = 2;
        for(int i = n-3; i >= 0; i--) {
            int temp = prev + prev_prev;
            prev_prev = prev;
            prev = temp;
        }    
        return prev;
    }
};