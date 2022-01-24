//Time: O(N);
//Space: O(1);
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2)
            return min(cost[0], cost[1]);
        int first = cost[0], second = cost[1];
        int ans = 0;
        for(int i = 2; i<=cost.size();i++){
            ans = min(first, second);
            int temp = second;
            if(i!=cost.size()){
                second = min(first, second) + cost[i];
                first = min(temp, first + cost[i-1]);
            }
        }
        return ans;
    }
};
