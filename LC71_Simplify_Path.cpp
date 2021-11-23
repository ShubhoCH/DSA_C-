//Time:  O(N);
//Space: O(N);
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string s = "";
        for(int i = 0 ;i<path.length();i++){
            if(path[i]=='/'){
                if(s==".."){
                    if(!st.empty())
                        st.pop();
                    s = "";
                }
                if(s != "" && s != ".")
                    st.push(s);
                s = "";
            }
            else
                s+=path[i];
        }
        if(s!="" && s!="." && s != "..")
            st.push(s);
        else if(s == ".." && !st.empty())
            st.pop();
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
            s = '/' + s;
        }
        if(s == "")
            s = '/';
        return s;
    }
};
