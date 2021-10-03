// O(N^2)
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> box(9, unordered_set<char>());
        vector<unordered_set<char>> col(9, unordered_set<char>());
        vector<unordered_set<char>> row(9, unordered_set<char>());
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                int num = board[i][j];
                if(num == '.')
                    continue;
                if(row[i].count(num))
                    return false;
                if(col[j].count(num))
                    return false;
                int b = ((i/3)*3 + j/3);
                if(box[b].count(num))
                    return false;
                row[i].insert(num);
                col[j].insert(num);
                box[b].insert(num);
            }
        return true;
    }
};
