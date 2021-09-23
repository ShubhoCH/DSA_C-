#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    //NAIVE SOLUTION:		
    int find(vector<int> v, int index, int val, int n){
        for(int i = 0;i<n;i++){
            if(i==index)
                continue;
            else{
                if(v[i]==val)
                    return i;
            }
        }  
        return -1;
    };
    vector<int> twoSum(vector<int>& nums, int target) {
        int temp, index, n = nums.size();
        vector<int> ans;
        for(int i =0;i<n;i++){
            temp = target - nums[i];
            index = find(nums,i,temp,n);
            if(index!=-1)
            {
                ans.push_back(i);
                ans.push_back(index);
                break;
            }
        }
        return ans;
    };
    //OPTIMISED SOLUTION
     vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            if(map.find(target - nums[i]) != map.end()){
                ans.push_back(i);
                ans.push_back(map[target - nums[i]]);
                return ans;
            }
            map[nums[i]] = i;
        }
        return ans;
    };
};
int main(){
	vector<int> v;
	int n,x,target;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>x;
		v.push_back(x);
	}
	cin>>target;
	Solution s;
	vector<int> vv = s.twoSum(v,target);
	cout<<vv[0]<<" "<<vv[1];
	return 0;
}
