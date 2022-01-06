class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(int i = 0; i < address.size(); i++) 
            res = address[i] == '.' ? res+"[.]" : res+address[i];
        return res;
    }
    
};