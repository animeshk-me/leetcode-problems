class Solution {
public:
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long st_max_sum = 0;
        long long arr_sum = 0;
        long long sum = 0;
        long long M = 1e9 + 7;
        cout << "len: " << arr.size() << endl;
        for(auto& a : arr) {
            if(sum < 0)
                sum = 0;
            arr_sum += a;
            sum += a;
            st_max_sum = max(sum, st_max_sum);
        }
        if(k == 1)
            return st_max_sum % M;
        long long l_sum_max = 0, r_sum_max = 0;
        long long l_sum = 0, r_sum = 0;
        for(long long i = 0; i < arr.size(); i++) {
            l_sum += arr[i];
            l_sum_max = max(l_sum_max, l_sum);
            r_sum += arr[arr.size() - i - 1];
            r_sum_max = max(r_sum_max, r_sum);
        }
        cout << l_sum_max << ", " << r_sum_max << endl;
        long long sum1 = l_sum_max + r_sum_max;
        cout << "sum1 " << sum1 << endl;
        long long sum2 = max(sum1, st_max_sum);
        if(k == 2 || arr_sum <= 0)
            return sum2 % M;
        return max(sum1, mod_sum(mod_mul(arr_sum, k-2, M), sum1, M) ) % M;
    }
    

    long long mod_mul(long long a, long long b, long long mod) {
        a %= mod;
        b %= mod;
        long long product = a;
        while(b > 1) {
            if(b&1 == 0) {
                b >>= 1;
                product = mod_sum(product, product, mod);
            }
            else {
                b--;
                product = mod_sum(product, a, mod);
            }
        }
        return product;
    }

    
    long long mod_sum(long long a, long long b, long long mod) {
        a %= mod;
        b %= mod;
        long long c = mod - a;
        if(b > c)
            return b-c;
        return (a+b) % mod;
    }
    
    
    
};