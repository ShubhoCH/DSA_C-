//Time:  O(N);
//Space: O(1);
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gass, costt;
        gass = costt = 0;
        for(int i=0;i<gas.size();i++){
            gass+=gas[i];
            costt+=cost[i];
        }
        if(costt>gass) return -1;
        int start = 0;
        gass = 0;
        for(int i = start;i<gas.size();i++){
            gass+=gas[i];
            gass -= cost[i];
            if(gass<0){
                gass = 0;
                start = i+1;
            }
        }
        return start;
    }
};
