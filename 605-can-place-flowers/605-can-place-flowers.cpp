class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int i = 0;
        int sum = 0;
        while(i < size) {
            while(i < size && flowerbed[i] != 0)
                i++;
            if(i == size)
                break;
            
            int start = i;
            while(i < size && flowerbed[i] == 0)
                i++;
            int num_zeros = i - start;
            if(start > 0 && flowerbed[start-1] == 1)
                num_zeros--;
            if(i < size && flowerbed[i] == 1)
                num_zeros--;
            sum += ceil((float)num_zeros/(float)2);
            if(sum >= n)
                return true;
        }
        return sum >= n;
        
    }
};