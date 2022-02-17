class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> a;
        for(int i = 0; i < nums.size(); i++)
            a.push_back({nums[i], i});
        sort(a.begin(), a.end());
        int i = 0;
        int j = a.size() - 1;
        while(i < j) {
            long long a_i = target - a[j].first;
            if(a_i == a[i].first)
                break;
            if(a_i > a[i].first)
                i++;
            else
                j--;
        }
        return {a[i].second, a[j].second};
        
    }
};