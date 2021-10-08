class Solution {
public:
    void Find(int row, vector<vector<string>>& ans, vector<string> temp, int n, unordered_set<int> col, unordered_set<int> d1, unordered_set<int> d2){
        if(row == n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(col.find(i) == col.end() && d1.find(i + row) == d1.end() && d2.find(row - i) == d2.end()){
                col.insert(i);
                d1.insert(i + row);
                d2.insert(row - i);
                string s = "";
                for(int j=0;j<n;j++){
                    if(j!=i)
                        s+=".";
                    else
                        s+="Q";
                }
                temp.push_back(s);
                Find(row+1, ans, temp, n, col, d1, d2);
                col.erase(i);
                d1.erase(i + row);
                d2.erase(row - i);
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if(n==1){
            ans.push_back({"Q"});
            return ans;
        }
        if(n==2)
            return ans;
        unordered_set<int> col;
        unordered_set<int> d1;
        unordered_set<int> d2;
        vector<string> temp;
        Find(0,ans, temp,n,col,d1,d2);
        return ans;
        
    }
};
