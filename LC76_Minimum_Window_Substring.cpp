//Time:  O(N + M);
//Space: O(N);
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        unordered_map<char,int> mp;
        for(int i=0;i<t.size();++i){
            mp[t[i]]++;
        }
        int count=mp.size();
        string ans;
        int mn=INT_MAX;
        int i=0,j=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
            while(count==0){
                if(j-i+1<mn){
                    mn=j-i+1;
                    ans=s.substr(i,j-i+1);
                }
                if(mp.find(s[i])!=mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]]==1){
                        count++;
                    }
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
