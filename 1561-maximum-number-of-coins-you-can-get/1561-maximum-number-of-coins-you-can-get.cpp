class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());
        int i = piles.size() - 2;
        int count = 0;
        int n = piles.size() / 3;
        while(i >= n) {
            count += piles[i];
            i -= 2;
        }
        return count;
    }
};