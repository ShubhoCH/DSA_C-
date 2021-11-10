//Time:  O(N);
//Space: O(N);
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans = "", temp = "";
        unordered_map<int, int> mp;
        
        if(!numerator){
            return "0";
        }
        if(numerator > 0 and denominator < 0 or numerator < 0 and denominator > 0){
            temp += '-';
        }
        long n = abs(numerator);
        long d = abs(denominator);
        
        ans += to_string(n/d);
        n %= d;
        if(n){
            ans += '.';
            while(n and mp.find(n) == mp.end()){
                mp[n] = ans.size();
                n *= 10;
                ans += to_string(n/d);
                n %= d;
            }
            if(n){
                ans = ans.substr(0, mp[n]) + '(' + ans.substr(mp[n]) + ')';
            }
        }
        return temp + ans;
    }
};
