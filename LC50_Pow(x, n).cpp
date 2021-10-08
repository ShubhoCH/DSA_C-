class Solution {
public:
    double myPow(double x, int n) {
        return pow(x,n);
        if (n == 0)
            return 1.00000;
        if (n == 1)
            return x;
        if (n == -1)
            return 1 / x;
        int p = 1;
        bool pos = false;
        if((x<0 && n%2 == 0) || x > 0)
            pos = true;
        if (n < 0)
            p = -1;
        if (p > 0) {
            while (p * 2 < n) {
                p *= 2;
                x *= x;
            }
            double temp = x;
            int num = p;
            while (num != n) {
                if (p + num <= n) {
                    num += p;
                    x *= temp;
                }
                else {
                    p /= 2;
                    temp = sqrt(temp);
                }
            }
        }
        else {   
            x = 1 / x;
            while (p * 2 >= n) {
                p *= 2;
                x *= x;
            }
            double temp = x;
            int num = p;
            while (num != n) {
                if (p + num >= n) {
                    num += p;
                    x *= temp;
                }
                else {
                    p /= 2;
                    temp = sqrt(abs(temp));
                }
            }
        }
        if(pos)
            x = abs(x);
        else if(x > 0)
                x = -x;
        return x;
    }
};
