//Time:  O(N^2);
//Space: O(N);
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        unordered_set<int> s;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0)
            return false;
        sum/=2;
        s.insert(0);
        for(int i=0;i<nums.size();i++){
            unordered_set<int> temp;
            for(auto x: s){
                if(x+nums[i] == sum)
                    return true;
                if(x+nums[i] < sum)
                    temp.insert(x + nums[i]);
                temp.insert(x);
            }
            s = temp;
        }
        return false;
    }
};
