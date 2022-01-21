class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        return bin_search(piles, 1, piles[piles.size() - 1], h);
    }
    
    int bin_search(const vector<int> &piles, int low, int high, int h) {
        if(low > high)
            return -1;
        if(low == high) 
            return get_val(piles, low) <= h ? low : -1;
        if(low == high - 1) {
            if(get_val(piles, low) <= h) 
                return low;
            else if(get_val(piles, high) <= h)
                return high;
            else 
                return -1;
        }
        int mid = low + (high - low) / 2;
        if(get_val(piles, mid) <= h) {
            int ret_val = bin_search(piles, low, mid-1, h);
            if(ret_val == -1)
                return mid;
            return ret_val;
        }
        else
            return bin_search(piles, mid+1, high, h);
    }
    
    int get_val(const vector<int> &piles, int k) {  
        int val = 0;
        for(int pile : piles)
            val += ceil((long double)pile / (long double)k);
        return val;
    }
};