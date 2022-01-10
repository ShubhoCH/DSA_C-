//Time:  O(logM+logN);
//Space: O(1);
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();
        int r=0;
        for(int i = 0;i<row;i++) {
            r=i;
            if(matrix[i][column-1]>=target) {
                break;
            }
        }
        for(int i=0;i<column;i++){
            if(matrix[r][i]==target){
                return true;
            }
        }
        return false;
    }
};
