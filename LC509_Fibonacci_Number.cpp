//Time:  O(N);
//Space: O(N);
class Solution {
public:
    unordered_map<int,int> map;
    int helper(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(map[n]) return map[n];
        map[n] = helper(n-1) + helper(n-2);
        return map[n];
    }
    int fib(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        return helper(n-1) + helper(n-2);
    }
};
