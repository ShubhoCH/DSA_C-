//Time:  O(N);
//Space: O(N);
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> s;
        for(int i=0;i<ast.size();i++){
            if(s.empty())
                s.push(ast[i]);
            else{
                if(s.top()/abs(s.top()) == ast[i]/abs(ast[i]) || s.top() < 0)
                    s.push(ast[i]);
                else{
                    bool push = true;
                    while(!s.empty() && s.top()/abs(s.top()) != ast[i]/abs(ast[i])){
                        if(abs(s.top()) >= abs(ast[i])){
                            if(abs(s.top()) == abs(ast[i]))
                                s.pop();
                            push = false;
                            break;
                        }
                        s.pop();
                    }
                    if(push)
                        s.push(ast[i]);
                }
            }
        }
        vector<int> ans(s.size());
        while(!s.empty()){
            ans[s.size()-1] = s.top();
            s.pop();
        }
        return ans;
    }
};
