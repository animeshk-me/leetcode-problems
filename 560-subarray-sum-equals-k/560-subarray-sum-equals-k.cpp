class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    unordered_map<int,int> M;
    int pre_sum = 0;
    int count = 0;
    M.insert({pre_sum, 1});
    
    for(auto& x : nums) {
				// dynamically calculate pre_sum
        pre_sum += x;

				// check if a pre_sum2 exists
        auto it = M.find(pre_sum - k);
        if(it != M.end())
            count += it->second;

        // increment the count of pre_sum in the map M
				it = M.find(pre_sum);
        if(it != M.end())
            it->second++;
        else
            M.insert({pre_sum, 1});
    }
    return count;
}
};