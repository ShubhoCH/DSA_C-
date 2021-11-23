//Time:  O(N);
//Space: O(N);
class Solution {
public:
     int maxSumMinProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>left(n,-1);
        vector<int>right(n,n);
        stack<int>s1,s2;
        for(int i=0;i<n;i++){
            while(!s1.empty() and nums[s1.top()]>nums[i])
            {
                right[s1.top()]=i;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() and nums[s2.top()]>nums[i])
            {
                left[s2.top()]=i;
                s2.pop();
            }
            s2.push(i);
        }
        vector<long long int>prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
            prefix[i]=prefix[i-1]+nums[i];
        long long int ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long int x=nums[i]*(prefix[right[i]-1]-((left[i]==-1)?0:prefix[left[i]]));
            ans=max(ans,x);
        }
        return ans%1000000007;
        
    }
};
