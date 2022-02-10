class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        long m = abs(n);
        double pow = 1;
        while(m != 0) {
            if(m & 1 == 1)
                pow *= x;
            x *= x;
            m >>= 1;
        }
        return n < 0 ? (double)1 / (double)(pow) : pow;   
    }
};