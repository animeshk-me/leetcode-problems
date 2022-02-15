class Solution {
public:
    int getSum(int a, int b) {
        int A = max(abs(a), abs(b));
        int B = min(abs(a), abs(b));

        if(a * b >= 0) {
            int C = get_sum(A, B);
            return a < 0 || b < 0 ? -C : C;
        } 
        // cout << get_sum(~B, 1) << endl;
        // cout << A << ", " << B << endl;
        int C = get_sum(A, get_sum(~B, 1));
        return (abs(a) == A && a < 0) || (abs(b) == A && b < 0)  ? -C : C;
        // return 0;
    }
    
    int get_sum(int A, int B) {
        // cout << "hello " << A << ", " << B << endl;
        int c = 0;
        unsigned long long i = 1;
        int carry = 0;
        int x = 32;
        while(x--) {
            int b1 = A&1, b2 = B&1;
            int sum = b1 ^ b2 ^ carry;
            carry = (b1&b2) | (carry&(b1^b2));
            // cout << sum << ", " << carry << ", " << i << ", " << A << ", " << B << ", " << c << endl;
            c = sum == 0 ? c : c^i;
            i <<= 1;
            A >>= 1;
            B >>= 1;
        }
        if(carry == 1)
            c = c^i;
        // cout << "hi " << c << endl;
        return c;
        
    }
};

/*
998
587
423
935
-1000
-200
-400
-300
1000
-542
-321
999
99
-1000
-987
14 */