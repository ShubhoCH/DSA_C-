// Time- O(N)
//Space - O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix[0].size();i++){
            for(int j=i;j<matrix[0].size();j++){
                if(i==j)continue;
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
        for(int i=0;i<matrix[0].size();i++){
            for(int j=0;j<matrix[0].size()/2;j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][matrix.size()-1-j];
                matrix[i][matrix.size()-1-j] = temp;
            }
        }
    }
};
