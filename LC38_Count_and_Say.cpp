class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string ans = "", s="";
        ans = countAndSay(n-1);
        if(ans == "1")
            return "11";
        for(int i=ans.length()-1;i>=0;i--){
            char temp = ans[i];
            int count = 1;
            while(i>0 && ans[i]  == ans[i-1]){
                i--;
                count++;
            }
            s = to_string(count) + temp + s;
        }
        return s;
    }
};
