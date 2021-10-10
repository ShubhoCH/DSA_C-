class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        vector<int>result;
        int top = 0, down = mat.size()-1, left = 0, right = mat[0].size() - 1;
        int direction = 0;
        while (top <= down && left <= right)
        {
            if(direction == 0){
                for(int i = left; i <= right; i++){
                    result.push_back(mat[top][i]);
                }
                top++;
            }
            else if(direction == 1){
                for(int i = top; i <= down; i++){
                    result.push_back(mat[i][right]);
                }
                right--;
            }
            else if(direction == 2){
                for(int i = right; i >= left; i--){
                    result.push_back(mat[down][i]);
                }
                down--;
            }
            else if(direction == 3){
                for(int i = down; i >= top; i--){
                    result.push_back(mat[i][left]);
                }
                left++;
            }
            direction = (direction+1)%4;
        } 
        return result;
    }
};
