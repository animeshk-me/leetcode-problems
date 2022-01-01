class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string fin_str = "";
        string str = string(nums[0].size(), '0');
        gen_str(str, 0, fin_str, nums);
        return fin_str;
    }
    
    void gen_str(string str, int id, string &fin_str, vector<string>& nums) {
        if(fin_str != "")
            return;
        if(find(nums.begin(), nums.end(), str) == nums.end()){ 
            fin_str = str;
            return;
        }
        if(id == str.size()) 
            return;
        str[id] = '1';
        gen_str(str, id+1, fin_str, nums);
        str[id] = '0';
        gen_str(str, id+1, fin_str, nums);
    }
};