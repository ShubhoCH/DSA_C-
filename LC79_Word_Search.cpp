//Time:  O(N);
//Space: O(N); //N->Represents no. of Cells;
class Solution {
public:
    bool check(int i, int j, int row, int col, int index, vector<vector<char>>& board, string s, vector<vector<bool>>& visited){
        if(index == s.length() - 1)
            return true;
        visited[i][j] = true;
        if(i>0 && !visited[i-1][j] && board[i-1][j] == s[index+1] && check(i-1,j,row,col,index+1,board, s, visited)) 
            return true;
        if(j>0 && !visited[i][j-1] && board[i][j-1] == s[index+1] && check(i,j-1,row,col,index+1,board, s, visited)) 
            return true;
        if(i<row-1 && !visited[i+1][j] && board[i+1][j] == s[index+1] && check(i+1,j,row,col,index+1,board, s, visited))
            return true;
        if(j<col-1 && !visited[i][j+1] && board[i][j+1] == s[index+1] && check(i,j+1,row,col,index+1,board, s, visited)) 
            return true;
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited (row, vector<bool>(col, false));
                    bool found = check(i, j, row, col,0, board, word, visited);
                    if(found)
                        return true;
                }
            }
        return false;
    }
};
