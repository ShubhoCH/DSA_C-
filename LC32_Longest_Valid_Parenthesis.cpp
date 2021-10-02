class Solution {
public:
    // O(N):
    int longestValidParentheses(string s) {
        if(s=="")
            return 0;
        int count = 0;
        stack<char> st;
        stack<int> st2;
        st2.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i] == '('){
                st.push(s[i]);
                st2.push(i);
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                    st2.pop();
                    if(i-st2.top() > count)
                        count = i-st2.top();
                }
                else{
                    st.push(s[i]);
                    st2.push(i);
                }
            }
        }
        return count;
    }
};
