class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i = piles.size() - 2;
        int j = 0;
        int count = 0;
        while(j < i) {
            count += piles[i];
            i -= 2;
            j++;
        }
        return count;
    }
};