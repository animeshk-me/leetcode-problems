class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> Memo(cost.size(), -1);
        return min(get_min(0, cost, Memo), get_min(1, cost, Memo));        
    }
    
    int get_min(int x, vector<int> &cost, vector<int> &Memo) {
        if(x >= cost.size())
            return 0;
        if(Memo[x] == -1)
            Memo[x] = cost[x] + min(get_min(x+1, cost, Memo), get_min(x+2, cost, Memo));
        return Memo[x];
    }
    
};