class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val = 0;
        int t = 0;
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] < prices[t])
                t = i;
            else 
                max_val = max(max_val, prices[i] - prices[t]);
        }
        return max_val;
    }
};