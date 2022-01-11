//Time:  O(N);
//Space: O(1);
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> v (n+1, true);
        for(int i=2;i*i<=n;i++){
            if(v[i]){
                for(int j=i;i*j<=n;j++)
                    v[i*j] = false;
            }
        }
        int ans = 0;
        for(int i=2;i<n;i++)
            if(v[i])
                ans++;
        return ans;
    }
};
