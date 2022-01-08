class Solution {
//Time:  O(M*N);
//Space: O(1);
public:
    void helper(vector<vector<char>>& board, int i, int j){
        if(board[i][j] == 'X') return;
        board[i][j] = '1';
        if(i+1 < board.size() && board[i+1][j] == 'O')
            helper(board,i+1,j);
        if(i-1>=0 && board[i-1][j] == 'O')
            helper(board,i-1,j);
        if(j+1 < board[0].size() && board[i][j+1] == 'O')
            helper(board,i,j+1);
        if(j-1>=0 && board[i][j-1] == 'O')
            helper(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            helper(board,i,0);
            helper(board,i,board[0].size()-1);
        }
        for(int i=0;i<board[0].size();i++){
            helper(board,0,i);
            helper(board,board.size()-1,i);
        }
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == '1')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
    }
};
