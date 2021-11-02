//Time:  O(N);
//Space: O(1);
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min, max_profit=0;
        min = prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i] < min)
                min = prices[i];
            else if(prices[i] - min > max_profit)
                max_profit = prices[i] - min;
        }
        return max_profit;
    }
};
