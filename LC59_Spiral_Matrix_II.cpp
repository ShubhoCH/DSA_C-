//Time:  O(N^2);
//Space: O(1);
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans (n, vector<int>(n));
        int top = 0, down = n-1, left = 0, right = n-1;
        int direction = 0, count = 1;  
        while (top <= down && left <= right)
        {
            if(direction == 0){
                for(int i = left; i <= right; i++)
                    ans[top][i] = count++;
                top++;
            }
            else if(direction == 1){
                for(int i = top; i <= down; i++)
                    ans[i][right] = count++;
                right--;
            }
            else if(direction == 2){
                for(int i = right; i >= left; i--)
                    ans[down][i] = count++;
                down--;
            }
            else if(direction == 3){
                for(int i = down; i >= top; i--)
                    ans[i][left] = count++;
                left++;
            }
            direction = (direction+1)%4;
        } 
        return ans;
    }
};
