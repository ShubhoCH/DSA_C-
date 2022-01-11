//Time:  O(N);
//Space: O(1);
class Solution {
public:
    vector<int> twoSum(vector<int>& num, int t) {
        int l = 0, r = num.size()-1;
        while(r>l){
            if(num[l]+num[r]==t)
                return {l+1, r+1};
            if(num[l]+num[r]>t)
                r--;
            else
                l++;
        }
        return {};
    }
};
