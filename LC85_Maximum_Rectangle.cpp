//Time: O(N*M);
//Time: O(N);
class Data{
public:
    int index;
    int height;
    Data(int a, int b){
        index = a;
        height = b;
    }
};
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int answer = 0;
        vector<int> nums;
        int row = matrix.size(), col = matrix[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(i == 0)
                    nums.push_back((matrix[i][j] == '1')?1:0);
                else
                    nums[j] = (matrix[i][j] == '1')?(nums[j]+1):0;
            }
            answer = max(answer, LRA(nums));
        }
        return answer;
    }
    int LRA(vector<int>& h) {
        stack<Data>s;
        int ans = 0, lastpop = 0;
        Data temp(0,h[0]);
        s.push(temp);
        for(int i=1;i<h.size();i++){
            if(s.empty()){
                if(h[i] != 0){
                    Data x(i,h[i]);
                    s.push(x);
                }
                continue;
            }
            if(h[i] >= s.top().height){
                Data x(i,h[i]);
                s.push(x);
            }
            else{
                while(!s.empty() && s.top().height > h[i]){
                    int area = s.top().height * (i - s.top().index);
                    lastpop = s.top().index;
                    s.pop();
                    ans = max(ans, area);
                }
                if(h[i] != 0){
                    Data x(lastpop,h[i]);
                    s.push(x);
                }
            }
        }
        while(!s.empty()){
            int area = s.top().height * (h.size() - s.top().index);
            s.pop();
            ans = max(ans, area);
        }
        return ans;
    }
};
