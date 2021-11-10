//Time:  O(logN);
//Space: O(lonN);
class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> seen;
        double sum;
        while(n!=1 && seen.find(n)==seen.end()){
            sum = 0;
            seen[n] = true;
            while(n!=0){
                int x = n%10;
                sum += x*x;
                n/=10;
            }
            n = sum;
        }
        return n==1;
    }
};
