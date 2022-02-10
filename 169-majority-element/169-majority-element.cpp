class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hashmap;
        for(int n : nums) {
            auto it = hashmap.find(n);
            if(it == hashmap.end())
                hashmap[n] = 1;
            else
                it->second++;
        }
        for(auto &it : hashmap) {
            if(it.second > (nums.size() / 2))
                return it.first;
        }
        return 0;
    }
};