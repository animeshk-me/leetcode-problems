class Solution {
public:
    int climbStairs(int n) {
        vector<int> Memo(n+1, -1);
        return foo(n, Memo);
    }
    
    int foo(int n, vector<int>& Memo) {
        if(n <= 2)
            return n;
        if(Memo[n] == -1)
            Memo[n] = foo(n-1, Memo) + foo(n-2, Memo);
        return Memo[n];
    }
};