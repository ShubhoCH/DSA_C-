//O((logN)^2):
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend == INT_MIN) return INT_MAX;
            else return -dividend;
        }
        bool sign = (dividend < 0) ^ (divisor < 0);
        dividend = dividend > 0 ? -dividend:dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        int ans = 0;
        while(dividend <= divisor){
            int count =1, res = divisor;
            while(res > INT_MIN>>1 && dividend <= res + res){
                count += count;
                res += res;
            }
            ans += count;
            dividend -= res;
        }
        return (sign)?-ans: ans;
    }
};
//O(logN)
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)
            return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend == INT_MIN) return INT_MAX;
            else return -dividend;
        }
        bool sign = (dividend < 0) ^ (divisor < 0);
        dividend = dividend > 0 ? -dividend:dividend;
        divisor = divisor > 0 ? -divisor : divisor;
        int ans = 0, count = 1, res = divisor;
        while(res >= INT_MIN>>1 && dividend <= res + res){
            count <<= 1;
            res += res;
        }
        while(dividend<=divisor){
            if(dividend<=res){
                dividend-=res;
                ans+=count;
            }
            res>>=1;
            count>>=1;
        }
        return (sign)?-ans: ans;
    }
};
