class Solution {
public:
    int maximum69Number (int num) {
        int lat = -1;
        int m = num;
        int p = 0;
        while(m != 0) {
            int val = m % 10;
            if(val == 6)
                lat = p;
            m /= 10;
            p++;
        }
        if(lat == -1)
            return num;
        return num + 3*pow(10, lat);
    }
};