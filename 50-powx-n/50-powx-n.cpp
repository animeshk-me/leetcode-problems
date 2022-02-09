class Solution {
public:
    
    
    double myPow(double x, int n) {
        if(x == 0)
            return 0;
        map<long, double> Memo;
        double pow = my_pow(x, abs(n), Memo);
        return n < 0 ? (double)1 / (double)(pow) : pow;        
    }
    
    double my_pow(double x, long n, map<long, double> &Memo) {
        if(n == 0)
            return 1;
        if(x == 0 || n == 1)
            return x;
        if(Memo.find(n) == Memo.end()) 
            Memo[n] = my_pow(x, n/2, Memo) * my_pow(x, n - n/2, Memo);
        return Memo[n];
    }
};
