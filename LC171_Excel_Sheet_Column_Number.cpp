//Time: O(N);
//Space: O(1);
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        long long int val = 1;
        for(int i=columnTitle.length()-1;i>=0;i--){
            res+=(columnTitle[i]-'A'+1)*val;
            val*=26;
        }
        return res;
    }
};
