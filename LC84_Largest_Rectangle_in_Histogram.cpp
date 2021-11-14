//Time:  O(N);
//Space: O(N);
class D{
public:
    int index;
    int height;
    D(int a, int b){
        index = a;
        height = b;
    }
};
class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<D>s;
        int ans = 0, lastpop = 0;
        D temp(0,h[0]);
        s.push(temp);
        for(int i=1;i<h.size();i++){
            if(s.empty()){
                if(h[i] != 0){
                    D x(i,h[i]);
                    s.push(x);
                }
                continue;
            }
            if(h[i] >= s.top().height){
                D x(i,h[i]);
                s.push(x);
            }
            else{
                while(!s.empty() && s.top().height > h[i]){
                    int area = s.top().height * (i - s.top().index);
                    lastpop = s.top().index;
                    s.pop();
                    ans = max(ans, area);
                }
                if(h[i] != 0){
                    D x(lastpop,h[i]);
                    s.push(x);
                }
            }
        }
        while(!s.empty()){
            int area = s.top().height * (h.size() - s.top().index);
            s.pop();
            ans = max(ans, area);
        }
        return ans;
    }
};
