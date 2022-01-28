//Time:  O(N^2);
//SPace: O(N^2);
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> map;
        for(auto x: A)
            for(auto y : B)
                map[x+y]++;
        int count = 0;
        for(auto x: C)
            for(auto y : D){
                if(map.find(-(x+y))!=map.end()){
                    count+=map[-(x+y)];
                }
            }
        return count;
    }
};
