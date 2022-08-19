class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_val = 0;
        int min_buy = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            max_val = max(max_val, prices[i] - min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        return max_val;
    }
};