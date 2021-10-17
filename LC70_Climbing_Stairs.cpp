//Slow:
class Solution {
public:
    void Climb(int n, int i, int& count, vector<int>& dp){
        if(i>n)
            return;
        if(dp[i] != -1){
            count+=dp[i];
            return;
        }
        if(i==n){
            count++;
            return;
        }
        Climb(n,i+1,count, dp);
        Climb(n,i+2,count, dp);
        dp[i] = count;
    }
    int climbStairs(int n) {
        int count = 0;
        vector<int> v;
        for(int i=0;i<=n;i++)v.push_back(-1);
        Climb(n,0, count, v);
        return count;
    }
};
//Super_Fast:
class Solution {
public:
    int climbStairs(int n) {
        int count = 0;
        vector<int> v;
        v.push_back(1);
        v.push_back(1);
        for(int i = 2; i<=n ;i++)
            v.push_back(v[i-1]+v[i-2]);
        return v[n];
    }
};
