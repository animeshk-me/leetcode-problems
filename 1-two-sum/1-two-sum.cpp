class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++) {
            auto it = map.find(target - nums[i]);
            if(it == map.end())
                map.insert({nums[i], i});
            else {
                ret = vector<int>({i, it->second});
                break;
            }
        }
        return ret;
    }
};