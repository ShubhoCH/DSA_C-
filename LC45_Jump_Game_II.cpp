//Pretty Slow:
class Solution {
public:
    int findMin(vector<int>& nums, int s, int i){
        if(i == nums.size()-1)
            return s;
        int max = nums[i];
        vector<int>v;
        for(int j=1;j<=max;j++)
            v.push_back(findMin(nums,s+1,i+j));
        int min = INT_MAX ;
        for(int i=0;i<max;i++)
            if(min > v[i])
                min = v[i];
        return min;
    }
    int jump(vector<int>& nums) {
        return findMin(nums, 0, 0);
    }
};
//O(N):
class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,s=0;
        while(r<nums.size()-1){
            int far=0;
            for(int i=l;i<=r;i++)
                far = max(far,nums[i]+i);
            l=r+1;
            r=far;
            s++;
        }
        return  s;
    }
};
