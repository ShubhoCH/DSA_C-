//Time:  O(M*N);
//Space: O(M*N);
class Solution {
    unordered_map<string,bool> mem;
    bool check(string s1,string s2,string s3,int p1,int p2,int p3)
    {
        if(p3==s3.length())
            return (p1==s1.length() and p2==s2.length())?true:false;
        string key = to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(mem.find(key)!=mem.end())
            return mem[key];
        if(p1==s1.length())
            return mem[key] = s2[p2]==s3[p3]? check(s1,s2,s3,p1,p2+1,p3+1):false;
        if(p2==s2.length())
            return mem[key] = s1[p1]==s3[p3]? check(s1,s2,s3,p1+1,p2,p3+1):false;
        bool one = false,two = false;
        if(s1[p1]==s3[p3])
            one = check(s1,s2,s3,p1+1,p2,p3+1);
        if(s2[p2]==s3[p3])
            two = check(s1,s2,s3,p1,p2+1,p3+1);
        return mem[key] = one or two;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.length() != s1.length()+s2.length())
            return false;
        return check(s1,s2,s3,0,0,0);
    }
};

