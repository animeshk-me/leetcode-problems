class Solution {
public:
    string reverseWords(string s) {
        istringstream my_stream(s);
        string fin_str = "";
        string str;
        while(my_stream >> str) 
            fin_str = fin_str.empty() ? str : str + " " + fin_str;
        return fin_str;
    }
};