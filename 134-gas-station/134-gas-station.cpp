class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        vector<int> vix(len, 0);
        for(int i = 0; i < len; i++)
            vix[i] = gas[i] - cost[i];
        
        
        
        vector<int> tax(len, 0);
        int i = 0;
        int prev = -1;
        int max_neg_i = 0;
        int max_neg = 0;
        while(1) {
            tax[i] = prev == -1 ? vix[i] : tax[prev] + vix[i];
            if(tax[i] < max_neg) {
                max_neg = tax[i];
                max_neg_i = i;
            }
            prev = i;
            i = (i+1) % len;
            if(i == 0)
                break;
        }
        
        if(tax[len-1] < 0)
            return -1;
        if(max_neg == 0)
            return 0;
        i = max_neg_i;
        while(1) {
            if(tax[max_neg_i] == tax[i] - vix[i])
                return i;
            i = (i+1) % len;
        }
        
    }
};