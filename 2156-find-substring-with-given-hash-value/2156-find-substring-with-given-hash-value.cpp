class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        unsigned long long p = 1;
        unsigned long long hash_calculated = 0;
        int n = s.size();
        
        unsigned long long prev_p;        
        for(int i = n-k; i <= n-1; i++) { 
            hash_calculated = (hash_calculated + (s[i] - 'a' + 1) * p) % modulo;
            prev_p = p;
            p = (p*power) % modulo;
        }
        int res_id = hash_calculated == hashValue ? n-k : 0;
        
        // cout << hash_calculated << endl;
        for(int i = n-k-1; i >= 0; i--) {
            hash_calculated = ((hash_calculated + modulo - ((s[i+k]-'a'+1)*prev_p) % modulo) * power + (s[i]-'a'+1)) % modulo;
            if(hash_calculated == hashValue)
                res_id = i;
            // cout << i << ": " << hash_calculated << endl;
        }
        return s.substr(res_id, k);
        
    }
};