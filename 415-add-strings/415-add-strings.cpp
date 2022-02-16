class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size() < num2.size())
            normalize_str(num1, num2);
        else if(num1.size() > num2.size())
            normalize_str(num2, num1);
        string fin_sum = "";
        int i = num1.size();
        int carry = 0;
        while(i--) {
            int sum = num1[i] + num2[i] + carry - 2*'0';
            carry = sum / 10;
            fin_sum = (char)(sum%10 + '0') + fin_sum;
        }
        if(carry > 0)
            fin_sum = (char)(carry + '0') + fin_sum;
        return fin_sum;
    }
    
    void normalize_str(string &small, string &large) {
        small = string(large.size() - small.size(), '0') + small;
    }
};