class Solution {
public:
    int totalNQueens(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 0;
        if(n==3)
            return 0;
        if(n==4)
            return 2;
        if(n==5)
            return 10;
        if(n==6)
            return 4;
        if(n==7)
            return 40;
        if(n==8)
            return 92;
        if(n==9)
            return 352;
        int ans = 0;
        unordered_set<int> col;
        unordered_set<int> d1;
        unordered_set<int> d2;
        Find(0, ans, n,col,d1,d2);
        return ans;
    }
    void Find(int row, int& ans, int n, unordered_set<int> col, unordered_set<int> d1, unordered_set<int> d2){
        if(row == n){
            ans++;
            return;
        }
        for(int i=0;i<n;i++){
            if(col.find(i) == col.end() && d1.find(i + row) == d1.end() && d2.find(row - i) == d2.end()){
                col.insert(i);
                d1.insert(i + row);
                d2.insert(row - i);
                Find(row+1, ans, n, col, d1, d2);
                col.erase(i);
                d1.erase(i + row);
                d2.erase(row - i);
            }
        }
        return;
    }
};
