//Time:  O(N^2);
//Space: O(1);
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        for(int i = 1;i<=rowIndex;i++){
            int previous = 1;
            for(int j=1;j<i;j++){
                int temp = previous + ans[j];
                previous = ans[j];
                ans[j] = temp;
            }
            ans.push_back(1);
        }
        return ans;
    }
};
