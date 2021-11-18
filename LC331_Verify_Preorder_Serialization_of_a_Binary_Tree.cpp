//Time:  O(N);
//Space: O(N);
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int size = preorder.length();
        queue<string> q;
        for(int i=0;i<size;i++){
            string s = "";
            while(i<size && preorder[i] != ',') s+=preorder[i++];
            q.push(s);
        }
        int n = 1;
        size = q.size();
        for(int i=0;i<size;i++){
            if(q.front() == "#")
                n--;
            else
                n++;
            q.pop();
            if(n==0 && i<size-1)
                return false;
        }
        if(n==0)
            return true;
        return false;
    }
};

