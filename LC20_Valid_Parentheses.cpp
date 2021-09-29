class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for(char x: s){
            if(x=='(' || x== '[' || x == '{')
                st.push(x);
            else{
                if(st.empty())
                    return false;
                switch(x){   
                    case ')':
                        if(st.top()!='(')
                            return false;
                        st.pop();
                        break;
                    case ']':
                        if(st.top()!='[')
                            return false;
                        st.pop();
                        break;
                    case '}':
                        if(st.top()!='{')
                            return false;
                        st.pop();
                        break;
                }
            }
        }
        if(st.empty())
            return true;
        return false;
    }
};
