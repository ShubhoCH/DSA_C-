class Solution {
public:
    int myAtoi(string s) {
        short int sign = 1;
        long long ans = 0;
        while(s[0] == ' ')
            s=s.substr(1);
        if(s[0] == '-'){
            sign = -1;
            s = s.substr(1);
        }
        else if(s[0] == '+')
            s = s.substr(1);
        unsigned int limit = pow(2,32)/2;
        for(int i=0;i<s.length();i++){
            if( s[i]>=48 && s[i] <= 57 ){
                ans = ans*10 + ( s[i] - 48 );
                if(ans > limit)
                    break;
            }
            else
                break;
        }
        ans*=sign;
        ans = (ans < -pow(2,32)/2) ? -pow(2,32)/2 : (ans > pow(2,32)/2-1) ? pow(2,32)/2 - 1 : ans;
        return ans;
        
    }
};
