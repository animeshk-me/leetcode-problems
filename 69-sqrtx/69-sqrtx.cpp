class Solution {
public:
    int mySqrt(int x) {
        if(x < 2)
            return x;
        return BS(1, x-1, x);
    }
    
    int BS(int l, int h, int x) {
        if(h < l)
            return 0;
        long double mid = l + (h - l) / 2;
        long double val = x / mid;
        long double next_val = x / (mid+1);
        if(mid == val)
            return mid;
        if(mid > val)
            return BS(l, mid-1, x);
        if(mid+1 > next_val)
            return mid;
        return BS(mid+1, h, x);
    } // 2147395599
};