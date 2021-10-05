//Back-Tracking:
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> box(9, unordered_set<char>());
        vector<unordered_set<char>> col(9, unordered_set<char>());
        vector<unordered_set<char>> row(9, unordered_set<char>());
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){
                int num = board[i][j];
                if(num == '.')
                    continue;
                int b = ((i/3)*3 + j/3);
                row[i].insert(num);
                col[j].insert(num);
                box[b].insert(num);
            }
        solve(board, box, col, row);
    }
    bool solve(vector<vector<char>>& board, vector<unordered_set<char>> box, vector<unordered_set<char>> col, vector<unordered_set<char>> row){
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++){ 
                if(board[i][j] == '.'){  
                    int b = ((i/3)*3 + j/3);
                    for(char c='1'; c<='9'; c++){
                        if(!row[i].count(c) && !col[j].count(c) && !box[b].count(c)){
                            board[i][j] = c;
                            row[i].insert(c);
                            col[j].insert(c);
                            box[b].insert(c);
                            if(solve(board, box, col, row))
                                return true;
                            else{
                                row[i].erase(c);
                                col[j].erase(c);
                                box[b].erase(c);
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        return true;
    }
};
